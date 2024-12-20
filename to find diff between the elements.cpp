#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    int arr[SIZE];
    int differences[SIZE - 1]; 
    cout << "Enter 10 elements for the array:" << endl;
    for (int i = 0; i < SIZE; i++) {
        if (i == 3) {
            arr[i] = -999; // Represent null with -999
            cout << "Element at index 3 is set to null (-999)." << endl;
        } else {
            cin >> arr[i];
        }
    }

    cout << "Calculating differences (ignoring index 3):" << endl;
    for (int i = 0; i < SIZE - 1; i++) {
        if (i == 2 || i == 3) { // Skip index 2 and 3
            differences[i] = -999; // Represent skipped difference as -999
        } else {
            differences[i] = arr[i + 1] - arr[i];
        }
    }

    cout << "\nArray elements (with null at index 3):" << endl;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == -999)
            cout << "null ";
        else
            cout << arr[i] << " ";
    }
    cout << endl;

    cout << "\nDifferences between consecutive elements:" << endl;
    for (int i = 0; i < SIZE - 1; i++) {
        if (differences[i] == -999)
            cout << "null ";
        else
            cout << differences[i] << " ";
    }
    cout << endl;

    return 0;
}
