#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() { 
        cout << "Drawing a generic shape." << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override { // Overriding the base class method
        cout << "Drawing a circle." << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override { // Overriding the base class method
        cout << "Drawing a rectangle." << endl;
    }
};

int main() {
    Shape* shapePtr;      
    Circle circleObj;    
    Rectangle rectangleObj; 

    shapePtr = &circleObj; 
    shapePtr->draw();      /

    shapePtr = &rectangleObj; 
    shapePtr->draw();         

    return 0;
}
