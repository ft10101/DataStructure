#include<stdio.h>

int linearSearch( int arr[], int size, int element)
{
	for (int i = 0; i < size; i++)
	{
		if(arr[i]==element)
		{
			return i;
		}
	}
	return -1;
}


int main()
{
	int arr[] = {1,2,12,1221,121,23,3,22,24,34,55};
	int size = sizeof(arr)/sizeof(int);
	int element;

	printf("Enter the element you want to search by using linear searching algorithm: \n");
	scanf("%d", &element);

	int searchIndex = linearSearch(arr,size,element);

	if(searchIndex == -1)
		printf("Element not found\n");
	else
		printf("The element %d was found at index %d \n", element, searchIndex);
	return 0;
}
