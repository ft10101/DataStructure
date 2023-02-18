
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

void print(struct node* tail)
{
	struct node* p = tail->next;
	do
	{
		printf("%d ", p->data);
		p = p->next;
	}while(p!=tail->next);
}

int main(){

	struct node* tail;
	printf("Adding a number: 10\n");
	tail = addToEmpty(10);
	printf("Adding at begin: 20\n");
	tail = addAtBegin(tail, 20);

	print(tail);
	return 0;
}
