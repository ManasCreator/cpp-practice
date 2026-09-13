#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            ans = mid;  // store current index as answer
            high = mid - 1;  // search for an earlier occurrence
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return ans; // return the index
}

int main() {
    int arr[] = {4, 4, 4, 4, 6, 6, 10};
    int n = 7;
    int key = 4;

    cout << firstOccurrence(arr, n, key);

    return 0;
}