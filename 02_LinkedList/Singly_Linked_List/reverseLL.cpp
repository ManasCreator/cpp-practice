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
 void insertAtHead(Node*&head,int val){
    Node* newNode= new Node(val);
    newNode->next=head;
    head=newNode;
}
void insertAtTail(Node*&head,int val){
    Node* newNode= new Node(val);
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;


}
//REVERSAL RECURSION LOGIC

void reverseLL(Node*&head){
    if(head==NULL)
    return;
    reverseLL(head->next);
    cout<<head->val<<"->";
}

void display(Node* head){
    Node* temp=head;
    while (temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main() {
    Node*head=NULL;
    insertAtHead(head,10);
    insertAtTail(head,20);
    insertAtTail(head,30);
    insertAtTail(head,40);
    reverseLL(head);
    cout<<"NULL";

    return 0;
}