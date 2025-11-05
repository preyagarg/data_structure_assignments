#include<iostream>
using namespace std;

class Node{
public:
    char data;
    Node *prev,*next;
    Node(char ch){
        data = ch;
        prev = next = NULL;
    }
};

class DoublyList{
public:
    Node *head;
    DoublyList(){ head = NULL; }

    void insertEnd(char ch){
        Node *p = new Node(ch);
        if(!head){
            head = p;
            return;
        }
        Node *t = head;
        while(t->next) t = t->next;
        t->next = p;
        p->prev = t;
    }

    bool isPalindrome(){
        if(!head) return true;

        Node *left = head;
        Node *right = head;

        while(right->next) right = right->next;

        while(left != right && right->next != left){
            if(left->data != right->data)
                return false;

            left = left->next;
            right = right->prev;
        }
        return true;
    }

    void display(){
        Node *t=head;
        while(t){
            cout << t->data << " ";
            t=t->next;
        }
        cout<<endl;
    }
};

int main(){
    DoublyList DL;
    string s;

    cout<<"Enter characters string: ";
    cin>>s;

    for(char c : s){
        DL.insertEnd(c);
    }

    cout<<"DLL Elements: ";
    DL.display();

    if(DL.isPalindrome())
        cout<<"Palindrome DLL"<<endl;
    else
        cout<<"Not Palindrome DLL"<<endl;
}
