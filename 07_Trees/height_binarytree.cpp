#include <iostream>
#include <algorithm>
using namespace std;
 /*
    DRY RUN:
    BST:
               50
              /  \
            30    70
           / \    / \
          20  40  60  80

    STEP 2: Calculate left subtree height
    int left = height(root->left);

    First: height(50) calls height(30)
    Then:  height(30) calls height(20)
    Then:  height(20) calls height(NULL)

    height(NULL) returns 0.
    Node 20 has no right child either, so that returns 0.

    At node 20:
    left = 0
    right = 0
    return 1 + max(0, 0) = 1

    Back at node 30:
    left = 1
    Now height(40) is called and returns 1.
    right = 1

    return 1 + max(1, 1) = 2

    Therefore, height(30) returns 2 to height(50).
    So, at node 50: left = 2

    STEP 3: Calculate right subtree height
    int right = height(root->right);

    height(50) calls height(70).
    Node 70 has children 60 and 80.
    height(60) returns 1.
    height(80) returns 1.

    At node 70:
    left = 1
    right = 1

    return 1 + max(1, 1) = 2

    Therefore, height(70) returns 2 to height(50).
    So, at node 50: right = 2

    STEP 4: Calculate final height

    At node 50:
    left = 2
    right = 2

    return 1 + max(2, 2) = 3

    FINAL ANSWER: Height of BST = 3 nodes
    */

struct Node {
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

int height(Node* root) {
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return 1 + max(left, right); // max of left or right tree + 1 
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

    cout << "Height of BST: " << height(root);

    return 0;
}