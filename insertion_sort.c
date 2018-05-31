#include <stdio.h>
void print(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%i ",arr[i]);
	}
	//printf("\n");
}
int insertion_sort(int *arr,int n)
{
	int tswaps=0;
	for(int i=1;i<n;i++)
	{
		int swaps=0;
		int key=arr[i];
		int j=i-1;
		while(j>=0&&arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
			swaps++;
		}
		arr[j+1]=key;
		print(arr,n);
		printf("  --swap: %i\n",swaps);
		tswaps+=swaps;
	}
	return tswaps;
}
int main()
{
	int n=6;
	int arr[]={5,2,4,6,1,3};
	printf("Unsorted Array: ");
	print(arr,n);
	printf("\n");
	int swaps=insertion_sort(arr,n);
	printf("Total Swaps: %i\n",swaps);
	printf("Sorted Array: ");
	print(arr,n);
	printf("\n");
	return 0;
}
