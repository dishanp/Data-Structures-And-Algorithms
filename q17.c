//Write down the algorithm to print all the elements below the minor diagonal in a 2-D array.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    int **arr;
    printf("Enter Dimensions (m & n) : ");
    scanf("%d%d", &m, &n);
    arr = (int**)malloc(m*sizeof(int*));//totally in heap
    for(int i = 0 ; i < m ; i++)
    {
        arr[i] = (int*)malloc(n*sizeof(int));
    }
    printf("Enter elements : \n");
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Original Matrix : \n");
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("New Matrix : \n");
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if((i+j) >= m)//assumming to be a square matrix
            {
                printf("%d ", arr[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }

}