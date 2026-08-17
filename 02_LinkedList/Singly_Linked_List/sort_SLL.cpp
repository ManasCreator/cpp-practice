#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node*& head, int val) {

    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void display(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

void sortList(Node* head) {

    for (Node* i = head; i != NULL; i = i->next) {

        for (Node* j = i->next; j != NULL; j = j->next) {

            if (i->data > j->data) {
                swap(i->data, j->data);
            }
        }
    }
}

int main() {

    Node* head = NULL;

    insertAtTail(head, 24);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 8);
    insertAtTail(head, 10);
    insertAtTail(head, 4);

    cout << "Before sorting: ";
    display(head);

    sortList(head);

    cout << "After sorting: ";
    display(head);

    return 0;
}