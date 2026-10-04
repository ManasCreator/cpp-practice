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
        //Insert the new node somewhere in my left subtree,
        
    }
    else {
        root->right = insert(root->right, val); 
    }

    return root;// give me address of the root pointer of that tree/subtree
}

Node* buildBST(vector<int> arr) {
    Node* root = NULL;

    for (int i = 0; i < arr.size(); i++) {
        root = insert(root, arr[i]);
    }

    return root; //address to that node is returned
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

    return 0;
}