#include <iostream>
using namespace std;

int main() {
    int arr[]={5,1,3,2,4,-1,6};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n-1;i++){ //NO. OF PASSES/ROUNDS, IF SIZE=5 -> 4 PASSES

        for(int j=0;j<n-1;j++){ // TRAVERSING AND SWAPPING,LAST INDEX NOT SWAP
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]); //BUILT IN SWAP
            }
        }
    }

    for(int i=0;i<=n-1;i++){ //DISPLAY
        cout<<arr[i]<<" ";
    }
    return 0;
}