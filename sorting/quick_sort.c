#include<stdio.h>
int partition(int a[],int low,int high)
{
	int pivot=low,i=low+1,j=high;
	while(i<=j)
	{
		while(a[i]<=a[pivot])
			i++;
		while(a[j]>a[pivot])
			--j;
		if(i<j)
		{
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	int t=a[pivot];
	a[pivot]=a[j];
	a[j]=t;
	return j;
}
void quicksort(int a[],int low, int high)
{
	if(low<high)
	{
		int j = partition(a,low,high);
		quicksort(a,low,j-1);
		quicksort(a,j+1,high);
	}
}
void main()
{
	int n;
	printf("\n Enter the size of the array");
	scanf("%d",&n);
	int a[n];
	printf("\n enter array elements");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\n Elements of the array before sorting ");
	for(int i=0;i<n;i++)
		printf("%d  ",a[i]);
	quicksort(a,0,n-1);  // a-> array 0 -> low  n-1->high
	printf("\n Elements of the array after sorting ");
	for(int i=0;i<n;i++)
		printf("%d  ",a[i]);
}