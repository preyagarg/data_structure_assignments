#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;
    Node(int x){
        data=x;
        left=right=NULL;
    }
};

bool isBSTUtil(Node* root, long long minVal, long long maxVal){
    if(root==NULL) return true;

    if(root->data <= minVal || root->data >= maxVal)
        return false;

    return  isBSTUtil(root->left,  minVal, root->data)  &&
            isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root){
    return isBSTUtil(root, -1e18, 1e18);
}

int main(){

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    if(isBST(root))
        cout<<"Given Binary Tree is a BST"<<endl;
    else
        cout<<"Given Binary Tree is NOT a BST"<<endl;

    return 0;
}
