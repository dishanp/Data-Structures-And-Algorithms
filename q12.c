//Write down the algorithm to sort elements by their frequency.
#include <stdio.h>
#include <stdlib.h>

struct freqtable
{
    int e;//element
    int f;//frequency
    int in;//index
};
int main()
{
    int n;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    int a[n];
    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter element %d : ", i+1);
        scanf("%d", &a[i]);
    }
    //to sort the array
    for(int i = 0 ; i < n - 1 ; i++)
    {
        for(int j = 0 ; j < n - 1 - i ; j++)
        {
            if(a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("\nSorted Array : ");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ", a[i]);
    }
    int unique = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] != a[i+1])
        {
            unique++;
        }
    }
    printf("\n");
    //initializing values to freq table
    //giving index of last repeated element
    struct freqtable t[unique];
    int index = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] != a[i+1])
        {
            t[index].e = a[i];
            t[index].in = i;
            t[index].f = 1;
            index++;
        }
    }
    //printf("%d", unique);
    //increase frequency of repeated elements
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] == a[i+1])
        {
            for(int j = 0 ; j < unique ; j++)
            {
                if(a[i] == t[j].e)
                {
                    t[j].f++;
                }
            }
        }
    }

    //now we know no of unique elements
    printf("\nFrequency table : \n");
    printf("e  : ");
    for(int i = 0 ; i < unique ; i++)
    {
        printf("%d ", t[i].e);
    }
    printf("\n");
    printf("f  : ");
    for(int i = 0 ; i < unique ; i++)
    {
        printf("%d ", t[i].f);
    }
    printf("\n");
    printf("in : ");
    for(int i = 0 ; i < unique ; i++)
    {
        printf("%d ", t[i].in);
    }
    printf("\n");

    //sorting the frequency table according frequency
    for(int i = 0 ; i < unique - 1 ; i++)
    {
        for(int j = 0 ; j < unique - 1 - i ; j++)
        {
            if(t[j].f > t[j + 1].f)
            {
                struct freqtable temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
    //sorted table
    printf("\nSorted Frequency table : \n");
    printf("e  : ");
    for(int i = 0 ; i < unique ; i++)
    {
        printf("%d ", t[i].e);
    }
    printf("\n");
    printf("f  : ");
    for(int i = 0 ; i < unique ; i++)
    {
        printf("%d ", t[i].f);
    }
    printf("\n");
    printf("in : ");
    for(int i = 0 ; i < unique ; i++)
    {
        printf("%d ", t[i].in);
    }
    printf("\n\n");
    //printing freq sorted array from freq sorted table
    for(int i = 0 ; i < unique ; i++)
    {
        for(int j = 0 ; j < t[i].f ; j++)
        {
            printf("%d ", t[i].e);
        }
    }
}