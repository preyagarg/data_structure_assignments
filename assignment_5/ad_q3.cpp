#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* newNode(int v){
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = v; n->next = NULL; return n;
}


int removeLoop(Node *head) {
    if (!head || !head->next) return 0;

    Node *slow = head, *fast = head;

    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (slow != fast) return 0; 

    
    slow = head;
    
    if (slow == fast) {
        while (fast->next != slow) fast = fast->next;
        fast->next = NULL;
        return 1;
    }

    
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    
    fast->next = NULL;
    return 1;
}


void printList(Node *head) {
    Node *t = head;
    while (t) {
        printf("%d", t->data);
        if (t->next) printf("->");
        t = t->next;
    }
    printf("\n");
}

int main() {
    
    Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    
    Node *node5 = head->next->next->next->next;
    Node *node3 = head->next->next;
    node5->next = node3;

    
    int removed = removeLoop(head);
    if (removed) {
        printf("Loop detected and removed.\n");
        printf("List after removal: ");
        printList(head);
    } else {
        printf("No loop found.\n");
        printf("List: ");
        printList(head);
    }

    return 0;
}
