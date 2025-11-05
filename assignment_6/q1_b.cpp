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

    void insertBeg(int x){
        Node*p=new Node(x);
        if(!head) head=p;
        else{
            p->next=head;
            head->prev=p;
            head=p;
        }
    }
    void insertEnd(int x){
        Node*p=new Node(x);
        if(!head){ head=p; return; }
        Node*t=head;
        while(t->next) t=t->next;
        t->next=p;
        p->prev=t;
    }
    void insertAfter(int key,int x){
        Node*t=head;
        while(t && t->data!=key) t=t->next;
        if(!t){ cout<<"Not Found\n"; return; }
        Node*p=new Node(x);
        p->next=t->next;
        if(t->next) t->next->prev=p;
        p->prev=t;
        t->next=p;
    }
    void insertBefore(int key,int x){
        Node*t=head;
        while(t && t->data!=key) t=t->next;
        if(!t){ cout<<"Not Found\n"; return; }
        if(t==head){ insertBeg(x); return; }
        Node*p=new Node(x);
        p->next=t;
        p->prev=t->prev;
        t->prev->next=p;
        t->prev=p;
    }
    void delNode(int key){
        if(!head) return;
        Node*t=head;
        while(t && t->data!=key) t=t->next;
        if(!t){ cout<<"Not Found\n"; return; }
        if(t==head){
            head=head->next;
            if(head) head->prev=NULL;
        }
        else{
            t->prev->next=t->next;
            if(t->next) t->next->prev=t->prev;
        }
        delete t;
    }
    void search(int key){
        int pos=1;
        Node*t=head;
        while(t){
            if(t->data==key){
                cout<<"Found at "<<pos<<"\n"; return;
            }
            t=t->next; pos++;
        }
        cout<<"Not Found\n";
    }
    void display(){
        Node*t=head;
        while(t){
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<"\n";
    }
};

int main(){
    DoublyList DL;
    int ch,x,key;
    while(1){
        cout<<"\n1.Insert Beg\n2.Insert End\n3.Insert After\n4.Insert Before\n5.Delete\n6.Search\n7.Display\n8.Exit\nChoice: ";
        cin>>ch;
        if(ch==8) break;
        cout<<"Enter value: "; cin>>x;
        switch(ch){
            case 1: DL.insertBeg(x); break;
            case 2: DL.insertEnd(x); break;
            case 3: cout<<"After which? "; cin>>key; DL.insertAfter(key,x); break;
            case 4: cout<<"Before which? "; cin>>key; DL.insertBefore(key,x); break;
            case 5: DL.delNode(x); break;
            case 6: DL.search(x); break;
            case 7: DL.display(); break;
        }
    }
}
