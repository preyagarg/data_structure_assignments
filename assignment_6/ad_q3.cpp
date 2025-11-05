#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *prev,*next;
    Node(int x){
        data = x;
        prev = next = NULL;
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

    Node* reverseK(Node* start, int k){
        Node* curr=start;
        Node* prevNode=NULL;
        int cnt=0;

        while(curr!=NULL && cnt<k){
            Node* next=curr->next;
            curr->next=prevNode;
            curr->prev=next;
            prevNode=curr;
            curr=next;
            cnt++;
        }

        if(start) start->next = curr;
        if(curr) curr->prev = start;
        return prevNode;
    }

    void reverseInGroups(int k){
        if(!head || k<=1) return;

        Node *curr=head;
        Node *newHead=NULL;
        Node *lastBlockEnd=NULL;

        while(curr){
            Node *blockStart = curr;

            int count=0;
            Node *temp=curr;
            while(temp && count<k){
                temp=temp->next;
                count++;
            }

            Node *revHead = reverseK(curr,k);

            if(!newHead)
                newHead = revHead;

            if(lastBlockEnd){
                lastBlockEnd->next = revHead;
                revHead->prev = lastBlockEnd;
            }

            lastBlockEnd = blockStart;
            curr = blockStart->next;
        }

        head=newHead;
    }

    void display(){
        Node*t=head;
        while(t){
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }
};

int main(){
    DoublyList DL;
    int n,k,x;

    cout<<"Enter number of nodes: ";
    cin>>n;

    cout<<"Enter "<<n<<" values:\n";
    for(int i=0;i<n;i++){
        cin>>x;
        DL.insertEnd(x);
    }

    cout<<"Enter k: ";
    cin>>k;

    cout<<"Before: ";
    DL.display();

    DL.reverseInGroups(k);

    cout<<"After : ";
    DL.display();
}
