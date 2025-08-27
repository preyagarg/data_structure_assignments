#include <iostream>
#include <stack>

using namespace std;

// Function to check precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> st;       // stack for operators
    string postfix = "";  // result

    for (char ch : infix) {
        // If operand (letter/number) → add directly to postfix
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If '(' → push to stack
        else if (ch == '(') {
            st.push(ch);
        }
        // If ')' → pop until '('
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
        // If operator
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
