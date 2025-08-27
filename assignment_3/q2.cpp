#include <iostream>
#include <stack>
using namespace std;

string reverseString(string str) {
    stack<char> st;

    // Push all characters of the string into the stack
    for (char ch : str) {
        st.push(ch);
    }

    // Pop characters from the stack and add to result
    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }

    return reversed;
}

int main() {
    string str = "DataStructure";
    cout << "Original String: " << str << endl;
    cout << "Reversed String: " << reverseString(str) << endl;
    return 0;
}
