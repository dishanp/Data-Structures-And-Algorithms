//Write an algorithm that takes as input the size of the array and the elements
//in the array and find the mode of the elements in the array.

#include <stdio.h>
#include <stdlib.h>

struct freqtable
{
    int e;
    int f;
};
int main()
{
    int n,sum;
    printf("Enter no of elements : ");
    scanf("%d", &n);
    int *a = (int*)malloc(n*sizeof(int));
    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter element %d : ", i+1);
        scanf("%d", &a[i]);
    }
    //mode is the eliment with highest frequency
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
    int unique = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] != a[i+1])
        unique++;
    }
    //unique = no of unique elemnts and only 1 count for al the duplicates
    //initializing freqtable values
    struct freqtable t[unique];
    int index = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] != a[i+1])
        {
            t[index].e = a[i];
            t[index].f = 1;
            index++;
        }
    }
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
    int maxfreq = t[0].f;
    for(int j = 0 ; j < unique ; j++)
    {
        if(t[j].f > maxfreq)
        maxfreq = t[j].f;
    }
    for(int i = 0 ; i < unique ; i++)
    {
        if(t[i].f == maxfreq)
        {
            printf("MODE : %d\n", t[i].e);
        }
    }
    printf("\n");
}


