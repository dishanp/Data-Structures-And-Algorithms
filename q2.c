/*
WAP to count the number of occurrences of an element in a linked list of n nodes.
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

void count_key(struct node *p, int key)
{
    int counter = 0;
    while(p)
    {
        if(p->data == key)
            counter++;
        p = p->next;
    }
    printf("Occurences of %d : %d\n", key, counter);
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

    create(A, n);
    printf("Enter key : ");
    scanf("%d", &key);
    count_key(first, key);
}