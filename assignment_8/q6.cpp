#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> heap; // Using vector to store heap elements

    // Function to maintain heap property (for insertion)
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    // Function to maintain heap property (for deletion)
    void heapifyDown(int index) {
        int size = heap.size();
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Insert element into the priority queue
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    // Remove highest priority element
    void pop() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // Get highest priority element
    int top() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        return heap[0];
    }

    // Check if empty
    bool empty() {
        return heap.empty();
    }

    // Display all elements
    void display() {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);

    cout << "Priority Queue (Heap): ";
    pq.display();

    cout << "Top element (Highest priority): " << pq.top() << endl;

    pq.pop();
    cout << "After removing top element: ";
    pq.display();

    return 0;
}
