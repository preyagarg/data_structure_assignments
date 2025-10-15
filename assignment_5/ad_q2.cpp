#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;


Node* createNode(int val) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->next = NULL;
    return n;
}


void insertEnd(Node **head, int val) {
    Node *n = createNode(val);
    if (*head == NULL) {
        *head = n;
        return;
    }
    Node *t = *head;
    while (t->next) t = t->next;
    t->next = n;
}


Node* reverseKGroup(Node *head, int k) {
    Node *cur = head, *prev = NULL, *next = NULL;
    int count = 0;

    
    Node *temp = head;
    for (int i = 0; i < k; i++) {
        if (!temp) return head; 
        temp = temp->next;
    }

   
    while (cur && count < k) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        count++;
    }

    
    if (next)
        head->next = reverseKGroup(next, k);

    return prev; 
}


void display(Node *head) {
    while (head) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    for (int i = 0; i < n; i++)
        insertEnd(&head, arr[i]);

    printf("Original List: ");
    display(head);

    head = reverseKGroup(head, k);

    printf("Reversed in groups of %d: ", k);
    display(head);

    return 0;
}
