#include<stdio.h>
#include<stdlib.h> 
int a[6],n=0;
void insert_begin(int d)
{
	if(n==6)
	{
		printf("\n Array Overflow");
		return;
	}
	for(int i=n;i>0;i--)
		a[i]=a[i-1];
	a[0]=d; //Insertion
	n++;
}
void insert_end(int d)
{
	if(n==6)
	{
		printf("\n Array Overflow");
		return;
	}
	a[n++]=d;
}
void insert_pos(int d,int pos)
{
	if(n==6)
		printf("\n Array Overflow");
	else if(pos==1)
		insert_begin(d);
	else if(pos==n+1)
		insert_end(d);
	else if(pos>n)
		printf("\n Position is out of bound");
	else
	{
		for(int i=n;i>=pos;i--)
			a[i]=a[i-1];
		a[pos-1]=d;
		n++;
	}
}
void delete_begin()
{
	if(n==0)
	{
		printf("\n Array Underflow");
		return;
	}
	for(int i=1;i<n;i++)
		a[i-1]=a[i];
	n--;
}
void delete_end()
{
	if(n==0)
	{
		printf("\n Array Underflow");
		return;
	}
	n--;
}
void delete_pos(int pos)
{
	if(n==0)
		printf("\n Array Underflow");
	else if(pos==1)
		delete_begin();
	else if(pos==n)
		delete_end();
	else if(pos>n)
		printf("\n Position is out of bound");
	else
	{
		for(int i=pos;i<n;i++)
			a[i-1]=a[i];
		n--;
	}
}
void display()
{
	if(n==0)
	{
		printf("\n Array is Empty");
		return;
	}
	printf("\n Array elements are : ");
	for(int i=0;i<n;i++)
		printf("%d  ",a[i]);
}
// Menu Driven program -->switch; repeat -->while
void main()
{
	int d, pos,op,ch;
	printf("Enter size of the array 1-6\n");
	scanf("%d", &n);
	printf("Enter your array:\n");
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	while(1)
	{
		int ch;
		printf("\n 1.Insert 2.Delete 3.Display 4.Exit");
		printf("\n Enter your option");
		scanf("%d",&ch);
		switch(ch)
		{
			int d, pos,op;
			case 1: printf("\n Enter new element ");
					scanf("%d",&d);
					printf("\n 1. Beg 2. end 3. pos");
					printf("\n Enter insertion option");
					scanf("%d",&op);
					switch(op)
					{
						case 1: insert_begin(d);
								display();
								break;
						case 2:insert_end(d);
								display(); break;
						case 3: printf("\n Enter postion ");
								scanf("%d",&pos);
								insert_pos(d,pos);
								display();
								break;
					}
					break;
			case 2: printf("\n 1. begin 2. end 3. pos");
					printf("\n Enter deletion option");
					scanf("%d",&op);
					switch(op)
					{
						
						case 1: int pos;
								delete_begin();
								display(); break;
						case 2: delete_end();
								display(); break;
						case 3: printf("\n Enter delete position");
								scanf("%d",&pos);
								delete_pos(pos);
								display();
								break;
					}
					break;
			case 3: display(); break;
			case 4: exit(0);
			default: printf("\n Choice out of bound ");
		}
	}
}	