#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expr) {
    stack<char> st; //st=

    for (char ch : expr) {
        // If opening bracket → push into s          //{    )           (          }tack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            // Check matching type
            if ((ch == ')' && top != '(') ||  (ch == '}' && top != '{') ||  (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // At the end, stack must be empty
    return st.empty();
}

int main() {
    string expr1 = "{[()]}";   // Balanced
    string expr2 = "{[(])}";   // Not Balanced
    string expr3 = "((()))";   // Balanced
    string expr4 = "(()";      // Not Balanced

    cout << expr1 << " -> " << (isBalanced(expr1) ? "Balanced" : "Not Balanced") << endl;
    cout << expr2 << " -> " << (isBalanced(expr2) ? "Balanced" : "Not Balanced") << endl;
    cout << expr3 << " -> " << (isBalanced(expr3) ? "Balanced" : "Not Balanced") << endl;
    cout << expr4 << " -> " << (isBalanced(expr4) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}
