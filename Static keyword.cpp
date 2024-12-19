#include <iostream>
using namespace std;

class NumberHandler {
public:
    static int sum; // Static variable to hold the cumulative sum

    void addNumber(int num) {
        sum += num; // Add the input number to the cumulative sum
    }

    void displaySum() {
        cout << "Current Sum: " << sum << endl;
    }

    void displayReference() {
        cout << "Memory Reference of Sum: " << &sum << endl;
    }
};

// Initialize the static variable
int NumberHandler::sum = 0;

int main() {
    NumberHandler handler;
    int num;
    char choice;

    cout << "Static Keyword Demonstration\n";
    do {
        cout << "Enter a number: ";
        cin >> num;
        handler.addNumber(num);

        handler.displaySum();
        handler.displayReference();

        cout << "Do you want to add another number? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Final Sum: " << NumberHandler::sum << endl;
    cout << "Memory Reference of Sum: " << &NumberHandler::sum << endl;

    return 0;
}
