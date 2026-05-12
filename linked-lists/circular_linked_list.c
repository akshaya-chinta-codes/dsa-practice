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
    {
        p->next = p;   // points to itself
        head = p;
        return;
    } // find last node to update its next
    struct Node *last = head;
    while (last->next != head)
        last = last->next;
    p->next = head;
    last->next = p;   // last node now points to new head
    head = p;
}
void insert_end(int d)
{
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->data = d;
    if (head == NULL)
    {
        p->next = p;   // points to itself
        head = p;
        return;
    }
    struct Node *last = head;
    while (last->next != head)
        last = last->next;
    last->next = p;
    p->next = head;   // new last node points back to head
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
    while (c < pos - 1 && q->next != head)
    {
        c++;
        q = q->next;
    }
    if (c < pos - 1)
    {
        printf("\n Position is out of bound");
        free(p);
        return;
    }
    p->next = q->next;
    q->next = p;
}
void delete_begin()
{
    if (head == NULL)
    {
        printf("\n CLL Underflow");
        return;
    }
    if (head->next == head)   // only one node
    {
        free(head);
        head = NULL;
        return;
    }
    // find last node to re-link it to new head
    struct Node *last = head;
    while (last->next != head)
        last = last->next;
    struct Node *q = head;
    head = head->next;
    last->next = head;   // last node points to new head
    free(q);
}
void delete_end()
{
    if (head == NULL)
    {
        printf("\n CLL Underflow");
        return;
    }
    if (head->next == head)   // only one node
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *q = head, *p = NULL;
    while (q->next != head)
    {
        p = q;
        q = q->next;
    }
    p->next = head;   // second-last now points back to head
    free(q);
}
void delete_pos(int pos)
{
    if (head == NULL)
    {
        printf("\n CLL Underflow");
        return;
    }
    if (pos == 1)
    {
        delete_begin();
        return;
    }
    struct Node *q = head, *p = NULL;
    int c = 1;
    while (c < pos && q->next != head)
    {
        c++;
        p = q;
        q = q->next;
    }
    if (c < pos)
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
        printf("\n CLL is Empty");
        return;
    }
    printf("\n CLL elements are: ");
    struct Node *q = head;
    do
    {
        printf("%d", q->data);
        if (q->next != head)
            printf(" -> ");
        q = q->next;
    } while (q != head);
    printf(" -> (back to %d)", head->data);  // show circular 
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
                    case 1: insert_begin(d); display(); break;
                    case 2: insert_end(d);   display(); break;
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
                    case 1: delete_begin();  display(); break;
                    case 2: delete_end();    display(); break;
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