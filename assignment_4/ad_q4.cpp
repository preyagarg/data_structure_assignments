#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
   
    queue<int> students;
    stack<int> sandwiches;

   
    int studentPrefs[] = {1, 1, 0, 0};
    int n = sizeof(studentPrefs) / sizeof(studentPrefs[0]);
    for (int i = 0; i < n; i++)
        students.push(studentPrefs[i]);

    
    int sandwichStack[] = {0, 1, 0, 1};
    for (int i = n - 1; i >= 0; i--) 
        sandwiches.push(sandwichStack[i]);

    int count = 0; 
    while (!students.empty() && count < students.size()) {
        if (students.front() == sandwiches.top()) {
            
            students.pop();
            sandwiches.pop();
            count = 0; 
        } else {
            
            int s = students.front();
            students.pop();
            students.push(s);
            count++;
        }
    }

    cout << "Number of students unable to eat: " << students.size() << endl;

    return 0;
}
