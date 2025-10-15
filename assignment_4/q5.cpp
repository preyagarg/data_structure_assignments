#include <iostream>
#include <queue>
using namespace std;


class StackUsingTwoQueues {
private:
    queue<int> q1; 
    queue<int> q2; 

public:
    void push(int x) {
        
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack underflow (two-queue)\n";
            return;
        }
        q1.pop();
    }

    int top() const {
        if (q1.empty()) {
            cerr << "Stack is empty (two-queue)\n";
            return -1;
        }
        return q1.front();
    }

    bool empty() const { return q1.empty(); }
    int size() const { return (int)q1.size(); }
};


class StackUsingOneQueue {
private:
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int n = q.size();
        
        for (int i = 0; i < n - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack underflow (one-queue)\n";
            return;
        }
        q.pop();
    }

    int top() const {
        if (q.empty()) {
            cerr << "Stack is empty (one-queue)\n";
            return -1;
        }
        return q.front();
    }

    bool empty() const { return q.empty(); }
    int size() const { return (int)q.size(); }
};


int main() {
    cout << "--- Stack using TWO queues demo ---\n";
    StackUsingTwoQueues s2;
    s2.push(10);
    s2.push(20);
    s2.push(30);
    cout << "Top: " << s2.top() << "  (expected 30)\n";
    s2.pop();
    cout << "Top after pop: " << s2.top() << "  (expected 20)\n";
    s2.pop();
    s2.push(40);
    cout << "Top after pushes/pops: " << s2.top() << "  (expected 40)\n";
    while (!s2.empty()) { cout << "pop " << s2.top() << '\n'; s2.pop(); }

    cout << "\n--- Stack using ONE queue demo ---\n";
    StackUsingOneQueue s1;
    s1.push(100);
    s1.push(200);
    s1.push(300);
    cout << "Top: " << s1.top() << "  (expected 300)\n";
    s1.pop();
    cout << "Top after pop: " << s1.top() << "  (expected 200)\n";
    s1.push(400);
    cout << "Top after pushes/pops: " << s1.top() << "  (expected 400)\n";
    while (!s1.empty()) { cout << "pop " << s1.top() << '\n'; s1.pop(); }

    return 0;
}
