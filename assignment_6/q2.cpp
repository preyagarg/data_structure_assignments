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
    CircularList(){
        head = NULL;
    }

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

    void displayRepeatHead(){ 
        if(!head){
            cout<<"List empty";
            return;
        }
        Node *t = head;
        do{
            cout << t->data << " ";
            t = t->next;
        }while(t != head);

        cout << head->data << endl;
    }
};

int main(){
    CircularList CL;

    CL.insertEnd(20);
    CL.insertEnd(100);
    CL.insertEnd(40);
    CL.insertEnd(80);
    CL.insertEnd(60);

    cout << "Output: ";
    CL.displayRepeatHead();
}
