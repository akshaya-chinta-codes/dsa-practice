#include<stdio.h>
void merge(int a[], int low, int high, int mid)
{
	int i=low,j=mid+1,k=0;
	int res[high-low+1];
	while(i<=mid && j<=high)
	{
		if(a[i]<=a[j])
			res[k] = a[i++];
		else
			res[k] = a[j++];
		k++;
	}
	// Remaining elts left in left part
	while(i<=mid)
		res[k++] = a[i++];
	// right part 
	while(j<=high)
		res[k++] = a[j++];
	for(k=0,i=low;i<=high;i++)
		a[i]=res[k++];
}
void mergesort(int a[],int low, int high)
{
	if(low < high)
	{
		
		int mid = (low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,high,mid);
	}	
}
void main()
{
	int n;
	printf("\n Enter the size of the array");
	scanf("%d",&n);
	int a[n];
	printf("\n Enter array elements");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\n Array elements before sorting");
	for(int i=0;i<n;i++)
		printf("%d  ",a[i]);
	mergesort(a,0,n-1);  // a-array   0 - low n-1 -> high
	printf("\n Array elements after sorting");
	for(int i=0;i<n;i++)
		printf("%d  ",a[i]);
	
}