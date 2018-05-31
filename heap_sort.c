#include <stdio.h>
int n=10;
//int heap_size=9;
int parent(int i)
{
	return (i-1)/2;
}
int left(int i)
{
	return 2*i+1;
}
int right(int i)
{
	return 2*i+2;
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void max_heapify(int *arr,int i)
{
	int l=left(i);
	int r=right(i);
	int largest;
	if(l<n && arr[l]>arr[i])
		largest=l;
	else
		largest=i;
	if(r<n && arr[r]>arr[largest])
		largest=r;
	if(largest!=i)
	{
		swap(&arr[largest],&arr[i]);
		max_heapify(arr,largest);
	}
}
void build_max_heap(int *arr)
{
	for(int i=(n/2)-1;i>=0;i--)
		max_heapify(arr,i);
}
void heap_sort(int *arr)
{
	build_max_heap(arr);
	for(int i=n-1;i>0;i--)
	{
		swap(&arr[0],&arr[i]);
		n=n-1;
		max_heapify(arr,0);
	}
}
void print(int *arr)
{
	for(int i=0;i<10;i++)
		printf("%i ",arr[i]);
	printf("\n");
}
int main()
{
	//int n=10;
	int arr[]={4,1,3,2,16,9,10,14,8,7};
	/*int l,r,p;
	l=left(0);
	r=right(0);
	p=parent(10);
	printf("%i\n%i\n%i\n",l,r,p);*/
	print(arr);
	heap_sort(arr);
	print(arr);
	return 0;
}
