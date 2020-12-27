/*
WAP to check whether a singly linked list is a palindrome or not.
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
    return p;
}

int length(struct node *p)
{
    int len = 0;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void check_palindrome(struct node *p)
{
    int len = length(first);
    struct node *q;
    int c = 0;
    while(p)
    {
        q = p;
        for(int i = 0 ; i < len - 1 ; i++)
        {
            q = q->next;
        }
        if(p->data != q->data)
        {
            c = 1;
        }
        len = len - 2;
        p = p->next;
    }

    if(c == 0)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

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
    check_palindrome(first);
}