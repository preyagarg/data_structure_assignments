#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

bool isCircular(Node *head){
    if(!head) return false;

    Node *t = head->next;

    while(t != NULL && t != head){
        t = t->next;
    }

    return (t == head);
}

int main(){
    Node *head = NULL;

    // creating example nodes manually:
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);

    head = a;
    a->next = b;
    b->next = c;
    c->next = a;      
  if(isCircular(head))
        cout<<"It is a Circular Linked List";
    else
        cout<<"It is NOT a Circular Linked List";

    return 0;
}
