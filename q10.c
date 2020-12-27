//Design an algorithm to convert a lower triangular matrix to upper triangular matrix.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *A;//1D aray to store
    int n;//dimension
    int size = 0;
    printf("Enter Dimensions : ");
    scanf("%d", &n);
    size = n*(n + 1) / 2;
    int t;
    A = (int*)malloc(size * sizeof(int));
    printf("\nEnter elements : \n");
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            scanf("%d", &t);
            if(i >= j)
            {
                A[i*(i-1)/2 + (j-1)] = t ;//ROW MAJOR FORMULA
            }
        }
    }
    printf("\n1D array storing the elements : ");
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n\nDisplaying Upper Triangular Matrix from stored 1D array values (inverted):\n");
    for(int i = n ; i >= 1 ; i--)
    {
        for(int j = n ; j >= 1 ; j--)
        {
            if(i >= j)
            {
                printf("%d ", A[i*(i-1)/2 + (j-1)]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n\nDisplaying Upper Triangular Matrix from stored 1D array values (non-inverted):\n");
    for(int i = n ; i >= 1 ; i--)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(i >= j)
            {
                printf("%d ", A[i*(i-1)/2 + (j-1)]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}