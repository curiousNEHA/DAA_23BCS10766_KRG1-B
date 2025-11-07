#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }
    void insertBegin(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteBegin() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        else tail = NULL;
        delete temp;
    }

    void deleteEnd() {
        if (tail == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = NULL;
        else head = NULL;
        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertBegin(10);
    dll.insertEnd(20);
    dll.insertBegin(5);
    dll.insertEnd(30);

    cout << "Doubly Linked List: ";
    dll.display();

    dll.deleteBegin();
    dll.deleteEnd();

    cout << "After deletion: ";
    dll.display();

    return 0;
}
