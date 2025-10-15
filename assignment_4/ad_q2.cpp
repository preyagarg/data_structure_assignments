#include <iostream>
#include <queue>
#include <climits>
using namespace std;

void sortQueue(queue<int> &q) 
{
    int n = q.size();
  
    for (int i = 0; i < n; i++)
      {
        int minVal = INT_MAX;
        int size = q.size();

 
        for (int j = 0; j < size; j++) 
        {
            int curr = q.front();
            q.pop();

            if (curr < minVal && j < size - i) 
            {
                minVal = curr;
            }
            q.push(curr);
        }

       
        bool minPlaced = false;
        for (int j = 0; j < size; j++) 
        {
            int curr = q.front();
            q.pop();
            if (curr == minVal && !minPlaced) 
            {
                q.push(curr); 
                minPlaced = true;
            }
            else 
            {
                q.push(curr);
            }
        }
    }
}

int main() {
    queue<int> q;
    int arr[] = {11, 5, 4, 21};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        q.push(arr[i]);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    sortQueue(q);

    cout << "Sorted Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
