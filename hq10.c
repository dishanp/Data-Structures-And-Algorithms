/*Given an array of integers. All numbers occur twice except one number which occurs
once. Write down the algorithm to find the number.
Input: ar[] = {7, 3, 5, 4, 5, 3, 4};
Output: 7
*/
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
    int c;
    for(int i = 0 ; i < n ; i++)
    {
        c = 0;
        for(int j = 0 ; j < n ; j++)
        {
            if(arr[i] == arr[j])
            c++;
        }
        if(c == 1)
        {
            printf("%d occurs only once\n", arr[i]);
            break;
        }
    }

}