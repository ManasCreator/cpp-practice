//Modify bubble sort to sort elements in descending order.
//After sorting, print the k-th largest element (where k is entered by the user).

#include <iostream>
using namespace std;

int main() {
    int arr[]={5,1,3,2,4,-1,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Enter k";
    int k;
    cin>>k;

    for(int i=0;i<n-1;i++){ 

        for(int j=0;j<n-1;j++){ 
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]); 
            }
        }
    }
    cout<<k<<" th largest number = "<<arr[k-1];
    return 0;
}