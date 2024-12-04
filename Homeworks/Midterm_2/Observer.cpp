#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Forward declaration
template <typename T>
class Observer;

// Observable
template <typename T>
class Observable
{
    std::vector<Observer<T> *> subs;

public:
    void subscribe(Observer<T> *sub) { subs.push_back(sub); }
    void unsubscribe(Observer<T> *sub)
    {
        auto it = std::find(subs.begin(), subs.end(), sub);
        if (it != subs.end())
            subs.erase(it);
    }
    void notify(T &source, std::string fieldName, std::string newValue)
    {
        for (auto sub : subs)
        {
            sub->fieldChanged(source, fieldName, newValue);
        }
    }
};

// Publisher - Concrete Observable
class YouTuber : public Observable<YouTuber>
{
    int numOfVideos;
    std::string channelName = "";

public:
    YouTuber(int number, std::string name) : numOfVideos(number), channelName(name) {}
    int get_num() const { return numOfVideos; }
    std::string get_name() const { return channelName; }
    void set_num(int num)
    {
        if (this->numOfVideos == num)
            return;
        numOfVideos = num;
        notify(*this, "Videos", std::to_string(num));
    }
    void set_name(std::string name)
    {
        if (this->channelName == name)
            return;
        channelName = name;
        notify(*this, "Name", name);
    }
};

// Observer
template <typename T>
class Observer
{
public:
    virtual void fieldChanged(T &source, std::string fieldName, std::string newValue) = 0;
};

// Concrete observer
class Subscriber : public Observer<YouTuber>
{
public:
    void fieldChanged(YouTuber &yout, std::string fieldName, std::string newValue) override
    {
        if (fieldName == "Videos")
            std::cout << "Number of the videos was changed to " << yout.get_num() << ".\n";
        else if (fieldName == "Name")
            std::cout << "Name of the channel was changed to " << yout.get_name() << ".\n";
    }
};

int main()
{
    YouTuber bloger(10, "Bloger_1");
    Subscriber sub1;
    bloger.subscribe(&sub1);
    bloger.set_num(11);
    std::cout <<std::endl;

    Subscriber sub2;
    bloger.subscribe(&sub2);
    bloger.set_name("New_Bloger_1");
    std::cout <<std::endl;

    bloger.unsubscribe(&sub1);
    bloger.set_num(12);

    return 0;
}
