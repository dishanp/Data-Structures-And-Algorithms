//Write an algorithm to replace every array element by multiplication of previous and next.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *arr;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int temp[n];
    printf("Enter array elements : \n");
    arr = (int*)malloc(n*sizeof(int));
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d", &arr[i]);
        temp[i] = arr[i];
    }
    printf("Original array : ");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d\t", arr[i]);
    }
    //using auxiliary array to make the changes
    for(int i = 0 ; i < n ; i++)
    {
        if(i == 0)
        temp[i] = arr[i]*arr[i+1];
        else if(i == n-1)
        temp[i] = arr[i]*arr[i-1];
        else
        temp[i] = arr[i-1]*arr[i+1];
    }
    //copying changed elements from aux array to original array
    for(int i = 0 ; i < n ; i++)
    {
        arr[i] = temp[i];
    }
    printf("\nNew array : ");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");

}