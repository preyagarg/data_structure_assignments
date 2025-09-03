#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
private:
    int arr[SIZE];
    int front, end;

public:
    Queue() {
        front = -1;
        end = -1;
    }

    int isEmpty() {
        return front == -1;
    }

    int isFull() {
        return end == SIZE - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        end++;
        arr[end] = value;
        cout << value << " enqueued to queue.\n";
    }

    void dequeue() 
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        cout << arr[front] << " dequeued from queue.\n";
        if (front == end) {
            front = end = -1;
        } else {
            front++;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Front element is: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= end; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue Operations Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Check if Empty\n6. Check if Full\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                if (q.isEmpty())
                    cout << "Queue is empty.\n";
                else
                    cout << "Queue is not empty.\n";
                break;
            case 6:
                if (q.isFull())
                    cout << "Queue is full.\n";
                else
                    cout << "Queue is not full.\n";
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
