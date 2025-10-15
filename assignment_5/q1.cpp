#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // (a) Insertion at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << val << " inserted at beginning.\n";
    }

    // (b) Insertion at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << val << " inserted at end.\n";
    }

    // (c) Insertion before or after a specific value
    void insertBeforeAfter(int val, int target, bool after = true) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* newNode = new Node(val);

        // Insert before head
        if (!after && head->data == target) {
            newNode->next = head;
            head = newNode;
            cout << val << " inserted before " << target << ".\n";
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && 
              ((after && temp->data != target) || (!after && temp->next->data != target))) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr && !after) {
            cout << "Target node not found.\n";
            delete newNode;
            return;
        }

        if (after) {
            if (temp->data == target) {
                newNode->next = temp->next;
                temp->next = newNode;
                cout << val << " inserted after " << target << ".\n";
            } else {
                cout << "Target node not found.\n";
                delete newNode;
            }
        } else {
            // insert before
            newNode->next = temp->next;
            temp->next = newNode;
            cout << val << " inserted before " << target << ".\n";
        }
    }

    // (d) Deletion from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted from beginning.\n";
        delete temp;
    }

    // (e) Deletion from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == nullptr) {
            cout << head->data << " deleted from end.\n";
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        cout << temp->next->data << " deleted from end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    // (f) Deletion of a specific node
    void deleteNode(int target) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == target) {
            Node* temp = head;
            head = head->next;
            cout << target << " deleted from list.\n";
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != target) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Node " << target << " not found.\n";
            return;
        }
        Node* del = temp->next;
        temp->next = del->next;
        cout << target << " deleted from list.\n";
        delete del;
    }

    // (g) Search for a node
    void searchNode(int target) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == target) {
                cout << target << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << target << " not found in the list.\n";
    }

    // (h) Display all node values
    void displayList() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "List elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, target;
    bool after;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before/after a node\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete specific node\n";
        cout << "7. Search node\n";
        cout << "8. Display list\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Insert after(1) or before(0) the target? ";
                cin >> after;
                list.insertBeforeAfter(val, target, after);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter node value to delete: ";
                cin >> target;
                list.deleteNode(target);
                break;
            case 7:
                cout << "Enter node value to search: ";
                cin >> target;
                list.searchNode(target);
                break;
            case 8:
                list.displayList();
                break;
            case 9:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
