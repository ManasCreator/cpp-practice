//Implement recursive binary search for a sorted array where an element may occur multiple times.
//Print all the indices where the key is found.
#include <iostream>
using namespace std;
void binarysearch(int arr[],int low,int high,int key){

    if(low>high){ // Base condition: search range is exhausted
        return;
    }
    int mid=(low+high)/2;
    if(key==arr[mid]){
     // Search the left half for earlier occurrences
       binarysearch(arr, low, mid - 1, key);
     // Print the current matching index
       cout << "Index = " << mid << endl;
     // Search the right half for later occurrences
       binarysearch(arr, mid + 1, high, key);
        
    }
    if(key<arr[mid]){
        binarysearch(arr,low,mid-1,key);  // If key is smaller, search the left half
    }
    if(key>arr[mid]){
        binarysearch(arr,mid+1,high,key); // If key is greater, search the right half
    }
    

}

int main() {
    int arr[]={1,2,3,4,4,4,4,6};
    int n=sizeof(arr)/4;
    cout<<"Enter the number you want to find indices of: ";
    int key;
    cin>>key;
    int low=0;
    int high=n-1;
    binarysearch(arr,low,high,key);
    return 0;
}