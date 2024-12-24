#include <iostream>
using namespace std;

class Queue {
private:
    int size;
    int front;
    int rear;
    int* items;

public:
    Queue(int s) {
        size = s;
        front = -1;
        rear = -1;
        items = new int[size];
    }

    ~Queue() {
        delete[] items;
    }

    bool isFull() {
        return (rear == size - 1);
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        items[++rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued: " << items[front++] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }

    int getFront() {
        return isEmpty() ? -1 : items[front];
    }

    int getRear() {
        return isEmpty() ? -1 : items[rear];
    }
};

int main() {
    int size = 5; 
    Queue q(size);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Front value: " << q.getFront() << endl;
    cout << "Rear value: " << q.getRear() << endl;

    q.dequeue();
    q.display();

    return 0;
}
