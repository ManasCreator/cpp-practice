#include <iostream>
using namespace std;

int main() {
    int n,original,digit,rev=0;
    cout<<"Enter Number"<<endl;
    cin>>n;
    original=n;
    while(n>0){
    digit=n%10;
    rev=rev*10+digit;
    n=n/10;
    }
    if(original==rev){
        cout<<"It's a palindrome";
    
    }
    else{
        cout<<"Not a Palindrome";
    }


    return 0;
}
