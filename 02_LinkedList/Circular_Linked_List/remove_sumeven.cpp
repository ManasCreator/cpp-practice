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

// Insert at tail
void insertAtTail(Node*& head, int val) {

    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Display circular linked list
void display(Node* head) {

    if (head == NULL) {
        cout << "List is empty";
        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)" << endl;
}

// Calculate digit sum
int digitSum(int n) {

    int sum = 0;

    while (n > 0) {
        sum = sum + (n % 10);
        n = n / 10;
    }

    return sum;
}

// Delete nodes whose digit sum is even
void deleteEvenDigitSum(Node*& head) {

    if (head == NULL)
        return;

    // Find last node
    Node* prev = head;

    while (prev->next != head) {
        prev = prev->next;
    }

    Node* current = head;

    do {

        Node* next = current->next;

        if (digitSum(current->data) % 2 == 0) {

            // Only one node exists
            if (current == head && current->next == head) {
                delete current;
                head = NULL;
                return;
            }

            // Remove current node
            prev->next = current->next;

            // If current is head
            if (current == head) {
                head = current->next;
            }

            delete current;
        }
        else {
            prev = current;
        }

        current = next;

    } while (current != head);
}

int main() {

    Node* head = NULL;

    // Create circular linked list
    insertAtTail(head, 9);
    insertAtTail(head, 11);
    insertAtTail(head, 34);
    insertAtTail(head, 6);
    insertAtTail(head, 13);
    insertAtTail(head, 21);

    cout << "Original list: ";
    display(head);

    deleteEvenDigitSum(head);

    cout << "After deletion: ";
    display(head);

    return 0;
}