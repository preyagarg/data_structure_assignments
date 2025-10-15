#include <iostream>
#include <list>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to find intersection node
Node* getIntersectionNode(Node* head1, Node* head2) {
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    // If either list is empty
    if (!head1 || !head2)
        return nullptr;

    // Traverse both lists
    // When one pointer reaches end, redirect it to the head of other list
    // They will meet at intersection or at null
    while (ptr1 != ptr2) {
        ptr1 = (ptr1) ? ptr1->next : head2;
        ptr2 = (ptr2) ? ptr2->next : head1;
    }
    return ptr1; // nullptr if no intersection
}

int main() {
    // Create shared part of list
    Node* common = new Node(8);
    common->next = new Node(10);

    // First linked list: 3->6->9->8->10
    Node* head1 = new Node(3);
    head1->next = new Node(6);
    head1->next->next = new Node(9);
    head1->next->next->next = common;

    // Second linked list: 4->8->10
    Node* head2 = new Node(4);
    head2->next = common;

    Node* intersection = getIntersectionNode(head1, head2);

    if (intersection)
        cout << "Intersection Node: " << intersection->data << endl;
    else
        cout << "No intersection." << endl;

    return 0;
}
