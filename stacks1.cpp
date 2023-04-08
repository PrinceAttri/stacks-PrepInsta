#include <iostream>
#include <climits>
using namespace std;

// A structure to represent a stack
struct Stack {
    int top;
    int maxSize;
    int* arr;
};

struct Stack* create(int max){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack*));
    stack->top = -1;
    stack->maxSize = max;
    stack->arr = (int*)malloc(stack->maxSize * sizeof(int));
    //here above memory for array is being created
    // size would be 10*4 = 40
    return stack;
}

// Checking with this function is stack is full or not
// Will return true is stack is full else false
//Stack is full when top is equal to the last index
bool isFull(struct Stack* stack) {
    if(stack->top == stack->maxSize - 1){
        cout << "Maximum size reached!" << endl;
    }
    return stack->top == stack->maxSize-1;
}

// By definition the Stack is empty when top is equal to -1
// Will return true if top is -1
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push function here, inserts value in stack and increments stack top by 1
int push(struct Stack* stack, int item) {
    if(isFull(stack)) {
        return 0;
    }
    stack->arr[++stack->top] = item;
    cout << "Item " << item << " has been pushed to the stack!" << endl;
}

// Function to remove an item from the stack. It decreases top by 1
int pop(struct Stack* stack) {
    if(isEmpty(stack)) {
        return INT_MIN;
    }
    return stack->arr[stack->top--];
}

// Function to return the top from stack without removing it
int peek(struct Stack* stack) {
    if(isEmpty(stack)) {
        return INT_MIN;
    }
    return stack->arr[stack->top];
}

int size(struct Stack* stack) {
    return stack->top + 1;
}

int main() {
    struct Stack* stack = create(5);

    push(stack, 5);
    push(stack, 15);
    push(stack, 20);
    push(stack, 25);

    cout << peek(stack) << endl;
    cout << size(stack) << endl;
    cout << pop(stack) << endl;
    cout << size(stack) << endl;
    push(stack, 30);
    push(stack, 35);
    push(stack, 40);
    cout << isFull(stack) << endl;
    cout << isEmpty(stack) << endl;
}
