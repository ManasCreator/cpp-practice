#include <iostream>
using namespace std;

int dualEndedSearch(int A[], int low, int high, int key) {

    if (low > high)
        return -1;

    if (A[low] == key)
        return low;

    if (A[high] == key)
        return high;

    return dualEndedSearch(A, low + 1, high - 1, key); // RECURSIVE APPROACH
}

int main() {
    int n, key;
    int A[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int pos = dualEndedSearch(A, 0, n - 1, key);

    if (pos != -1)
        cout << "Element found at index " << pos;
    else
        cout << "Element not found";

    return 0;
}