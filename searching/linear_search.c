#include<stdio.h>
int linearsearch(int a[], int n, int key)
{
	for(int i=0; i<n; i++) //iterations
	{
		if(a[i]==key) //match
			return i+1; 
	}
	return -1; //search was unsuccesful
}
void main()
{
	int n, key=0, a[10], i;
	//Reading number of elements
	printf("\nEnter the number of the elements:\n");
	scanf("%d", &n);
	//Reading elements
	printf("Enter array of elements:\n");
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
	printf("Enter the element to be searched:\n");
	scanf("%d", &key);
	int res=linearsearch(a, n, key);
	if(res!=-1)
	{
		printf("Search is successful\n");
		printf("Key is found at %d position", res);
	}
	else
		printf("Search is unsuccesful\nElement not found");
}