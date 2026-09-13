#include <iostream>
using namespace std;

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

    int low = 0;
    int high = n - 1;
    int pos = -1;

    while (low <= high) {

        if (A[low] == key) {
            pos = low;
            break;
        }
        low++;

        if (A[high] == key) {
            pos = high;
            break;
        }
        high--;
    }

    if (pos != -1)
        cout << "Element found at index " << pos;
    else
        cout << "Element not found";

    return 0;
}