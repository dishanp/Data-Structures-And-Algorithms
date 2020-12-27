//Write an algorithm that takes as input the size of the array and the elements
//in the array and find the median of the elements in the array.

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
    //median is middle element of sorted array
    //to sort

    for(int i = 0 ; i < n - 1 ; i++)
    {
        for(int j = 0 ; j < n - i - 1 ; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted array : ");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    if(n%2 == 0)//even no of elements//n/2 and n+1/2 but here indexes are n-1 so
    {
        int median1 = (n - 1) / 2;//extra 0.5 removed since int
        int median2 = n / 2;
        printf("Median : %.2f\n", (float)(arr[median1]+arr[median2])/2);
    }
    else//n is odd i.e. odd no of elements
    {
        int median = n / 2;
        printf("Median element : %d\n", arr[median]);
    }
}