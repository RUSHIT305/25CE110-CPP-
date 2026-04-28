#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

// Base Class: Shape
class Shape {
public:
    // Pure virtual function makes this an abstract base class
    virtual double area() const = 0;
    // Virtual destructor is crucial for polymorphism
    virtual ~Shape() {}
};

// Derived Class: Rectangle
class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override { return length * width; }
};

// Derived Class: Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return M_PI * radius * radius; }
};

int main() {
    // --- 1. Dynamic Storage Approach (Flexible) ---
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Rectangle>(5.0, 4.0));
    shapes.push_back(std::make_unique<Circle>(3.0));

    std::cout << "Dynamic Area Calculation:\n";
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->area() << std::endl;
    }

    // --- 2. Static Storage Approach (Fixed size) ---
    Shape* staticShapes[2];
    Rectangle r(10.0, 2.0);
    Circle c(5.0);
    staticShapes[0] = &r;
    staticShapes[1] = &c;

    std::cout << "\nStatic Area Calculation:\n";
    for (int i = 0; i < 2; ++i) {
        std::cout << "Area: " << staticShapes[i]->area() << std::endl;
    }

    return 0;
}
