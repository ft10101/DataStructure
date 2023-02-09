
#include<stdio.h>
int main(){

int size = 7, a[size];
int i,j,min, temp;

printf("Enter 7 Numbers to perform selection sort:\n");
for(i=0; i<size ;i++)
	scanf("%d",&a[i]);

printf("\nBEFORE SELECTION SORT:\n");
        for(i=0 ; i<size ; i++)
                printf("%d\t", a[i]);

for(i=0; i<size-1; i++){
	min = i;
	for(j=i+1; j<size; j++){
		if(a[j] < a[i])
		{
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
}

printf("\nAFTER SELECTION SORT:\n");
	for(i=0 ; i<size ; i++)
		printf("%d\t", a[i]);

}
