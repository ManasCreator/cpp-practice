
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

int sumNodes(Node* root) {
    // If the node is NULL, return 0
    if (root == NULL)
        return 0;

    // Calculate sum of left and right subtrees
    int left = sumNodes(root->left);
    int right = sumNodes(root->right);

    // Add current node's data to both subtree sums
    return root->data + left + right;
}

int main() {
    Node* root = NULL;

    // Build the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Sum of nodes: " << sumNodes(root);

    return 0;
}
