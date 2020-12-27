/*Given an array of integers, Write down the algorithm to count number of sub-arrays
(of size more than one) that are strictly increasing.
Input: arr[] = {1, 2, 3, 4}
Output: 6 as there are 6 sub-arrays {1, 2}, {1, 2, 3}, {1, 2, 3, 4}, {2, 3}, {2, 3, 4} and {3, 4}*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter number of elements of array : ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    printf("Enter elements for array : \n");
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {

            if(arr[i] < arr[j])
            {
                printf("{");
                for(int k = i ; k <= j ; k++)
                printf("%d ", arr[k]);
                printf("}  ");
            }
        }
    }
    printf("\n");

}