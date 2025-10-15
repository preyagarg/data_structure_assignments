#include <iostream>
#include <list>
using namespace std;

int main() {
    // Example input: 1->2->3->4
    list<int> l = {1, 2, 3, 4};

    cout << "Original Linked List: ";
    for (int val : l)
        cout << val << "->";
    cout << "NULL" << endl;

    // Reverse the list
    l.reverse();

    cout << "Reversed Linked List: ";
    for (int val : l)
        cout << val << "->";
    cout << "NULL" << endl;

    return 0;
}
