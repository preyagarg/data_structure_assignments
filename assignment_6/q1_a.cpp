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

    void insertBeg(int x){
        Node*p=new Node(x);
        if(!head){ head=p; p->next=head; return; }
        Node*t=head;
        while(t->next!=head) t=t->next;
        t->next=p;
        p->next=head;
        head=p;
    }

    void insertEnd(int x){
        Node*p=new Node(x);
        if(!head){ head=p; p->next=head; return; }
        Node*t=head;
        while(t->next!=head) t=t->next;
        t->next=p;
        p->next=head;
    }

    void delNode(int key){
        if(!head) return;
        Node*t=head,*prev=NULL;
        while(t->data!=key){
            if(t->next==head){ cout<<"Not Found\n"; return; }
            prev=t;
            t=t->next;
        }
        if(t==head){
            Node*last=head;
            while(last->next!=head) last=last->next;
            head=head->next;
            last->next=head;
        }else prev->next=t->next;
        delete t;
    }

    void search(int key){
        if(!head) return;
        int pos=1;
        Node*t=head;
        do{
            if(t->data==key){ cout<<"Found at "<<pos<<"\n"; return; }
            t=t->next; pos++;
        } while(t!=head);
        cout<<"Not Found\n";
    }

    void display(){
        if(!head){ cout<<"Empty\n"; return; }
        Node*t=head;
        do{
            cout<<t->data<<" ";
            t=t->next;
        } while(t!=head);
        cout<<"\n";
    }
};

int main(){
    CircularList CL;
    int ch,x;

    while(1){
        cout<<"\n1.Insert Beg\n2.Insert End\n3.Delete\n4.Search\n5.Display\n6.Exit\nChoice: ";
        cin>>ch;
        if(ch==6) break;

        if(ch==1||ch==2||ch==3||ch==4){
            cout<<"Enter value: "; cin>>x;
        }
        switch(ch){
            case 1: CL.insertBeg(x); break;
            case 2: CL.insertEnd(x); break;
            case 3: CL.delNode(x); break;
            case 4: CL.search(x); break;
            case 5: CL.display(); break;
        }
    }
}
