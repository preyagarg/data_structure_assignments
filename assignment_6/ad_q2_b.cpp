#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int x){ data=x; next=NULL; }
};

class CircularList{
public:
    Node *head;
    CircularList(){ head=NULL; }

    void insertEnd(int x){
        Node *p=new Node(x);
        if(!head){
            head=p;
            p->next=head;
            return;
        }
        Node *t=head;
        while(t->next!=head) t=t->next;
        t->next=p;
        p->next=head;
    }

    int parity(int x){
        int ones=0;
        while(x){ if(x&1) ones++; x>>=1; }
        return ones;
    }

    void removeEvenParity(){
        if(!head) return;

        Node *curr=head,*prev=NULL;
        do{
            Node *next=curr->next;
            if(parity(curr->data)%2==0){     // EVEN parity remove
                if(curr==head){
                    Node *last=head;
                    while(last->next!=head) last=last->next;
                    head=head->next;
                    last->next=head;
                    delete curr;
                    curr=head;
                }else{
                    prev->next=curr->next;
                    delete curr;
                    curr=prev->next;
                }
            }else{
                prev=curr;
                curr=next;
            }
        }while(curr!=head);
    }

    void display(){
        if(!head){ cout<<endl; return; }
        Node *t=head;
        do{
            cout<<t->data<<" ";
            t=t->next;
        }while(t!=head);
        cout<<endl;
    }
};

int main(){
    CircularList CL;

    CL.insertEnd(9);
    CL.insertEnd(11);
    CL.insertEnd(34);
    CL.insertEnd(6);
    CL.insertEnd(13);
    CL.insertEnd(21);

    cout<<"Before: ";
    CL.display();

    CL.removeEvenParity();

    cout<<"After : ";
    CL.display();
}
