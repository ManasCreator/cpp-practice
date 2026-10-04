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

// Inorder: Left -> Root -> Right
void inorder(Node* root, vector<int>& ans) {
    if (root == NULL)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

// Preorder: Root -> Left -> Right
void preorder(Node* root, vector<int>& ans) {
    if (root == NULL)
        return;

    ans.push_back(root->data);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

// Postorder: Left -> Right -> Root
void postorder(Node* root, vector<int>& ans) {
    if (root == NULL)
        return;

    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->data);
}

int main() {

    // Creating the tree
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Vectors to store traversals
    vector<int> in;
    vector<int> pre;
    vector<int> post;

    // Function calls
    inorder(root, in);
    preorder(root, pre);
    postorder(root, post);

    // Print Inorder
    cout << "Inorder: ";
    for (int i = 0; i < in.size(); i++) {
        cout << in[i] << " ";
    }

    // Print Preorder
    cout << "\nPreorder: ";
    for (int i = 0; i < pre.size(); i++) {
        cout << pre[i] << " ";
    }

    // Print Postorder
    cout << "\nPostorder: ";
    for (int i = 0; i < post.size(); i++) {
        cout << post[i] << " ";
    }

    return 0;
}