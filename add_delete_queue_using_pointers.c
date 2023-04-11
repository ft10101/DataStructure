
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
void enqueue(int element) { // func to add an element to the queue
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;
    if (front == NULL && rear == NULL) {
        front = rear = newNode;
        return; }
    rear->next = newNode;
    rear = newNode;
}
void dequeue() { // func to remove an element from the queue
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;  }
    struct Node* temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;   }
    printf("%d dequeued from queue.\n", temp->data);
    free(temp);
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    return 0;
}
