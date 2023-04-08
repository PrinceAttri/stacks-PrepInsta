#include <iostream>
#include <climits>
using namespace std;

class Stack {
    int top;
    int max;
    int* arr;

    public:
        Stack(int size) {
            top = -1;
            max = size;
            arr = new int [max]; //dynamic memory allocation of a which is equal to the value of max
        }
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
        bool isFull();
        void display();
};

bool Stack::push(int x) {
    if(top >= (max-1)) {
        cout << "Stack is full!" << endl;
        return false;
    }
    else {
        arr[++top] = x;
        cout << x << " pushed into stack!" << endl;
        return true;
    }
}

int Stack::pop() {
    if(top < 0) {
        cout << "Stack is empty" << endl;
        return 0;
    }
    else {
        int num = arr[top--];
        cout << "Value popped: " << num << endl;
    }
}

int Stack::peek() {
    if(top < 0) {
        cout << "Stack is empty!" << endl;
        return 0;
    }
    else {
        int num = arr[top];
        cout << "Value when peek is done: " << num << endl;
    }
}

bool Stack::isFull() {
    return(top == max-1);
}

bool Stack::isEmpty() {
    return(top < 0);
}

void Stack::display() {
    if(isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }
    else {
        cout << "Stack: ";
        for(int i = top; i>=0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    class Stack s(5);
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.push(25);
    s.display();
    s.peek();
    s.push(30);
    s.pop();
    s.peek();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    return 0;
}