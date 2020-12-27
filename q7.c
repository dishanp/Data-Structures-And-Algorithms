/*
WAP to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*first = NULL, *even = NULL, *odd = NULL;
struct node *create(int A[], int n)
{
    struct node *p, *t, *last;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = A[0];
    p->next = NULL;
    last = p;

    for(int i = 1 ; i < n ; i++)
    {
        t = (struct node*)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return p;
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

void inserteven(struct node *p, int index, int key)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = key;

    if(index == 0)
    {
        t->next = even;
        even = t;
    }
    else
    {
        for(int i = 0 ; i < index - 1 ; i++)
        {
            p = p->next;//brings p 1 node behind desired index
        }
        t->next = p->next;
        p->next = t;
    }
}

void insertodd(struct node *p, int index, int key)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = key;

    if(index == 0)
    {
        t->next = odd;
        odd = t;
    }
    else
    {
        for(int i = 0 ; i < index - 1 ; i++)
        {
            p = p->next;//brings p 1 node behind desired index
        }
        t->next = p->next;
        p->next = t;
    }
}

void convert(struct node *p)
{
    int ce = 0, co = 0;
    while(p)
    {
        if(p->data%2 == 0)
        {
            inserteven(even, ce, p->data);
            ce++;
        }
        else
        {
            insertodd(odd, co, p->data);
            co++;
        }
        p = p->next;
    }

    first = even;
    p = first;
    while(p->next != NULL)
        p = p->next;
    p->next = odd;
}

int main()
{
    int n, key;
    printf("Number of elements : ");
    scanf("%d", &n);
    int A[n];
    printf("Enter elements : ");
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d", &A[i]);
    }
    first = create(A, n);
    convert(first);
    display(first);
}