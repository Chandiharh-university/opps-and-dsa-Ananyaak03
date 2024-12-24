#include <iostream>
#define MAX 1000 
class Stack {
private:
    int top;
    int arr[MAX]; 
public:
    
    Stack() {
        top = -1;
    }

  
    bool push(int value) {
        if (top >= MAX - 1) {
            std::cout << "Stack Overflow\n";
            return false;
        }
        arr[++top] = value;
        std::cout << value << " pushed onto stack\n";
        return true;
    }

    int pop() {
        if (top < 0) {
            std::cout << "Stack Underflow\n";
            return -1; 
        }
        return arr[top--];
    }

    int peek() {
        if (top < 0) {
            std::cout << "Stack is empty\n";
            return -1; 
        }
        return arr[top];
    }
    bool isEmpty() {
        return (top < 0);
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element is " << stack.peek() << "\n";

    std::cout << "Popped " << stack.pop() << " from the stack\n";
    std::cout << "Top element is now " << stack.peek() << "\n";

    return 0;
}
