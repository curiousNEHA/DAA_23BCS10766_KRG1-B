#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
    Node* tail;

public:
    CircularLinkedList() {
        tail = NULL;
    }

    void insertBegin(int value) {
        Node* newNode = new Node(value);
        if (tail == NULL) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (tail == NULL) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void deleteBegin() {
        if (tail == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* head = tail->next;
        if (head == tail) {
            delete head;
            tail = NULL;
        } else {
            tail->next = head->next;
            delete head;
        }
    }

    void deleteEnd() {
        if (tail == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = tail->next;
        if (temp == tail) {
            delete tail;
            tail = NULL;
        } else {
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = tail->next;
            delete tail;
            tail = temp;
        }
    }

    void display() {
        if (tail == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = tail->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(back to head)" << endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertBegin(10);
    cll.insertEnd(20);
    cll.insertBegin(5);
    cll.insertEnd(30);
    cout << "Circular Linked List: ";
    cll.display();
    cll.deleteBegin();
    cll.deleteEnd();
    cout << "After deletion: ";
    cll.display();

    return 0;
}
