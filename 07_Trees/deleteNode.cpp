#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node*left;
    Node*right;
Node(int val){
    data=val;
    left=NULL;
    right=NULL;
}
};

Node* insert(Node* root,int val){
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
    return root;
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* buildBST(vector<int> arr){
Node* root=NULL;
for(int i=0;i<arr.size();i++){
    root=insert(root,arr[i]);
}
return root;
}

Node* getInorderSuccessor(Node* root){//left most node in right subtree
    while(root !=NULL && root->left != NULL){
        root=root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(key<root->data){
        root->left=deleteNode(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteNode(root->right,key);
    }
    else{
        //key==root
        if(root->left==NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            //for 2 children
            Node* IS = getInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = deleteNode(root->right, IS->data);
        }
    }
     return root;
}

int main() {
    vector<int> arr ={50, 30, 70, 20, 40, 60, 80};
    Node* root = buildBST(arr);
    inorder(root);
    cout<<endl;
    cout<<"Enter Key to delete : ";
    int key;
    cin>>key;
    root=deleteNode(root,key);
    cout<<"After : "<<endl;
    inorder(root);


    return 0;
}