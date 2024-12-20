#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; 
        
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }

        cout << "Step after selection sort pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];  
        int j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than key, to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;

        cout << "Step after insertion sort pass " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;

    
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

  
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

   
    cout << "\nSelection Sort Steps:\n";
    selectionSort(arr, n);

    
    cout << "\nRe-enter the array to perform Insertion Sort:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nInsertion Sort Steps:\n";
    insertionSort(arr, n);

    return 0;
}
