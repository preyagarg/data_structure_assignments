#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(string expr) {
    stack<int> st;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        // Skip spaces
        if (ch == ' ') continue;

        // If digit, push to stack
        if (isdigit(ch)) {
            st.push(ch - '0');   // convert char to int
        }
        else {
            // Operator case: Pop two operands
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }

    return st.top();
}

int main() {
    string expr1 = "231*+9-";  // (2 + (3 * 1)) - 9 = -4
    string expr2 = "34+2*";    // (3 + 4) * 2 = 14

    cout << expr1 << " = " << evaluatePostfix(expr1) << endl;
    cout << expr2 << " = " << evaluatePostfix(expr2) << endl;

    return 0;
}
