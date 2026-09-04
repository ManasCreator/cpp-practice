#include <iostream>
using namespace std;

class DoublyList {
    class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int val) {
            data = val;
            prev = NULL;
            next = NULL;
        }
    };

    Node* head;
    Node* tail;

public:

    // Initialization
    DoublyList() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);

        if (tail == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if (head == NULL)
            return;

        Node* temp = head;

        if (head == tail) {
            head = tail = NULL;
        }
        else {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;
    }

    void pop_back() {
        if (tail == NULL)
            return;

        Node* temp = tail;

        if (head == tail) {
            head = tail = NULL;
        }
        else {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete temp;
    }
    void print() {
    Node* temp = head;

    // Forward
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;

    // Backward
    temp = tail;

    while (temp != NULL) {
        cout << temp->data << " <- ";
        temp = temp->prev;
    }

    cout << "NULL" << endl;
}
};

int main() {
    DoublyList dll;

    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);

    dll.push_back(4);

    dll.pop_front();
    dll.pop_back();
    dll.print();

    return 0;
}