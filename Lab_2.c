// CS-2413
// Renard Kombo
// R11786591
// 232 Implementation of queue using stacks

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// stack definition
typedef struct {
    int* data;
    int top;
    int capacity; // maximum of the stack
} Stack;

// create new stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*)malloc(capacity * sizeof(int));
    return stack;
}
// check 
bool isEmpty(Stack* stack) { return stack->top == -1; }
void push(Stack* stack, int x) { stack->data[++stack->top] = x; }
int pop(Stack* stack) { return stack->data[stack->top--]; }
int peek(Stack* stack) { return stack->data[stack->top]; }

typedef struct {
    Stack* stack1;
    Stack* stack2;
} MyQueue;

// create new queue
MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->stack1 = createStack(100); // stack 1 == push new elements
    queue->stack2 = createStack(100); // stack 2 == popping and peeking elements
    return queue;
}
void myQueuePush(MyQueue* obj, int x) {
    push(obj->stack1, x);
}
int myQueuePop(MyQueue* obj) {
    if (isEmpty(obj->stack2)) {
        while (!isEmpty(obj->stack1)) {
            push(obj->stack2, pop(obj->stack1));
        }
    }
    return pop(obj->stack2);
}
int myQueuePeek(MyQueue* obj) {
    if (isEmpty(obj->stack2)) {
        while (!isEmpty(obj->stack1)) {
            push(obj->stack2, pop(obj->stack1));
        }
    }
    return peek(obj->stack2);
}
// check if queue is empty 
bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj->stack1) && isEmpty(obj->stack2);
}
//  space for memory
void myQueueFree(MyQueue* obj) {
    free(obj->stack1->data);
    free(obj->stack2->data);
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}

// Testing the queue
int main() {
    MyQueue* myQueue = myQueueCreate();
    myQueuePush(myQueue, 1);
    myQueuePush(myQueue, 2);
    printf("%d\n", myQueuePeek(myQueue)); 
    printf("%d\n", myQueuePop(myQueue));  
    printf("%d\n", myQueueEmpty(myQueue));
    myQueueFree(myQueue);
    return 0;
}

