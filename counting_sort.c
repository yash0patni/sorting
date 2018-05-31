#include <stdio.h>
void print(int *arr,int n)
{
	for(int i=0;i<n;i++)
		printf("%i ",arr[i]);
	printf("\n");
}
void counting_sort(int *arr,int *sarr,int n)
{
	int max=arr[0];
	for(int i=0;i<n;i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	int freq[max+1];
	for(int i=0;i<=max;i++)
		freq[i]=0;
	for(int i=0;i<n;i++)
		freq[arr[i]]++;
	int j=0;
	for(int i=0;i<=max;i++)
	{
		int c=freq[i];
		while(c--)
		{
			sarr[j++]=i;
		}
	}
}
int main()
{
	int n=10;
	int arr[]={7,3,2,5,6,4,2,7,4,1};
	int sarr[n];
	print(arr,n);
	counting_sort(arr,sarr,n);
	print(sarr,n);
	return 0;
}
