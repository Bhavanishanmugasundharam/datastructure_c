#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

int dequeue() {
    if (front == NULL) return -1;
    struct Node* temp = front;
    int value = temp->data;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return value;
}

int peek() {
    if (front == NULL) return -1;
    return front->data;
}

int isEmpty() {
    return front == NULL;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("Front: %d\n", peek());
    printf("Dequeued: %d\n", dequeue());
    printf("Front after dequeue: %d\n", peek());
    return 0;
}
