#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node *prev, *next, *random;
    Node(int x){
        data=x;
        prev=next=random=NULL;
    }
};

class DoublyList{
public:
    Node *head;
    DoublyList(){ head=NULL; }

    void insertEnd(int x){
        Node *p=new Node(x);
        if(!head){
            head=p;
            return;
        }
        Node *t=head;
        while(t->next) t=t->next;
        t->next=p;
        p->prev=t;
    }

    void fixRandomPointer(){
        vector<Node*> arr;
        Node* t=head;

        while(t){
            arr.push_back(t);
            t=t->next;
        }

        for(Node* x : arr){
            if(x->random){
                int correctIndex = x->data - 1;
                if(correctIndex>=0 && correctIndex < arr.size()){
                    x->random = arr[correctIndex];
                }
            }
        }
    }

    void display(){
        Node* t=head;
        while(t){
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }

    void displayRandom(){
        Node* t=head;
        while(t){
            if(t->random)
                cout<<t->data<<"->"<<t->random->data<<"  ";
            else
                cout<<t->data<<"->NULL ";
            t=t->next;
        }
        cout<<endl;
    }
};

int main(){
    DoublyList DL;

    DL.insertEnd(1);
    DL.insertEnd(2);
    DL.insertEnd(3);
    DL.insertEnd(4);
    DL.insertEnd(5);

    DL.head->random = DL.head->next->next; 
    DL.head->next->random = DL.head->next;
    DL.head->next->next->random = DL.head;  
    DL.head->next->next->next->random = DL.head->next->next->next->next;
    DL.head->next->next->next->next->random = DL.head->next; 

    cout<<"Before correction random:\n";
    DL.displayRandom();

    DL.fixRandomPointer();

    cout<<"\nAfter correction random:\n";
    DL.displayRandom();
}
