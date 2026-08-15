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
void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}
bool search(Node*head,int target){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->val==target){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
int searchPos(Node*head,int target){
     Node* temp=head;
     int position=1;
     while(temp!=NULL){
        if(temp->val==target){
            return position;
        }
        temp=temp->next;
        position++;
    }
    return -1;

}

int main() {
    Node* n1=new Node(10);
    Node* n2=new Node(20);
    Node* n3=new Node(30);
    Node* head=n1;
    n1->next=n2;
    n2->next=n3;
    display(head);
    cout<<"What Value You Want to Search??"<<endl;
    int target;
    cin>>target;
    if(search(head,target))
    cout << "Found"<<endl;
else
    cout << "Not Found";

int result = searchPos(head, target);

if(result == -1)
    cout << "Not Found";
else
    cout << "Position: " << result;

    

    
    
    return 0;
}