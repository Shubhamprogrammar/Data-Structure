#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
		this->data=val;
		this->next=NULL;
	}
};

class CircularLinkedList {
private:
    Node* tail;
public:
    CircularLinkedList() : tail(NULL) {}

    // Method to insert a node at the end of the circular linked list
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            // List is empty
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Method to delete a node with a given value
    void deleteNode(int val) {
        if (!tail) {
            cout << "List is empty." << endl;
			 return;
        }

        Node* current = tail->next;
        Node* prev = tail;

        // If the list contains only one node and that node is to be deleted
        if (current == tail && current->data == val) {
            delete current;
            tail = NULL;
            return;
        }

        do {
            if (current->data == val) {
                prev->next = current->next;
                if (current == tail) {
                    tail = prev;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != tail->next);

        cout << "Node with value " << val << " not found." << endl;
    }

    // Method to display the circular linked list
    void display() const {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
}
        Node* temp = tail->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display(); // Output: 10 20 30

    list.deleteNode(20);
    list.display(); // Output: 10 30

    list.deleteNode(40); // Output: Node with value 40 not found.
}
