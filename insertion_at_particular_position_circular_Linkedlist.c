
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* addToEmpty(int data)
{
	struct node* temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->next = temp;
	return temp;
}

struct node* addAtBegin(struct node* tail, int data)
{
	struct node* newP  = malloc(sizeof(struct node));
	newP->data = data;
	newP->next = tail->next;
	tail->next = newP;
	return tail;
}

struct node* addAtEnd(struct node* tail, int data)
{
	struct node* newP = malloc(sizeof(struct node));
	newP->data = data;
	newP->next = NULL;

	newP->next = tail->next;
	tail->next = newP;
	tail = tail->next;
	return tail;
}

void print(struct node* tail)
{
	struct node* p = tail->next;
	do
	{
		printf("%d ", p->data);
		p = p->next;
	}while(p!=tail->next);
}
// add at a particular given position
struct node* addAfterPos(struct node* tail, int data, int pos)
{
	struct node* p = tail->next;
	struct node* newP = malloc(sizeof(struct node));
	newP->data = data;
	newP->next = NULL;

	while(pos > 1)
	{
		p = p->next;
		pos--;
	}
	newP->next = p->next;
	p->next = newP;
	if(p == tail)
	{
		tail = tail->next;
	}
	return tail;
}


int main(){

	struct node* tail;
	printf("Adding a number: 10\n");
	tail = addToEmpty(10);
	printf("Add at begin: 20\n");
	tail = addAtBegin(tail, 20);
	printf("Add at end: 30\n");
	tail = addAtEnd(tail,30);

	printf("LinkedList: ");
	print(tail);

	printf("\n\nAdd an element 66 after 2nd position\n");
	tail = addAfterPos(tail, 66, 2);
	printf("LinkedList: ");
	print(tail);
	return 0;
}
