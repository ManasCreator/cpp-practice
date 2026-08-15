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
    Node* n1= new Node(10);
    Node* n2= new Node(20);
    Node* n3= new Node(30);
    n1->next=n2;
    n2->next=n3;
    Node* head=n1;
    Node*temp=head;
    Node* prev=head;

    cout<<"Original List :"<<endl;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
    cout<<"Which Value you want to Update?"<<endl;
    int target;
    cin>>target;
    cout<<"What value do you want it to be there?"<<endl;
    int newVal;
    cin>>newVal;
    temp=head;
   while(temp!=NULL){
    if(temp->val==target){
        temp->val=newVal;
        break;
    }
    temp=temp->next;
   }
    temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}