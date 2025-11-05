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

    void splitList(CircularList &first, CircularList &second){
        if(!head) return;

        Node *slow=head, *fast=head;

        while(fast->next!=head && fast->next->next!=head){
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast->next->next == head)
            fast = fast->next;

        first.head = head;
        second.head = slow->next;

        fast->next = slow->next;

        slow->next = head;
    }

    void display(){
        if(!head) return;
        Node *t = head;
        do{
            cout<<t->data<<" ";
            t=t->next;
        }while(t!=head);
        cout<<endl;
    }
};

int main(){
    CircularList CL, first, second;

    // Sample insert
    CL.insertEnd(10);
    CL.insertEnd(20);
    CL.insertEnd(30);
    CL.insertEnd(40);
    CL.insertEnd(50); 

    cout<<"Original List: ";
    CL.display();

    CL.splitList(first, second);

    cout<<"First half:  ";
    first.display();

    cout<<"Second half: ";
    second.display();
}
