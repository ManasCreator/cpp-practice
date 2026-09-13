#include <iostream>
using namespace std;

int main() {
    int arr[]={3,4,5,1,2};
    int n=sizeof(arr)/4;
    
    for(int i=0;i<n-1;i++){
    bool flag=false; 
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=true;
            }
        }
        if(flag==false){ // means no swap is done in that round,->sorted
            break;
        }

    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}