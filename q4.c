/*
WAP to remove duplicates from a linked list of n nodes.
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*first;

void create(int A[], int n)
{
    struct node *t, *last;
    first = (struct node*)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i = 1 ; i < n ; i++)
    {
        t = (struct node*)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct node *p)
{
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void remduplicates(struct node *p)
{
    struct node *q, *r, *t;
    while(p)
    {
        q = p->next;
        r = p;

        while(q)
        {
            if(p->data == q->data)
            {
                r->next = q->next;
                t = q;
                free(t);
                q = q->next;
            }
            else
            {
                r = q;
                q = q->next;
            }
        }
        p = p->next;
    }
}

int main()
{
    int n, m;
    printf("Number of elements : ");
    scanf("%d", &n);
    int A[n];
    printf("Enter elements : ");
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &A[i]);
    create(A, n);
    remduplicates(first);
    display(first);
}