#include <iostream>
using namespace std;

int main(){
    int n;
    int digit;
    int rev=0;
    cout<<"Enter a number";
    cin>>n;
    while(n>0){
       digit= n%10;
       rev=rev*10+digit;
       n=n/10;

    }
    cout<<rev;

    return 0;
}