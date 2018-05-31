//merge sort procedure new
#include <stdio.h>
#define INFINITE 10000;
void merge(int *a,int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int L[n1+1];
	int R[n2+1];
	for(int i=0;i<n1;i++)
	{
		L[i]=a[p+i];
	}
	for(int i=0;i<n2;i++)
	{
		R[i]=a[q+i+1];
	}
	L[n1]=INFINITE;
	R[n2]=INFINITE;
	int i=0;
	int j=0;
	for(int k=p;k<=r;k++)
	{
		if(L[i]<R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
	}
}
void merge_sort(int *a,int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
	}
}
void print(int *arr,int n)
{
	for(int i=0;i<n;i++)
		printf("%i ",arr[i]);
	printf("\n");
}
int main()
{
	int n=8;
	int arr[]={8,8,6,6,4,4,2,2};
	print(arr,n);
	merge_sort(arr,0,n-1);
	print(arr,n);
	return 0;
}
