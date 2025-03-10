#include <iostream>

class Building    //Component
{ 
public:
    virtual void build() = 0;
};

class Flat : public Building  //Concrete Component 1
{
public:
    void build() override
    {
        std::cout << "Building a flat.\n";
    }
};

class House : public Building  //Concrete Component 2
{
public:
    void build() override
    {
        std::cout << "Building a house.\n";
    }
};

class Decorator : public Building  //Base Decorator
{
    Building *m_building;

public:
    Decorator(Building *building) : m_building(building) {}
    void build() override
    {
        m_building->build();
    }
};

class WallColorDecortaor : public Decorator //Concrete Decorator 1
{
    std::string m_color;

public:
    WallColorDecortaor(Building *m_building, std::string m_color) : Decorator(m_building), m_color(m_color) {}
    void build() override
    {
        Decorator::build();
        std::cout << "Adding wall color " << m_color << std::endl;
    }
};

class WindowDecortaor : public Decorator    //Concrete Decorator 2
{
    std::string m_glassColor;

public:
    WindowDecortaor(Building *m_building, std::string m_glassColor) : Decorator(m_building), m_glassColor(m_glassColor) {}
    void build() override
    {
        Decorator::build();
        std::cout << "Adding window's glass color " << m_glassColor << std::endl;
    }
};

int main()
{
    Building *flat_withColoredWindows = new WindowDecortaor(new WallColorDecortaor(new Flat(), "white"), "blue");
    Building *house_withColoredWindows = new WindowDecortaor(new WallColorDecortaor(new House(), "beige"), "brown");

    flat_withColoredWindows->build();
    house_withColoredWindows->build();
}