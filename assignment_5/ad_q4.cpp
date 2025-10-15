#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* build(const vector<int>& a) {
    ListNode *head = nullptr, *tail = nullptr;
    for (int x : a) {
        ListNode *n = new ListNode(x);
        if (!head) head = tail = n;
        else { tail->next = n; tail = n; }
    }
    return head;
}

void printList(ListNode *h) {
    if (!h) { cout << "Empty\n"; return; }
    while (h) {
        cout << h->val;
        if (h->next) cout << "->";
        h = h->next;
    }
    cout << '\n';
}

ListNode* rotateLeft(ListNode* head, int k) {
    if (!head || !head->next || k <= 0) return head;

   
    ListNode *tail = head;
    int n = 1;
    while (tail->next) { tail = tail->next; ++n; }

    k %= n;
    if (k == 0) return head;

    
    tail->next = head;

    
    ListNode *newTail = head;
    for (int i = 1; i < k; ++i) newTail = newTail->next;

    ListNode *newHead = newTail->next;
    newTail->next = nullptr; 

    return newHead;
}

void freeList(ListNode *h) {
    while (h) {
        ListNode *t = h->next;
        delete h;
        h = t;
    }
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    ListNode *head = build(arr);

    cout << "Original: ";
    printList(head);

    int k = 2;
    head = rotateLeft(head, k);

    cout << "After left-rotate by " << k << ": ";
    printList(head);

    freeList(head);
    return 0;
}
