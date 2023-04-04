#include<stdio.h>
#define n 5

int stack[n];
int top = -1;

void push()
{
	int num;
	printf("Enter the number: ");
	scanf("%d", &num);

	if(top == n-1)
	{
		printf("\nOverflow\n");
		return;
	}
	else
	{
		top++;
		stack[top] = num;
	}
}

void pop()
{
	if(top == -1)
	{
		printf("\nStack underflow / EMPTY\n");
		return;
	}
	else
	{
		printf("Element poped: %d \n", stack[top]);
		top--;
	}
}

int main()
{
	char choice;
	while(1)
	{
		printf("ADD number in stack (Y/y) or delete? (N/n):");
		scanf(" %c",&choice);

		if(choice == 'y' || choice == 'Y')
		{
			push();
			continue;
		}
		else if (choice == 'n' || choice =='N')
		{
			pop();
			continue;
		}
	}
}
