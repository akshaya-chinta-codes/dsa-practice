#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void insert_begin(int d)
{
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->data = d;
    if (head == NULL)
        p->next = NULL;
    else
        p->next = head;
    head = p;
}
void insert_end(int d)
{
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->data = d;
    p->next = NULL;
    if (head == NULL)
        head = p;
    else
    {
        struct Node *q = head;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }
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
        free(p); // avoid memory leak
        return;
    }
    p->next = q->next;
    q->next = p;
}

void delete_begin()
{
    if (head == NULL)
    {
        printf("\n SLL Underflow");
        return;
    }
    struct Node *q = head;
    head = head->next;
    free(q);
}

void delete_end()
{
    if (head == NULL)
    {
        printf("\n SLL Underflow");
        return;
    }
    // FIX: free the node when only one element exists
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *q = head, *p = NULL;
    while (q->next != NULL)
    {
        p = q;
        q = q->next;
    }
    p->next = NULL;
    free(q);
}

void delete_pos(int pos)
{
    if (head == NULL)
    {
        printf("\n SLL Underflow");
        return;
    }
    // FIX: handle position 1 separately to avoid null pointer crash
    if (pos == 1)
    {
        delete_begin();
        return;
    }
    struct Node *q = head, *p = NULL;
    int c = 1;
    while (c < pos && q != NULL)
    {
        c++;
        p = q;
        q = q->next;
    }
    if (q == NULL)
    {
        printf("\n Position is out of bound");
        return;
    }
    p->next = q->next;
    free(q);
}

void display()
{
    if (head == NULL)
    {
        printf("\n SLL is Empty");
        return;
    }
    printf("\n SLL elements are: ");
    struct Node *q = head;
    while (q != NULL)
    {
        printf("%d", q->data);
        if (q->next != NULL)
            printf(" -> "); // FIX: separator for clarity
        q = q->next;
    }
}

int main() // FIX: int main() instead of void main()
{
    int d, pos, op, ch; // FIX: declared outside switch

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
                    case 1: insert_begin(d);  display(); break;
                    case 2: insert_end(d);    display(); break;
                    case 3:
                        printf("\n Enter position: ");
                        scanf("%d", &pos);
                        insert_pos(d, pos);
                        display();
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
                    case 1: delete_begin();   display(); break;
                    case 2: delete_end();     display(); break;
                    case 3:
                        printf("\n Enter delete position: ");
                        scanf("%d", &pos);
                        delete_pos(pos);
                        display();
                        break;
                    default: printf("\n Invalid option");
                }
                break;

            case 3: display(); break;
            case 4: exit(0);
            default: printf("\n Choice out of bound");
        }
    }

    return 0;
}