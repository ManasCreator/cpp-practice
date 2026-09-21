#include <iostream>
using namespace std;

// Function for insertion sort
void insertionSort(int arr[], int n) {

    // Number of passes
    for (int i = 0; i < n - 1; i++) { // if total 5 elements , passes=4

        // Start from the next element
        int j = i + 1;

        // Compare with previous elements
        while (j >= 1 && arr[j] < arr[j - 1]) {

            // Swap if current element is smaller
            swap(arr[j], arr[j - 1]);

            // Move towards left
            j--;
        }
    }
}

int main() {
    int arr[] = {5, 10, 1, 4, 3, 20};
    int n = 6;

    // Function calling
    insertionSort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}