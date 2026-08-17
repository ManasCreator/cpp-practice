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
void deleteAllOccurrence(Node*&head,int target){
    while(head!=NULL && head->val==target){
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    Node*prev=head;
    Node*temp=head->next;
    while(temp!=NULL){
        if(temp->val==target){
            prev->next=temp->next;
            delete temp;
            temp=prev->next;
        }
        else{
            prev=temp;
            temp=temp->next;
        }
    }
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
     insertAtTail(head,10);
      insertAtTail(head,30);
      deleteAllOccurrence(head,10);
      display(head);
    return 0;
}