
#include <iostream>
using namespace std;
/*
    DRY RUN:

    BST:
               50
              /  \
            30    70
           / \    / \
          20  40  60  80

    STEP 2: Count left subtree
    int left = countNodes(root->left);

    countNodes(50) calls countNodes(30).
    countNodes(30) calls countNodes(20).
    Node 20 has no children:
    return 1 + 0 + 0 = 1

    Back at node 30:
    Left subtree (20) returns 1.
    Right subtree (40) returns 1.

    return 1 + 1 + 1 = 3

    Therefore, left = 3 at node 50.

    STEP 3: Count right subtree
    int right = countNodes(root->right);

    countNodes(50) calls countNodes(70).
    Node 60 returns 1.
    Node 80 returns 1.

    At node 70:
    left = 1
    right = 1

    return 1 + 1 + 1 = 3

    Therefore, right = 3 at node 50.

    STEP 4: Calculate total nodes

    At node 50:
    left = 3
    right = 3

    return 1 + left + right
    return 1 + 3 + 3 = 7

    FINAL ANSWER: Total nodes = 7
    */

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

int countNodes(Node* root) {
    if (root == NULL)
        return 0;

    int left = countNodes(root->left);
    int right = countNodes(root->right);

    return 1 + left + right;
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Total nodes: " << countNodes(root);

    return 0;
}
