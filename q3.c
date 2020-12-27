//WAP to reverse the first m elements of a linked list of n nodes.

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

void reverse_m(struct node *p, int m)
{
    int counter = 0;
    struct node *q = NULL;
    struct node *r = NULL;

    //reversing links upto m nodes
    while(counter < m)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
        counter++;
    }
    first = q;
    //now p is pointing to rest of LL that is not reversed
    //q is pointing to first node of reversed list

    //concatenating reversed list with rest of list
    while(q->next != NULL)
    {
        q = q->next;
    }
    q->next = p;
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
    printf("Enter value of m : ");
    scanf("%d", &m);
    reverse_m(first, m);
    display(first);

}