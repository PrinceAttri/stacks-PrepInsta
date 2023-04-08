#include <iostream>
using namespace std;

#define size 20
int stack[size], top;

void push(int stack[], int item) {
    if(top == size-1) {
        cout << "Stack is full!" << endl;
        return;
    }
    top++;
    stack[top] = item;
}

void pop(int stack[]) {
    int del_item;
    if(top == -1) {
        cout << "Empty stack!" << endl;
        return;
    }
    del_item = stack[top];
    top--;
    cout << "Item deleted is: " << del_item;
    return;
}

void peek(int stack[]) {
    if(top == -1) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Top of stack is: " << stack[top] << endl;
}

void display(int stack[], int top) {
    if(top == -1) {
        cout << "Stack is empty!" << endl;
        return;
    }
    for(int i = top; i>=0; i--) {
        cout << stack[i] << " " << endl;
    }
}

int main() {
    int top = -1;
    int option;
    int item;

    while(1) {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch(option) {
            case 1:
                cout << "Enter the item to be inserted: ";
                cin >> item;
                push(stack, item);
                break;

            case 2:
                pop(stack);
                break;

            case 3:
                peek(stack);
                break;
            
            case 4:
                display(stack, top);
                break;
            
            case 5:
                exit(0);
            
            default:
                cout << "Enter a valid selection!" << endl;
                break;
        }
    }
}
