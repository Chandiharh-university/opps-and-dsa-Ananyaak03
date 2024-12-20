#include <iostream>
using namespace std;


void bubbleSort(int arr[], int n) {
    
    
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // Flag to check if a swap occurs in this pass
        
       
        for (int j = 0; j < n - i - 1; j++) {
            
            if (arr[j] > arr[j + 1]) {
            
                swap(arr[j], arr[j + 1]);
                swapped = true;

                
                cout << "Step after swap " << j + 1 << ": ";
                for (int k = 0; k < n; k++) {
                    cout << arr[k] << " ";
                }
                cout << endl;
            }
        }

        if (!swapped) {
            break;
        }
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

    
    cout << "Bubble Sort Steps:" << endl;
    bubbleSort(arr, n);

   
    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
