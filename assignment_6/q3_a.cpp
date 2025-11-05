#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *prev, *next;
    Node(int x){
        data = x;
        prev = next = NULL;
    }
};

class DoublyList{
public:
    Node *head;
    DoublyList(){ head = NULL; }

    void insertEnd(int x){
        Node *p = new Node(x);
        if(!head){
            head = p;
            return;
        }
        Node *t = head;
        while(t->next) t = t->next;
        t->next = p;
        p->prev = t;
    }

    int size(){
        int count = 0;
        Node *t = head;
        while(t){
            count++;
            t = t->next;
        }
        return count;
    }
};

int main(){
    DoublyList DL;

    DL.insertEnd(10);
    DL.insertEnd(20);
    DL.insertEnd(30);
    DL.insertEnd(40);

    cout<<"Size of Doubly Linked List = "<<DL.size()<<endl;
}
