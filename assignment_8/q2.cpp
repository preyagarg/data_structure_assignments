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

class BST{
public:
    Node *root;
    BST(){ root=NULL; }

    Node* insert(Node* r,int x){
        if(r==NULL) return new Node(x);
        if(x<r->data) r->left=insert(r->left,x);
        else r->right=insert(r->right,x);
        return r;
    }

    void insert(int x){ root=insert(root,x); }

    // (a) Recursive Search
    Node* searchRec(Node* r,int key){
        if(r==NULL || r->data==key) return r;
        if(key<r->data) return searchRec(r->left,key);
        return searchRec(r->right,key);
    }

    // (a) Non-Recursive Search
    Node* searchNonRec(int key){
        Node*r=root;
        while(r){
            if(r->data==key) return r;
            if(key<r->data) r=r->left;
            else r=r->right;
        }
        return NULL;
    }

    int maxElement(){
        Node*r=root;
        if(!r) return -1;
        while(r->right) r=r->right;
        return r->data;
    }

    int minElement(){
        Node*r=root;
        if(!r) return -1;
        while(r->left) r=r->left;
        return r->data;
    }

    Node* inorderSuccessor(int key){
        Node *curr=root, *succ=NULL;
        while(curr){
            if(key < curr->data){
                succ = curr;
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
        return succ;
    }

    Node* inorderPredecessor(int key){
        Node *curr=root, *pred=NULL;
        while(curr){
            if(key > curr->data){
                pred = curr;
                curr = curr->right;
            }else{
                curr = curr->left;
            }
        }
        return pred;
    }

};

int main(){
    BST tree;
    int a[]={50,30,70,20,40,60,80};
    for(int x:a) tree.insert(x);

    cout<<"Max   = "<<tree.maxElement()<<endl;
    cout<<"Min   = "<<tree.minElement()<<endl;

    int key = 40;

    Node *r1=tree.searchRec(tree.root,key);
    cout<<"Recursive search "<<key<<" => "<<(r1?"Found":"Not Found")<<endl;

    Node *r2=tree.searchNonRec(key);
    cout<<"Non-Recursive search "<<key<<" => "<<(r2?"Found":"Not Found")<<endl;

    Node *succ=tree.inorderSuccessor(key);
    cout<<"Successor of "<<key<<" => "<<(succ?to_string(succ->data):"None")<<endl;

    Node *pred=tree.inorderPredecessor(key);
    cout<<"Predecessor of "<<key<<" => "<<(pred?to_string(pred->data):"None")<<endl;

    return 0;
}
