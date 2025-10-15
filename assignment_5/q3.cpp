#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = {1, 2, 3, 4, 5}; // Example input

    cout << "Linked List: ";
    for (int val : l)
        cout << val << " ";
    cout << endl;

    // Find middle element using iterator
    int n = l.size();
    auto it = l.begin();
    advance(it, n / 2); // move iterator to middle (0-based index)

    cout << "Middle element: " << *it << endl;

    return 0;
}
