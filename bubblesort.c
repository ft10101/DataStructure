
#include<stdio.h>
int bubbleSort(int arr[], int  n)
{
	int temp;
	for(int k=0; k<n-1; k++)
	{
		for(int l=0; l<n-1-k; l++)
		{
			if(arr[l]>arr[l+1])
			{
				temp = arr[l];
				arr[l] = arr[l+1];
				arr[l+1] =temp;
			}
		}
	}
}

int main()
{
	int arr[10];

	printf("Enter 10 elements: \n");
		for(int i=0; i<10; i++)
			scanf("%d", &arr[i]);
	printf("\nUnsorted array is: ");
		for(int j=0;  j<10; j++)
			printf("%d ", arr[j]);

	bubbleSort(arr, 10);

        printf("\nSorted array is: ");
                for(int j=0;  j<10; j++)
                        printf("%d ", arr[j]);
}
