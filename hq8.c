/*Given an unsorted array, Write down the algorithm to find the minimum difference
between any pair in given array.
Input : {1, 5, 3, 19, 18, 25};
Output : 1 as Minimum difference is between 18 and 19*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    printf("Enter elements : \n");
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d", &arr[i]);
    }
    //sort the array to not get negative min values when u compare element i with element i+1
    //bubblesort
    for(int i = 0 ; i < n - 1 ; i++)
    {
        for(int j = 0 ; j < n - 1 - i ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    int mindiff = 999;
    int f,l;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            if(mindiff > arr[j] - arr[i])
            {
                mindiff = arr[j] - arr[i];
                f = i;
                l = j;
            }
        }
    }
    printf("%d is the minimum difference between array elements i.e. %d and %d\n", mindiff, arr[f], arr[l]);
}