#include <iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
    }
};
void display(Node* head){
    if(head == NULL){
        return;
    }
    Node* temp = head;

    do{
        cout << temp->val << "->";
        temp = temp->next;
    }while(temp != head);

    cout << "HEAD" << endl;
}
void insertAtHead(Node*& head,int val){
    Node* newNode=new Node(val);
    Node*temp=head;
    while(temp->next != head){
        temp=temp->next;
    }
    temp->next = newNode;
    newNode->next=head;
    head=newNode;
}
void insertAtTail(Node*& head, int val){
    Node* newNode = new Node(val);

    Node* temp = head;

    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}
void insertAtPos(Node*& head, int val, int pos){
    if(pos == 1){
        insertAtHead(head, val);
        return;
    }

    Node* newNode = new Node(val);
    Node* temp = head;
    int count = 1;

    while(count != pos - 1){
        temp = temp->next;
        count++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteAtHead(Node*& head){
    if(head == NULL)
        return;

    Node* temp = head;

    if(head->next == head){
        delete head;
        head = NULL;
        return;
    }

    Node* last = head;

    while(last->next != head){
        last = last->next;
    }

    head = head->next;
    last->next = head;

    delete temp;
}
void deleteAtTail(Node*& head){
    if(head == NULL)
        return;

    if(head->next == head){
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while(temp->next->next != head){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = head;
}
void deleteAtPos(Node*& head, int pos){
    if(head == NULL)
        return;

    if(pos == 1){
        deleteAtHead(head);
        return;
    }

    Node* prev = head;
    int count = 1;

    while(count != pos - 1){
        prev = prev->next;
        count++;
    }

    Node* temp = prev->next;
    prev->next = temp->next;
    delete temp;
}
int main() {
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);

    n1->next = n2;
    n2->next = n3;
    n3->next = n1;

    Node* head = n1;

    cout << "Original List: ";
    display(head);

    cout << "Adding 5 at Head: ";
    insertAtHead(head, 5);
    display(head);

    cout << "Adding 40 at Tail: ";
    insertAtTail(head, 40);
    display(head);

    cout << "Adding 25 at Position 4: ";
    insertAtPos(head, 25, 4);
    display(head);

    cout << "Deleting Head: ";
    deleteAtHead(head);
    display(head);

    cout << "Deleting Tail: ";
    deleteAtTail(head);
    display(head);

    cout << "Deleting Position 3: ";
    deleteAtPos(head, 3);
    display(head);



    return 0;
}