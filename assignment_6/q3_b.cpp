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

class CircularList{
public:
    Node *head;
    CircularList(){ head = NULL; }

    void insertEnd(int x){
        Node *p = new Node(x);
        if(!head){
            head = p;
            p->next = head;
            return;
        }
        Node *t = head;
        while(t->next != head) t = t->next;
        t->next = p;
        p->next = head;
    }

    int size(){
        if(!head) return 0;
        int count = 0;
        Node *t = head;
        do{
            count++;
            t = t->next;
        }while(t != head);
        return count;
    }
};

int main(){
    CircularList CL;

    CL.insertEnd(20);
    CL.insertEnd(40);
    CL.insertEnd(60);
    CL.insertEnd(80);
    CL.insertEnd(100);

    cout<<"Size of Circular Linked List = "<<CL.size()<<endl;
}
