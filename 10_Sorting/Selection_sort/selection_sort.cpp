#include <iostream>
using namespace std;

int main() {
    int arr[]={5,1,3,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n-1;i++){ //NO OF PASSES
        int min=INT_MAX;
        int min_Index=-1;
        
        //now inner j will start from i
        for(int j=i;j<=n-1;j++){ //check until last index
           if(min>arr[j]){
            min=arr[j]; // store minimum
            min_Index=j; // store index
           }
        }
        swap(arr[i],arr[min_Index]); //for i'th round,we got its minimum value
    }

    for(int i=0;i<=n-1;i++){ //DISPLAY
        cout<<arr[i]<<" ";
    }
    return 0;
}