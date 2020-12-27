//Write an algorithm to remove repeated elements in a given array.
#include <stdio.h>
#include <stdlib.h>

void rem(int *arr, int *n, int j)
{
    for(int i = j ; i < *n ; i++)
    {
        arr[j] = arr[j+1];
    }
    *n = *n -1;
}

int main()
{
    int n,*arr;
    printf("Enter number of elements of array : ");
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));
    printf("Enter elements for array : \n");
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d", &arr[i]);
    }
    int c;
    for(int i = 0 ; i < n ; i++)
    {
        c = 0;
        for(int j = 0 ; j < n ; j++)
        {
            if(arr[i] == arr[j])
            {
                c++;
                if(c>1)
                {
                    rem(arr, &n, j);
                }
            }
        }
    }
    printf("\n New array : ");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

