//Write down the algorithm to find the k’th smallest and largest element in an unsorted array
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int n, k, temp;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter element no %d :", i+1);
        scanf("%d", arr + i);
    }
    printf("Enter k : ");
    scanf("%d", &k);
    //bubble sort
    for(int i = 0 ; i < n - 1 ; i++)
    {
        for(int j = 0; j < n - 1 - i; j ++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("The kth smallest element : %d\n", arr[k-1]);
    printf("The kth largest element : %d\n", arr[n-k]);
}