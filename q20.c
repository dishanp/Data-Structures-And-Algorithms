//Write an algorithm to replace every element in the array with the next greatest element present in the same array.

#include <stdio.h>
#include <stdlib.h>

void ngerearrange(int *arr, int n)
{
    int i, j;
    for (i=0; i<n; i++)
    {
        for (j = i+1; j<n; j++)
        {
            if (*(arr + i) < *(arr + j))
            {
                *(arr + i) = *(arr + j);
                break;
            }
        }
    }
}

int main()
{
    int *arr;
    int n, x, y, z;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));

    for (int i = 0 ; i < n ; i++)
    {
        printf("Enter element no %d :", i+1);
        scanf("%d", arr + i);
    }

    ngerearrange(arr, n);
    printf("Rearranged Array : \n");
    for (int i = 0 ; i < n ; i++)
    {
        printf("%d ", *(arr + i));
    }

}