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

    int pos = -1;

    //MAIN LOGIC BELOW

    for (int i = 0; i < n; i++) {
        if (A[i] == key) {
            pos = i;
            break;
        }
    }

    if (pos != -1){
        cout << "Element found at index " << pos<<endl;
        cout << "Element found at position " << pos + 1<<endl;
    }
    else{
        cout << "Element not found";
    }
    return 0;
}