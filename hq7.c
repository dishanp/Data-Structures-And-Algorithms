//q6 is theoretical
/*Given an array of integers, and a number ‘sum’. Write an algorithm to find
the number of pairs of integers in the array whose sum is equal to ‘sum’.
Examples: Input : arr[] = {1, 5, 7, -1}, sum = 6
Output : 2 as Pairs with sum 6 are (1, 5) and (7, -1)*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, sum;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    printf("Enter elements : \n");
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter sum : ");
    scanf("%d", &sum);
    printf("Pairs with sum %d are :  ", sum);
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i + 1 ; j < n ; j++)
        {
            if(arr[i] + arr[j] == sum)
            {
                printf("(%d, %d)  ", arr[i], arr[j]);
            }
        }
    }
    printf("\n");
}