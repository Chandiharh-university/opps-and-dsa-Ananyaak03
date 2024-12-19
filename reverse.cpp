#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {
        cout << "This is the Base class." << endl;
    }
};

class Derived : public Base {
public:
    void display() override { // Function overriding
        cout << "This is the Derived class." << endl;
    }
};

int main() {
    Base* basePtr;
    Derived derivedObj;

    basePtr = &derivedObj; // Base class pointer pointing to Derived class object
    basePtr->display();    // Calls the overridden function in the Derived class

    return 0;
}
