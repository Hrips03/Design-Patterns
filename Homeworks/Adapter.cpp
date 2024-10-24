#include <iostream>
using namespace std;

class Shape {
public:
    virtual double getAreaInInches() = 0;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    
    double getAreaInInches() override {
        return 3.14159 * radius * radius; 
    }
};

class AreaCalculatorInCM {
public:
    virtual double getAreaInCM() = 0;
};


class AreaAdapter : public AreaCalculatorInCM {
    Shape* shape;
public:
    AreaAdapter(Shape* s) : shape(s) {}
    
    double getAreaInCM() override {
        double areaInInches = shape->getAreaInInches();
        return areaInInches * 6.4516; 
    }
};


int main() {
    Circle circleInInches(5); 
    AreaAdapter adapter(&circleInInches);

    cout << "Area in square centimeters: " << adapter.getAreaInCM() << endl;
    
    return 0;
}
