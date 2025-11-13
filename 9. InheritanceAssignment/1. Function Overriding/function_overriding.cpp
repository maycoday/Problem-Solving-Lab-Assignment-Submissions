#include <iostream>
#include <string>
using namespace std;

// Base class
class Shape {
protected:
    string name;
    
public:
    Shape(string n) : name(n) {}
    
    // Virtual function to be overridden
    virtual void draw() {
        cout << "Drawing a generic shape: " << name << endl;
    }
    
    virtual double area() {
        cout << "Area calculation not defined for generic shape" << endl;
        return 0.0;
    }
    
    virtual void display() {
        cout << "Shape: " << name << endl;
    }
    
    virtual ~Shape() {}
};

// Derived class 1: Circle
class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : Shape("Circle"), radius(r) {}
    
    // Override draw() function
    void draw() override {
        cout << "Drawing a Circle with radius: " << radius << endl;
    }
    
    // Override area() function
    double area() override {
        return 3.14159 * radius * radius;
    }
    
    // Override display() function
    void display() override {
        cout << "=== Circle Details ===" << endl;
        cout << "Shape: " << name << endl;
        cout << "Radius: " << radius << endl;
        cout << "Area: " << area() << endl;
    }
};

// Derived class 2: Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;
    
public:
    Rectangle(double l, double w) : Shape("Rectangle"), length(l), width(w) {}
    
    // Override draw() function
    void draw() override {
        cout << "Drawing a Rectangle with length: " << length << " and width: " << width << endl;
    }
    
    // Override area() function
    double area() override {
        return length * width;
    }
    
    // Override display() function
    void display() override {
        cout << "=== Rectangle Details ===" << endl;
        cout << "Shape: " << name << endl;
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Area: " << area() << endl;
    }
};

// Derived class 3: Triangle
class Triangle : public Shape {
private:
    double base;
    double height;
    
public:
    Triangle(double b, double h) : Shape("Triangle"), base(b), height(h) {}
    
    // Override draw() function
    void draw() override {
        cout << "Drawing a Triangle with base: " << base << " and height: " << height << endl;
    }
    
    // Override area() function
    double area() override {
        return 0.5 * base * height;
    }
    
    // Override display() function
    void display() override {
        cout << "=== Triangle Details ===" << endl;
        cout << "Shape: " << name << endl;
        cout << "Base: " << base << endl;
        cout << "Height: " << height << endl;
        cout << "Area: " << area() << endl;
    }
};

int main() {
    cout << "===== Function Overriding using Inheritance =====\n\n";
    
    // Create objects
    Circle circle(5.0);
    Rectangle rectangle(10.0, 6.0);
    Triangle triangle(8.0, 4.0);
    
    // Using overridden functions directly
    cout << "--- Direct Function Calls ---\n";
    circle.draw();
    circle.display();
    cout << endl;
    
    rectangle.draw();
    rectangle.display();
    cout << endl;
    
    triangle.draw();
    triangle.display();
    cout << endl;
    
    // Using base class pointers (Runtime Polymorphism)
    cout << "\n--- Using Base Class Pointers (Polymorphism) ---\n";
    Shape* shapes[3];
    shapes[0] = &circle;
    shapes[1] = &rectangle;
    shapes[2] = &triangle;
    
    for (int i = 0; i < 3; i++) {
        shapes[i]->draw();
        shapes[i]->display();
        cout << endl;
    }
    
    return 0;
}
