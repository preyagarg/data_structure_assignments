#include <bits/stdc++.h>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node *next;
    Node(int c, int p): coeff(c), pow(p), next(nullptr) {}
};


void appendTerm(Node*& tail, int coeff, int pow) {
    if (coeff == 0) return;
    tail->next = new Node(coeff, pow);
    tail = tail->next;
}


Node* addSorted(Node* a, Node* b) {
    Node dummy(0, 0);
    Node* tail = &dummy;
    while (a && b) {
        if (a->pow == b->pow) {
            int s = a->coeff + b->coeff;
            appendTerm(tail, s, a->pow);
            a = a->next; b = b->next;
        } else if (a->pow > b->pow) {
            appendTerm(tail, a->coeff, a->pow);
            a = a->next;
        } else {
            appendTerm(tail, b->coeff, b->pow);
            b = b->next;
        }
    }
    while (a) { appendTerm(tail, a->coeff, a->pow); a = a->next; }
    while (b) { appendTerm(tail, b->coeff, b->pow); b = b->next; }
    return dummy.next;
}


Node* addUnsorted(Node* a, Node* b) {
    unordered_map<int,int> M; // power -> coeff
    for (Node* p = a; p; p = p->next) M[p->pow] += p->coeff;
    for (Node* p = b; p; p = p->next) M[p->pow] += p->coeff;

    
    vector<int> powers;
    powers.reserve(M.size());
    for (auto &kv : M) if (kv.second != 0) powers.push_back(kv.first);
    sort(powers.rbegin(), powers.rend());

    Node dummy(0,0); Node* tail = &dummy;
    for (int pow : powers) appendTerm(tail, M[pow], pow);
    return dummy.next;
}


Node* build(const vector<pair<int,int>>& terms) {
    Node *head = nullptr, *tail = nullptr;
    for (auto &t : terms) {
        Node* n = new Node(t.first, t.second);
        if (!head) head = tail = n; else { tail->next = n; tail = n; }
    }
    return head;
}
void printPoly(Node* h) {
    if (!h) { cout << "0\n"; return; }
    bool first = true;
    while (h) {
        if (!first && h->coeff > 0) cout << "+";
        if (h->pow == 0) cout << h->coeff;
        else if (h->pow == 1) cout << h->coeff << "x";
        else cout << h->coeff << "x^" << h->pow;
        first = false;
        h = h->next;
    }
    cout << "\n";
}
void freeList(Node* h) { while (h) { Node* t = h->next; delete h; h = t; } }

int main() {
    
    Node* A = build({{5,3}, {4,2}, {2,1}, {1,0}});
    Node* B = build({{3,3}, {-4,2}, {6,0}});

    cout << "A: "; printPoly(A);
    cout << "B: "; printPoly(B);

    Node* sumSorted = addSorted(A, B);
    cout << "Sum (sorted-merge): ";
    printPoly(sumSorted);

    
    Node* C = build({{2,1}, {1,0}, {5,3}, {4,2}}); // same as A but unsorted
    Node* D = build({{6,0}, {3,3}, {-4,2}});       // same as B but unsorted

    Node* sumUnsorted = addUnsorted(C, D);
    cout << "Sum (unsorted-aggregate): ";
    printPoly(sumUnsorted);

    freeList(A); freeList(B); freeList(C); freeList(D);
    freeList(sumSorted); freeList(sumUnsorted);
    return 0;
}
