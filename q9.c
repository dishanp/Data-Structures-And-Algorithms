/*
A linked list is said to contain a cycle if any node is visited more than once while traversing the list.
WAP to detect a cycle in a linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*first;

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
    //to create loop
    //optional step
    //last->next = p->next->next;//looping last element to 3rd node
    return p;
}

void isloop(struct node *f)
{
    struct node *p, *q;
    p = q = f;

    do
    {
        p = p->next;
        q = q->next;
        if(q != NULL)
            q = q->next;//moving q by two nodes but p by one
    }while(p && q && p != q);


    if(p == q)
        printf("Cycle is present\n");
    else
        printf("Cycle is absent\n");
}

int main()
{
    int n;
    printf("Number of elements : ");
    scanf("%d", &n);
    int A[n];
    printf("Enter elements : ");
    for(int i = 0 ; i < n ; i ++)
        scanf("%d", &A[i]);
    first = create(A, n);
    isloop(first);
}