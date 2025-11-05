#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class BST{
public:
    Node *root;
    BST(){ root = NULL; }

    Node* insert(Node* r,int x){
        if(r == NULL) return new Node(x);
        if(x == r->data){
            cout<<"Duplicate not allowed!\n";
            return r;
        }
        if(x < r->data) r->left = insert(r->left,x);
        else r->right = insert(r->right,x);
        return r;
    }

    void insert(int x){ root = insert(root,x); }

    Node* findMin(Node* r){
        while(r->left) r=r->left;
        return r;
    }

    Node* deleteNode(Node* r, int key){
        if(r == NULL) return r;
        if(key < r->data) r->left = deleteNode(r->left,key);
        else if(key > r->data) r->right = deleteNode(r->right,key);
        else{
            if(r->left == NULL){
                Node* temp=r->right;
                delete r;
                return temp;
            }
            else if(r->right == NULL){
                Node* temp=r->left;
                delete r;
                return temp;
            }

            Node* temp = findMin(r->right);
            r->data = temp->data;
            r->right = deleteNode(r->right,temp->data);
        }
        return r;
    }

    void deleteVal(int x){ root = deleteNode(root,x); }

    int maxDepth(Node* r){
        if(r==NULL) return 0;
        return 1 + max(maxDepth(r->left),maxDepth(r->right));
    }

    int minDepth(Node* r){
        if(r==NULL) return 0;
        if(!r->left && !r->right) return 1;
        if(!r->left) return 1 + minDepth(r->right);
        if(!r->right) return 1 + minDepth(r->left);
        return 1 + min(minDepth(r->left),minDepth(r->right));
    }

    int maxDepth(){ return maxDepth(root); }
    int minDepth(){ return minDepth(root); }

    void inorder(Node* r){
        if(r==NULL) return;
        inorder(r->left);
        cout<<r->data<<" ";
        inorder(r->right);
    }

    void display(){
        inorder(root);
        cout<<endl;
    }
};

int main(){
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout<<"Inorder BST: ";
    tree.display();

    cout<<"Max Depth = "<<tree.maxDepth()<<endl;
    cout<<"Min Depth = "<<tree.minDepth()<<endl;

    cout<<"Deleting 20\n";
    tree.deleteVal(20);

    cout<<"After deletion inorder: ";
    tree.display();

    return 0;
}
