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
    Node* newNode=new Node(25);
    Node*temp=head;
    int pos=3;
    int count=1;
    while(count!=pos-1){
        temp=temp->next;
        count++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    temp=head;

    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    return 0;
}
