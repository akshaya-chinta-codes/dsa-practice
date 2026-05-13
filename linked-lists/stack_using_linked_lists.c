#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int d){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = d;
    p->next = top;
    top = p;
}

void pop(){
    if(top == NULL){                  // Fix 1: was (top == -1)
        printf("Stack underflow\n"); return;
    }
    struct Node* temp = top;          // Fix 2: save pointer before moving
    top = top->next;
    free(temp);                       // Fix 2: free the popped node
}

void display(){
    if(top == NULL){
        printf("Stack is empty\n"); return;
    }
    printf("Stack elements are: ");
    struct Node* p = top;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");                     // Fix 4: newline at end of output
}

int main(){                           // Fix 3: was void main()
    while(1){
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        int choice; scanf("%d", &choice);
        switch(choice){
            case 1: {
                int d; printf("Enter data to push: ");
                scanf("%d", &d); push(d); break;
            }
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}