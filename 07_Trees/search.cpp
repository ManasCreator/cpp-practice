#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val); 
    }
    else {
        root->right = insert(root->right, val); 
    }

    return root;
}

Node* buildBST(vector<int> arr) {
    Node* root = NULL;

    for (int i = 0; i < arr.size(); i++) {
        root = insert(root, arr[i]);
    }

    return root;
}
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    vector<int> arr = {50, 30, 70, 20, 40, 60, 80};

    Node* root = buildBST(arr);

    inorder(root);
    cout<<endl;
    cout<<"Enter Key To Search : "<<endl;
    int key;
    cin>>key;
    Node* result = search(root, key);
    if (result != NULL)
    cout << "Found";
    else
    cout << "Not Found";

    return 0;
}