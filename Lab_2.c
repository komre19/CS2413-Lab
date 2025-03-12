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

///////////// 225
// CS-2413
// Renard Kombo
// R11786591
// 225 Implementation of stack using queue

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//  queue structure
typedef struct {
    int* data;
    int front, rear, size, capacity;
} Queue;

// new  queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->data = (int*)malloc(capacity * sizeof(int));
    return queue;
}
// queue operations
bool isEmpty(Queue* queue) { return queue->size == 0; }

void enqueue(Queue* queue, int x) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = x;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) return -1;
    int item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

typedef struct {
    Queue* q1;
    Queue* q2;
} MyStack;

// new stack
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1 = createQueue(100);
    stack->q2 = createQueue(100);
    return stack;
}
void myStackPush(MyStack* obj, int x) {
    enqueue(obj->q2, x);  
    while (!isEmpty(obj->q1)) {  
        enqueue(obj->q2, dequeue(obj->q1));
    }
    // Swap q1 and q2
    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

int myStackPop(MyStack* obj) {
    return dequeue(obj->q1);
}

int myStackTop(MyStack* obj) {
    return obj->q1->data[obj->q1->front];
}
// check if stack is empty
bool myStackEmpty(MyStack* obj) {
    return isEmpty(obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj->q1->data);
    free(obj->q2->data);
    free(obj->q1);
    free(obj->q2);
    free(obj);
}
int main() {
    MyStack* myStack = myStackCreate();

    myStackPush(myStack, 1);
    myStackPush(myStack, 2);
    printf("%d\n", myStackTop(myStack)); 
    printf("%d\n", myStackPop(myStack)); 
    printf("%d\n", myStackEmpty(myStack)); 

    myStackFree(myStack);
    return 0;
}


