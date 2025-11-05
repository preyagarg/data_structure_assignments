#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *prev,*next;
    Node(int x){ data=x; prev=next=NULL; }
};

class DoublyList{
public:
    Node *head;
    DoublyList(){ head=NULL; }

    void insertEnd(int x){
        Node *p=new Node(x);
        if(!head){ head=p; return; }
        Node *t=head;
        while(t->next) t=t->next;
        t->next=p;
        p->prev=t;
    }

    int parity(int x){
        int ones=0;
        while(x){ if(x&1) ones++; x>>=1; }
        return ones;
    }

    void removeEvenParity(){
        Node *t=head;
        while(t){
            Node *nxt=t->next;
            if(parity(t->data) % 2 == 0){ // EVEN parity
                if(t==head){
                    head=head->next;
                    if(head) head->prev=NULL;
                }else{
                    t->prev->next=t->next;
                    if(t->next) t->next->prev=t->prev;
                }
                delete t;
            }
            t=nxt;
        }
    }

    void display(){
        Node *t=head;
        while(t){
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }
};

int main(){
    DoublyList DL;
    DL.insertEnd(18);
    DL.insertEnd(15);
    DL.insertEnd(8);
    DL.insertEnd(9);
    DL.insertEnd(14);

    cout<<"Before: ";
    DL.display();

    DL.removeEvenParity();

    cout<<"After : ";
    DL.display();
}
