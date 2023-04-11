
#include <stdio.h>
#include <stdlib.h>
struct Node {  // define a node in the linked list
    int data;
    struct Node* next;
};
struct Node* newNode(int data) { // function to create a new node
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
// function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* node = newNode(data);
    node->next = *head;
    *head = node;
    printf("%d inserted successfully at the beginning.\n", data);
}
// function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* node = newNode(data);
    if (*head == NULL) {
        *head = node;
        printf("%d inserted successfully at the end.\n", data);
        return; }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
    printf("%d inserted successfully at the end.\n", data);
}
// function to delete a node with given data from the linked list
void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d not found in the linked list.\n", data);
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("%d deleted successfully from the linked list.\n", data);
}
// function to search for a node with given data in the linked list
void searchNode(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d not found in the linked list.\n", data);
    } else {
        printf("%d found in the linked list.\n", data);
    }
}
// function to print the linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    printf("Linked list: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// main function to test the linked list operations
int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    printList(head);
    searchNode(head, 3);
    searchNode(head, 6);
    deleteNode(&head, 3);
    deleteNode(&head, 6);
    printList(head);
    return 0;
}
