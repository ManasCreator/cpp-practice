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

// 1. Display
void display(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->val << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// 2. Insert at Head
void insertAtHead(Node*& head, int data){
    Node* newNode = new Node(data);

    newNode->next = head;
    head = newNode;
}

// 3. Insert at Tail
void insertAtTail(Node*& head, int data){
    Node* newNode = new Node(data);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

// 4. Insert at Position
void insertAtPos(Node*& head, int data, int pos){
    if(pos == 1){
        insertAtHead(head, data);
        return;
    }

    Node* newNode = new Node(data);
    Node* temp = head;
    int count = 1;

    while(count != pos - 1){
        temp = temp->next;
        count++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// 5. Delete at Head
void deleteAtHead(Node*& head){
    if(head == NULL)
        return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

// 6. Delete at Tail
void deleteAtTail(Node*& head){
    if(head == NULL)
        return;

    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while(temp->next->next != NULL){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// 7. Delete at Position
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

int main(){

    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);

    n1->next = n2;
    n2->next = n3;

    Node* head = n1;

    cout << "Original: ";
    display(head);

    insertAtHead(head, 5);
    cout << "After Insert Head: ";
    display(head);

    insertAtTail(head, 40);
    cout << "After Insert Tail: ";
    display(head);

    insertAtPos(head, 25, 4);
    cout << "After Insert Position: ";
    display(head);

    deleteAtHead(head);
    cout << "After Delete Head: ";
    display(head);

    deleteAtTail(head);
    cout << "After Delete Tail: ";
    display(head);

    deleteAtPos(head, 2);
    cout << "After Delete Position: ";
    display(head);

    return 0;
}