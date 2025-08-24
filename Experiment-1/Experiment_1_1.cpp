#include <iostream>
using namespace std;

template <class T>
class Stack {
    int top;
    int capacity;
    T *arr;

public:
    Stack(int size) {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }
    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(T x) {
        if (isFull()) {
            cout << "Stack Overflow!" << x << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed into stack" << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << arr[top--] << " popped from stack" << endl;
    }
    T peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return arr[top];
    }
    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack<int> s(5);   
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element is: " << s.peek() << endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop(); 
    if (s.isEmpty())
        cout << "Stack is empty now" << endl;

    return 0;
}
