//Given an array arr, write an algorithm to find the maximum j – i such that arr[j] > arr[i]
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,sum;
    printf("Enter no of elements : ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter element %d : ", i+1);
        scanf("%d", &arr[i]);
    }

    int i, j;
    int maxdiff = -1;

    for (i = 0; i < n; ++i)
    {
        for (j = n-1; j > i; --j)
        {
            if(arr[j] > arr[i] && maxdiff < (j - i))
            maxdiff = j - i;
        }
    }
    printf("\n");
}