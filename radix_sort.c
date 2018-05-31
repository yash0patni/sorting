#include <stdio.h>
int range=10;

void print(int *arr,int n)
{
	for(int i=0;i<n;i++)
		printf("%i ",arr[i]);
	printf("\n");
}
void countsort(int *arr,int n,int place)
{
	int i,freq[range];
	for(i=0;i<range;i++)
		freq[i]=0;         
	//range for integers is 10 as digits range from 0-9
	int output[n];
	for(i=0;i<n;i++)
		freq[(arr[i]/place)%range]++;
	printf("\n*******************\n");
	print(freq,range);
	for(i=1;i<range;i++)
		freq[i]+=freq[i-1];
	
	print(freq,range);
	
	for(i=n-1;i>=0;i--)
	{
		output[freq[(arr[i]/place)%range]-1]=arr[i];
		freq[(arr[i]/place)%range]--;
	}
	print(freq,range);
	printf("*******************\n");
	for(i=0;i<n;i++)
		arr[i]=output[i];
}
void radixsort(int *arr,int n,int maxx) 
//maxx is the maximum element in the array
{
	printf("*Initial --*\n");
	print(arr,n);
	printf("\n");
	int mul=1;
	while(maxx)
	{
		countsort(arr,n,mul);
		mul*=10;
		maxx/=10;
		print(arr,n);
	}
	printf("\n*Final --*\n");
	print(arr,n);
}
int main()
{
	int arr[]={10,21,17,34,44,11,654,123};
	int n=8;
	radixsort(arr,n,654);
	return 0;
}
