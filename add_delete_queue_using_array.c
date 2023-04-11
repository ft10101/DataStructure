
#include <stdio.h>
#define MAX_SIZE 100
int queue[MAX_SIZE], front = -1, rear = -1;
void enqueue(int element) { // func to add an element to the queue
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full.\n");
    } else {
        if (front == -1) {
            front = 0;   }
        rear++;
        queue[rear] = element;
        printf("%d enqueued to queue.\n", element);}
}
void dequeue() { // func to remove an element from the queue
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        int dequeuedElement = queue[front];
        front++;
        printf("%d dequeued from queue.\n", dequeuedElement); }
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
    return 0;
}
