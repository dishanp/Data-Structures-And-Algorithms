/*
WAP to find number of occurrences of all elements in a linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*first;

struct node_freq
{
    int data;
    int freq;
    struct node_freq *next;
}*head;

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

void insert(struct node_freq *p, int index, int key)
{
    struct node_freq *t = (struct node_freq *)malloc(sizeof(struct node_freq));
    t->data = key;
    t->freq = 0;

    if(index == 0)
    {
        t->next = head;
        head = t;
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

void display_freq(struct node_freq *p)
{
    while(p)
    {
        printf("Frequency of element %d is %d\n", p->data, p->freq);
        p = p->next;
    }
    printf("\n");
}

void frequency(struct node *p)
{
    struct node *q;
    int c = 0, counter;
    while(p)
    {
        counter = 0;
        q = p->next;

        while(q)
        {
            if(p->data == q->data)
            counter++;
            q = q->next;
        }
        if(counter == 0)
        {
            insert(head, c, p->data);
            c++;
        }
        p = p->next;
    }
    //this populates a sll containing only unique elements and all their frequencies set to 0
    //now we can traverse the og sll for each element in node_freq sll to fill up frequency values


    struct node_freq *r = head;
    while(r)
    {
        p = first;
        while(p)
        {
            if(r->data == p->data)
                r->freq++;
            p = p ->next;
        }
        r = r->next;
    }

    display_freq(head);
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
    frequency(first);
}