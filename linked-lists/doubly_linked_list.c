#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;
void insert_begin(int d)
{
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->data = d;
    p->prev = NULL;
    p->next = head;
    if (head != NULL)
        head->prev = p;
    head = p;
}
void insert_end(int d)
{
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->data = d;
    p->next = NULL;
    if (head == NULL)
    {
        p->prev = NULL;
        head = p;
        return;
    }
    struct Node *q = head;
    while (q->next != NULL)
        q = q->next;
    q->next = p;
    p->prev = q;
}
void insert_pos(int d, int pos)
{
    if (pos == 1)
    {
        insert_begin(d);
        return;
    }
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->data = d;
    struct Node *q = head;
    int c = 1;
    while (c < pos - 1 && q != NULL)
    {
        c++;
        q = q->next;
    }
    if (q == NULL)
    {
        printf("\n Position is out of bound");
        free(p);
        return;
    }
    p->next = q->next;
    p->prev = q;
    if (q->next != NULL)
        q->next->prev = p;   // update next node's prev pointer
    q->next = p;
}
void delete_begin()
{
    if (head == NULL)
    {
        printf("\n DLL Underflow");
        return;
    }
    struct Node *q = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;   // new head has no previous node
    free(q);
}
void delete_end()
{
    if (head == NULL)
    {
        printf("\n DLL Underflow");
        return;
    }
    if (head->next == NULL)  // only one node
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *q = head;
    while (q->next != NULL)
        q = q->next;
    q->prev->next = NULL;    // second-last node now points to NULL
    free(q);
}
void delete_pos(int pos)
{
    if (head == NULL)
    {
        printf("\n DLL Underflow");
        return;
    }
    if (pos == 1)
    {
        delete_begin();
        return;
    }
    struct Node *q = head;
    int c = 1;
    while (c < pos && q != NULL)
    {
        c++;
        q = q->next;
    }
    if (q == NULL)
    {
        printf("\n Position is out of bound");
        return;
    }
    q->prev->next = q->next;         // bypass q from forward direction
    if (q->next != NULL)
        q->next->prev = q->prev;     // bypass q from backward direction
    free(q);
}
void display_forward()
{
    if (head == NULL)
    {
        printf("\n DLL is Empty");
        return;
    }
    printf("\n Forward:  ");
    struct Node *q = head;
    while (q != NULL)
    {
        printf("%d", q->data);
        if (q->next != NULL)
            printf(" <-> ");
        q = q->next;
    }
}
void display_backward()
{
    if (head == NULL)
    {
        printf("\n DLL is Empty");
        return;
    } // go to last node
    struct Node *q = head;
    while (q->next != NULL)
        q = q->next;
    printf("\n Backward: ");
    while (q != NULL)
    {
        printf("%d", q->data);
        if (q->prev != NULL)
            printf(" <-> ");
        q = q->prev;
    }
}
int main()
{
    int d, pos, op, ch;
    while (1)
    {
        printf("\n\n 1.Insert  2.Delete  3.Display  4.Exit");
        printf("\n Enter your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("\n Enter new element: ");
                scanf("%d", &d);
                printf("\n 1.Beg  2.End  3.Pos");
                printf("\n Enter insertion option: ");
                scanf("%d", &op);
                switch (op)
                {
                    case 1: insert_begin(d); display_forward(); break;
                    case 2: insert_end(d);   display_forward(); break;
                    case 3:
                        printf("\n Enter position: ");
                        scanf("%d", &pos);
                        insert_pos(d, pos);
                        display_forward();
                        break;
                    default: printf("\n Invalid option");
                }
                break;

            case 2:
                printf("\n 1.Beg  2.End  3.Pos");
                printf("\n Enter deletion option: ");
                scanf("%d", &op);
                switch (op)
                {
                    case 1: delete_begin();  display_forward(); break;
                    case 2: delete_end();    display_forward(); break;
                    case 3:
                        printf("\n Enter delete position: ");
                        scanf("%d", &pos);
                        delete_pos(pos);
                        display_forward();
                        break;
                    default: printf("\n Invalid option");
                }
                break;

            case 3:
                printf("\n 1.Forward  2.Backward");
                printf("\n Enter display option: ");
                scanf("%d", &op);
                switch (op)
                {
                    case 1: display_forward();  break;
                    case 2: display_backward(); break;
                    default: printf("\n Invalid option");
                }
                break;

            case 4: exit(0);

            default: printf("\n Choice out of bound");
        }
    }
	
    return 0;
}