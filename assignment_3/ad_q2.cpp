#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
private:
    stack<int> mainStack;   // normal stack 
    stack<int> minStack;    // stores min element at each level

public:
    // Push element
    void push(int x) {
        mainStack.push(x);
        // if minStack is empty OR x is smaller, push x
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        } else {
            // otherwise, repeat the current minimum
            minStack.push(minStack.top());
        }
    }

    // Pop element
    void pop() {
        if (!mainStack.empty()) {
            mainStack.pop();
            minStack.pop();
        } else {
            cout << "Stack Underflow\n";
        }
    }

    // Peek top element
    int peek() {
        if (!mainStack.empty()) {
            return mainStack.top();
        }
        cout << "Stack is empty\n";
        return -1;
    }

    // Get minimum in O(1)
    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        }
        cout << "Stack is empty\n";
        return -1;
    }

    // Check if empty
    bool empty() {
        return mainStack.empty();
    }
};

int main() {
    SpecialStack s;
    s.push(10);
    s.push(20);
    s.push(5);
    s.push(30);

    cout << "Current Min: " << s.getMin() << endl; // 5
    s.pop();
    cout << "Current Min: " << s.getMin() << endl; // 5
    s.pop();
    cout << "Current Min: " << s.getMin() << endl; // 10
    return 0;
}
