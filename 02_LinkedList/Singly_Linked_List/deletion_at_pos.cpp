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
    Node* n4= new Node(40);
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    Node* head=n1;
    Node*temp=head;

    cout<<"Original List :"<<endl;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
    temp=head;
   int count=1;
   int pos;
   cout<<"Which position you want to remove?"<<endl;
   cin>>pos;
   while(count!=pos-1){
    temp=temp->next;
    count++;
   }
   Node* prev=temp;

   temp=prev->next;
   prev->next=temp->next;
   delete temp;
   temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

    return 0;
}