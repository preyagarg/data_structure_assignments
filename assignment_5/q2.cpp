#include <iostream>
#include <list>
#include <algorithm> // for count
using namespace std;

int main() {
    list<int> l;

    // Example input: 1->2->1->2->1->3->1
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        l.push_back(arr[i]);

    cout << "Original Linked List: ";
    for (int val : l)
        cout << val << " ";
    cout << endl;

    int key = 1;

    // Count occurrences
    int countKey = count(l.begin(), l.end(), key);
    cout << "Count of " << key << ": " << countKey << endl;

    // Delete all occurrences
    l.remove(key);

    cout << "Updated Linked List: ";
    for (int val : l)
        cout << val << " ";
    cout << endl;

    return 0;
}
