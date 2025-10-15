#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int front, rear, size;

public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int x) {
        if (rear >= 99) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[++rear] = x;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int val = arr[front++];
        size--;
        return val;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    int peek() {
        if (!isEmpty())
            return arr[front];
        return -1;
    }

    void display() {
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

class QueueInterleaver {
public:
    void interleave(Queue &q) {
        int n = q.getSize();
        if (n <= 1) return;

        int half = n / 2;
        Queue q1, q2;

        // Split into two halves
        for (int i = 0; i < half; i++) {
            q1.enqueue(q.dequeue());
        }
        while (!q.isEmpty()) {
            q2.enqueue(q.dequeue());
        }

        // Interleave q1 and q2 back into original queue
        while (!q1.isEmpty() || !q2.isEmpty()) {
            if (!q1.isEmpty()) q.enqueue(q1.dequeue());
            if (!q2.isEmpty()) q.enqueue(q2.dequeue());
        }
    }
};

int main() {
    Queue q;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.enqueue(val);
    }

    cout << "Original queue: ";
    q.display();

    QueueInterleaver inter;
    inter.interleave(q);

    cout << "Interleaved queue: ";
    q.display();

    return 0;
}
