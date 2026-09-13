
//Lower bound = first position where the element is greater than or equal to the key.
#include <iostream>
using namespace std;

int lowerBound(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    int pos = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= key) {  //Greater or equal sign
            pos = mid; //save
            high = mid - 1; //check left 
        }
        else {
            low = mid + 1;
        }
    }

    return pos;
}

int main() {
    int arr[] = {2, 4, 4, 6, 8, 10};
    int n = 6;
    int key = 5;

    cout << lowerBound(arr, n, key);

    return 0;
}