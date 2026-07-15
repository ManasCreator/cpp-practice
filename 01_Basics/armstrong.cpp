#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int num;int orig;int temp;int count=0;int digit;int sum=0;

    cout<<"Enter the Number"<<endl;
    cin>>num;
    orig=num;
    temp=num;
    while(num>0){
        digit=num%10;
        count++;
        num=num/10;

    }
    cout<<"Digit Count = "<<count<<endl;
     while(orig>0){
        digit=orig%10;
        sum=sum + pow(digit,count);
        orig=orig/10;

    }
    cout<<"Sum of Number = "<<sum<<endl;

    if(sum==temp){
        cout<<"Armstrong Number";
    }
    else
    cout<<"Not an Armstrong"<<endl;

    return 0;
}