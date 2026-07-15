#include <iostream>
using namespace std;
int min(int n1,int n2){
    if(n1>n2)
    return n2;
    else
    return n1;
}
int gcd(int n1,int n2){
    int final,m;
    m=min(n1,n2);
    for(int i=m;i>0;i--){
        if (n1%i==0 && n2%i==0){
        final=i;
        break;}
    }
    return final;
    
}
int main() {
    cout<<"Enter 2 numbers : ";
    int n1,n2,result;
    cin>>n1>>n2;
    result=gcd(n1,n2);
    cout<<result;
    return 0;
}