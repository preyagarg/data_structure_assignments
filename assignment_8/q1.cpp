#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void preorder(Node* root){
    if(root==NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){


    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    cout << "Preorder  : ";
    preorder(root);

    cout << "\nInorder   : ";
    inorder(root);

    cout << "\nPostorder : ";
    postorder(root);

    cout<<endl;
    return 0;
}
