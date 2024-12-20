#include <iostream>
using namespace std;

int main() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid size. Please enter a positive integer." << endl;
        return 1;
    }

    int arr[size];
    cout << "Enter " << size << " elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    if (size > 3) {
        cout << "Element at index 3 is: " << arr[3] << endl;
    } else {
        cout << "Index 3 does not exist in the array (size is too small)." << endl;
    }

    return 0;
}
