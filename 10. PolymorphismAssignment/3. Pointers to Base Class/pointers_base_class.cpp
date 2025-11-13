#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base class
class Shape {
protected:
    string color;
    int x, y;  // Position coordinates
    
public:
    Shape(string c = "White", int posX = 0, int posY = 0) 
        : color(c), x(posX), y(posY) {}
    
    // Pure virtual function
    virtual void draw() = 0;
    
    virtual double area() = 0;
    
    virtual void displayInfo() {
        cout << "Color: " << color << endl;
        cout << "Position: (" << x << ", " << y << ")" << endl;
    }
    
    virtual ~Shape() {
        cout << "Shape destructor called\n";
    }
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r, string c = "Red", int posX = 0, int posY = 0) 
        : Shape(c, posX, posY), radius(r) {}
    
    void draw() override {
        cout << "\nDrawing a Circle\n";
        cout << "Radius: " << radius << endl;
    }
    
    double area() override {
        return 3.14159 * radius * radius;
    }
    
    void displayInfo() override {
        cout << "=== Circle ===\n";
        Shape::displayInfo();
        cout << "Radius: " << radius << endl;
        cout << "Area: " << area() << endl;
    }
    
    ~Circle() {
        cout << "Circle destructor called\n";
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double length, width;
    
public:
    Rectangle(double l, double w, string c = "Blue", int posX = 0, int posY = 0) 
        : Shape(c, posX, posY), length(l), width(w) {}
    
    void draw() override {
        cout << "\nDrawing a Rectangle\n";
        cout << "Length: " << length << ", Width: " << width << endl;
    }
    
    double area() override {
        return length * width;
    }
    
    void displayInfo() override {
        cout << "=== Rectangle ===\n";
        Shape::displayInfo();
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Area: " << area() << endl;
    }
    
    ~Rectangle() {
        cout << "Rectangle destructor called\n";
    }
};

// Derived class: Triangle
class Triangle : public Shape {
private:
    double base, height;
    
public:
    Triangle(double b, double h, string c = "Green", int posX = 0, int posY = 0) 
        : Shape(c, posX, posY), base(b), height(h) {}
    
    void draw() override {
        cout << "\nDrawing a Triangle\n";
        cout << "Base: " << base << ", Height: " << height << endl;
    }
    
    double area() override {
        return 0.5 * base * height;
    }
    
    void displayInfo() override {
        cout << "=== Triangle ===\n";
        Shape::displayInfo();
        cout << "Base: " << base << endl;
        cout << "Height: " << height << endl;
        cout << "Area: " << area() << endl;
    }
    
    ~Triangle() {
        cout << "Triangle destructor called\n";
    }
};

// Derived class: Square
class Square : public Shape {
private:
    double side;
    
public:
    Square(double s, string c = "Yellow", int posX = 0, int posY = 0) 
        : Shape(c, posX, posY), side(s) {}
    
    void draw() override {
        cout << "\nDrawing a Square\n";
        cout << "Side: " << side << endl;
    }
    
    double area() override {
        return side * side;
    }
    
    void displayInfo() override {
        cout << "=== Square ===\n";
        Shape::displayInfo();
        cout << "Side: " << side << endl;
        cout << "Area: " << area() << endl;
    }
    
    ~Square() {
        cout << "Square destructor called\n";
    }
};

int main() {
    cout << "========================================\n";
    cout << "  Pointers to Base Class Example\n";
    cout << "  Demonstrating Runtime Polymorphism\n";
    cout << "========================================\n\n";
    
    // Create base class pointers array
    Shape* shapes[4];
    
    // Pointing to different derived class objects
    shapes[0] = new Circle(5.0, "Red", 10, 20);
    shapes[1] = new Rectangle(10.0, 6.0, "Blue", 30, 40);
    shapes[2] = new Triangle(8.0, 4.0, "Green", 50, 60);
    shapes[3] = new Square(7.0, "Yellow", 70, 80);
    
    cout << "--- Demonstrating Polymorphism ---\n";
    cout << "Using base class pointers to call virtual functions\n\n";
    
    // Using base class pointers to access derived class methods
    for (int i = 0; i < 4; i++) {
        cout << "\n--- Shape " << (i + 1) << " ---\n";
        shapes[i]->draw();
        shapes[i]->displayInfo();
        cout << endl;
    }
    
    // Calculate total area
    cout << "\n--- Area Calculations ---\n";
    double totalArea = 0;
    for (int i = 0; i < 4; i++) {
        double shapeArea = shapes[i]->area();
        totalArea += shapeArea;
        cout << "Shape " << (i + 1) << " area: " << shapeArea << endl;
    }
    cout << "Total area of all shapes: " << totalArea << endl;
    
    // Example with vector of base class pointers
    cout << "\n\n--- Using Vector of Base Class Pointers ---\n";
    vector<Shape*> shapeVector;
    
    shapeVector.push_back(new Circle(3.0, "Pink", 5, 5));
    shapeVector.push_back(new Square(4.0, "Orange", 15, 15));
    
    for (size_t i = 0; i < shapeVector.size(); i++) {
        cout << "\nVector element " << (i + 1) << ":\n";
        shapeVector[i]->draw();
        cout << "Area: " << shapeVector[i]->area() << endl;
    }
    
    // Cleanup - demonstrate virtual destructor
    cout << "\n\n--- Cleanup (Virtual Destructor Demo) ---\n";
    for (int i = 0; i < 4; i++) {
        delete shapes[i];
    }
    
    for (size_t i = 0; i < shapeVector.size(); i++) {
        delete shapeVector[i];
    }
    
    cout << "\n========================================\n";
    cout << "Key Concepts Demonstrated:\n";
    cout << "1. Base class pointer pointing to derived objects\n";
    cout << "2. Virtual functions for runtime polymorphism\n";
    cout << "3. Virtual destructor for proper cleanup\n";
    cout << "4. Pure virtual functions (abstract class)\n";
    cout << "========================================\n";
    
    return 0;
}
