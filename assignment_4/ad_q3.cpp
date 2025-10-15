#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool canBeSorted(queue<int> q) {
    stack<int> s;
    int expected = 1;
    queue<int> output;

    while (!q.empty() || !s.empty()) {
        if (!q.empty() && q.front() == expected) {
            output.push(q.front());
            q.pop();
            expected++;
        }
        else if (!s.empty() && s.top() == expected) {

            output.push(s.top());
            s.pop();
            expected++;
        }
        else if (!q.empty()) {

            s.push(q.front());
            q.pop();
        }
        else {
          
            return false;
        }
    }

    return true;
}

int main() {
    queue<int> q;
    int arr[] = {5, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        q.push(arr[i]);

    if (canBeSorted(q))
        cout << "Yes, the queue can be arranged in increasing order.\n";
    else
        cout << "No, it cannot be arranged in increasing order.\n";

    return 0;
}
