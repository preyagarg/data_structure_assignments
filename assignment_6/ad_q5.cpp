#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node *next,*prev,*up,*down;

    Node(int x){
        data=x;
        next=prev=up=down=NULL;
    }
};

Node* convertToDLL(vector<vector<int>> &mat){
    int r = mat.size();
    int c = mat[0].size();

    // Create a node pointer matrix of same size
    vector<vector<Node*>> node(r, vector<Node*>(c, NULL));

    // create all nodes first
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            node[i][j] = new Node(mat[i][j]);
        }
    }

    // link all pointers
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(j+1 < c) node[i][j]->next = node[i][j+1];   // right
            if(j-1 >= 0) node[i][j]->prev = node[i][j-1];  // left
            if(i+1 < r) node[i][j]->down = node[i+1][j];   // down
            if(i-1 >= 0) node[i][j]->up   = node[i-1][j];  // up
        }
    }

    return node[0][0]; // return head (top-left)
}

void displayRowWise(Node *head, int r, int c){
    Node *row = head;
    for(int i=0;i<r;i++){
        Node *col = row;
        for(int j=0;j<c;j++){
            cout<<col->data<<" ";
            col = col->next;
        }
        cout<<"\n";
        row = row->down;
    }
}

int main(){
    int r,c;
    cout<<"Enter rows and columns: ";
    cin>>r>>c;

    vector<vector<int>> mat(r, vector<int>(c));

    cout<<"Enter matrix values:\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }

    Node *head = convertToDLL(mat);

    cout<<"\nDoubly Linked (4-pointers) structure row-wise:\n";
    displayRowWise(head,r,c);

    return 0;
}
