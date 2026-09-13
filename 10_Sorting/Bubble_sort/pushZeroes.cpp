//PUSH ZEROES TO END KEEPING ORDER SAME USING BUBBLE SORT
#include <iostream>
using namespace std;

int main() {
    int arr[]={5,0,2,0,0,3,4,0,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=1;i<=n-1;i++){ 

        for(int j=0;j<n-1;j++){ 
            if(arr[j]==0){ // WHEN ZERO KINDLY SWAP
                swap(arr[j],arr[j+1]); 
            }
        }
    }
    // NOW ALL 0s HAVE BEEN SHIFTED AFTER N-1 ROUNDS
    for(int i=0;i<=n-1;i++){ 
        cout<<arr[i]<<" ";
    }
    return 0;
}