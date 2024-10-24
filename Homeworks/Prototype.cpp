#include <iostream>
#include <memory>
#include <unordered_map>


class Shape {
public:
    virtual ~Shape() = default;
    virtual std::shared_ptr<Shape> clone() const = 0;
    virtual void draw() const = 0;
};


class Circle : public Shape {
    int radius;
public:
    Circle(int r) : radius(r) {}

    std::shared_ptr<Shape> clone() const override {
        return std::make_shared<Circle>(*this);
    }

    void draw() const override {
        std::cout << "Drawing a Circle with radius: " << radius << std::endl;
    }
};


class Rectangle : public Shape {
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}

    std::shared_ptr<Shape> clone() const override {
        return std::make_shared<Rectangle>(*this);
    }

    void draw() const override {
        std::cout << "Drawing a Rectangle with width: " << width << " and height: " << height << std::endl;
    }
};


class ShapeFactory {
    std::unordered_map<std::string, std::shared_ptr<Shape>> prototypes;
public:
    void addPrototype(const std::string& shapeName, std::shared_ptr<Shape> shapePrototype) {
        prototypes[shapeName] = shapePrototype;
    }

    std::shared_ptr<Shape> createShape(const std::string& shapeName) const {
        if (prototypes.find(shapeName) != prototypes.end()) {
            return prototypes.at(shapeName)->clone();
        }
        return nullptr;
    }
};

int main() {
    ShapeFactory factory;

    factory.addPrototype("circle", std::make_shared<Circle>(10));    
    factory.addPrototype("rectangle", std::make_shared<Rectangle>(20, 30)); 

    std::shared_ptr<Shape> shape1 = factory.createShape("circle");
    shape1->draw();

    std::shared_ptr<Shape> shape2 = factory.createShape("rectangle");
    shape2->draw(); 
    return 0;
}
