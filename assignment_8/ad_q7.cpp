#include <iostream>
using namespace std;

// ------------------- Structure Definitions -------------------
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct DLLNode {
    int val;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int x) : val(x), prev(NULL), next(NULL) {}
};

// ------------------- BST to DLL Conversion -------------------
void convertBSTtoDLL(TreeNode* root, DLLNode*& head, DLLNode*& tail) {
    if (root == NULL)
        return;

    // Convert left subtree
    convertBSTtoDLL(root->left, head, tail);

    // Create new DLL node for current BST node
    DLLNode* newNode = new DLLNode(root->val);

    // Link into DLL
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Convert right subtree
    convertBSTtoDLL(root->right, head, tail);
}

// ------------------- Merge Two Sorted DLLs -------------------
DLLNode* mergeDLLs(DLLNode* head1, DLLNode* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    DLLNode* head = NULL;
    DLLNode* tail = NULL;

    // Merge like in merge sort
    while (head1 && head2) {
        DLLNode* temp;
        if (head1->val < head2->val) {
            temp = head1;
            head1 = head1->next;
        } else {
            temp = head2;
            head2 = head2->next;
        }

        temp->prev = tail;
        temp->next = NULL;

        if (!head)
            head = temp;
        else
            tail->next = temp;

        tail = temp;
    }

    // Attach remaining nodes
    if (head1) {
        tail->next = head1;
        head1->prev = tail;
    } else if (head2) {
        tail->next = head2;
        head2->prev = tail;
    }

    return head;
}

// ------------------- Utility Function -------------------
void printDLL(DLLNode* head) {
    cout << "Merged Doubly Linked List (sorted): ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// ------------------- Driver Code -------------------
int main() {
    /*
          BST1              BST2
            3                 8
           / \               / \
          1   5             7   10
    */

    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(5);

    TreeNode* root2 = new TreeNode(8);
    root2->left = new TreeNode(7);
    root2->right = new TreeNode(10);

    // Convert both BSTs to sorted DLLs
    DLLNode *head1 = NULL, *tail1 = NULL;
    DLLNode *head2 = NULL, *tail2 = NULL;

    convertBSTtoDLL(root1, head1, tail1);
    convertBSTtoDLL(root2, head2, tail2);

    // Merge both DLLs
    DLLNode* mergedHead = mergeDLLs(head1, head2);

    // Display result
    printDLL(mergedHead);

    return 0;
}
