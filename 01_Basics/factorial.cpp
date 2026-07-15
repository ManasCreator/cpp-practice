#include <iostream>
using namespace std;
int fact(int n){
if(n==0 || n==1)
return 1;
else
return n*fact(n-1);
}

int main() {
    cout<<"Enter a positive integer: ";
    int n; int result;
    cin>>n;
    result=fact(n);
    cout<<result;
    return 0;
}