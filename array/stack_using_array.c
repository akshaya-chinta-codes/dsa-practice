#include<stdio.h>
#include<stdlib.h>
int st[6], top=-1;

void push(int x){
	if(top==5){
		printf("Stack overflow\n"); return;
	}
	st[++top]=x;
}

void pop(){
	if (top==-1){
		printf("Stack Underflow\n"); return;
	}
	printf("\n Deleted element is %d", st[top--]);
}

void display(){
	if (top==-1){
		printf("Stack is empty\n"); return;
	}
	printf("Stack elements are: ");
	for(int i=0; i<=top; i++)
		printf("%d", st[i]);
}

void main(){
	while(1){
		int ch, x;
		printf("1.Push 2.Pop 3.Display 4.Exit");
		printf("Enter your Choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("Enter new element: ");
					scanf("%d", &x);
					push(x); display(); break;
					
			case 2: pop(); display(); break;
			case 3: display(); break;
			case 4: exit(0);
			default: printf("\n Invalid Choice");
		}
	}
}

	