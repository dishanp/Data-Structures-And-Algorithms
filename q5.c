/*
Given a linked list which is sorted, WAP to insert an element into the linked list in sorted way
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

void sortinsert(struct node *p, int key)
{
    struct node *t, *q;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = key;

    while(p && p->data < key)
    {
        q = p;
        p = p->next;
    }
    //q points to node smaller than key and p points to node larger than key
    if(p == first)
    {
        t->next = first;
        first = t;
    }
    else
    {
        t->next = p;
        q->next = t;
    }
}

int main()
{
    int n, key;
    printf("Number of elements : ");
    scanf("%d", &n);
    int A[n];
    printf("Enter elements : ");
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &A[i]);
    create(A, n);

    printf("Enter key : ");
    scanf("%d", &key);
    sortinsert(first, key);
    display(first);
}