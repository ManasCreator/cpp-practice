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
    cout<<"Which Value you want to delete?"<<endl;
    int target;
    cin>>target;
    temp=head;
    if(temp->val==target){
        head=head->next;
        delete temp;
    }
    else{

    while(temp->val!=target){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    delete temp;
}
    temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}