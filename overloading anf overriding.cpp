#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {
        cout << "Display function in Base class" << endl;
    }

    void display(int num) {
        cout << "Display function with integer: " << num << endl;
    }

    void display(string text) {
        cout << "Display function with string: " << text << endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        cout << "Display function in Derived class" << endl;
    }
};

int main() {
    
    Base baseObj;
    baseObj.display();
    baseObj.display(42);
    baseObj.display("Hello, C++");

    cout << "-----------------------" << endl;

    
    Base* basePtr; 
    Derived derivedObj;
    basePtr = &derivedObj;

    basePtr->display(); 

    return 0;
}
