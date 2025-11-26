#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev, *up, *down;

    Node(int val) {
        data = val;
        next = prev = up = down = NULL;
    }
};

Node* construct(int mat[][3], int R, int C) {

    // Create a 2D array of Node* to store created nodes
    Node* nodes[R][C];

    // Step 1: Create all nodes
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            nodes[i][j] = new Node(mat[i][j]);
        }
    }

    // Step 2: Connect the pointers
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {

            if (j + 1 < C)
                nodes[i][j]->next = nodes[i][j + 1];

            if (j - 1 >= 0)
                nodes[i][j]->prev = nodes[i][j - 1];

            if (i + 1 < R)
                nodes[i][j]->down = nodes[i + 1][j];

            if (i - 1 >= 0)
                nodes[i][j]->up = nodes[i - 1][j];
        }
    }

    // Return the head (top-left node)
    return nodes[0][0];
}

int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Node* head = construct(mat, 3, 3);

    // Example: print first row using next pointers
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
