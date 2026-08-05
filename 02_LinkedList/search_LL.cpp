#include <iostream>
using namespace std;
class Node{
    public:
int val;
Node* next;
Node(int data){
    val=data;
    next=NULL;
}
};
int main() {
    Node* n1=new Node(10);
    Node* n2=new Node(20);
    Node* n3=new Node(30);
    n1->next=n2;
    n2->next=n3;
    Node*head=n1;
    Node* temp=head;
    cout<<"Enter Target : ";
    int target;
    cin>>target;
    int found=0;

    while(temp!=NULL){
        if(target==temp->val){
            cout<<" Found ";
            found=1;
            break;
        }
        else{
          temp=temp->next;  
        }

    }
    if(found==0){
        cout<<" Not Found ";
    }
   


    return 0;
}