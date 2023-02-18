
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;
};

int main()
{
	int num, num1;

	struct node* head = (struct node*)malloc(sizeof(struct node));
	printf("Enter data for first node: \n");
	scanf("%d", &num);
	head->data = num;
	head->link = NULL;

	printf("Enter the number for 2nd node: \n");
	scanf("%d", &num1);
	struct node* current = (struct node*)malloc(sizeof(struct node));
	current->data = num1;
	current->link = NULL;

	head->link = current;

	printf("Linkedlist: ");

	struct node* temp = head;

	int count=0;

	while(temp != NULL)
	{
		count++;
		printf("%d ", temp->data);
		temp = temp->link;

	}

	printf("\nNumber of nodes in linkedlist: %d", count);
	return 0;
}
