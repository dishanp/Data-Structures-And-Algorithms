//Write an algorithm to find whether an array is subset of another array
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n1,n2;
    printf("Enter number of elements of array 1 : ");
    scanf("%d", &n1);
    printf("Enter number of elements of array 2 : ");
    scanf("%d", &n2);
    int *arr1 = (int*)malloc(n1*sizeof(int));
    int *arr2 = (int*)malloc(n2*sizeof(int));
    printf("Enter elements for array 1 : \n");
    for(int i = 0 ; i < n1 ; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter elements for array 2 : \n");
    for(int i = 0 ; i < n2 ; i++)
    {
        scanf("%d", &arr2[i]);
    }
    int c = 0;
    for(int i = 0 ; i < n2 ; i++)
    {
        for(int j = 0 ; j < n1 ; j++)
        {
            if(arr2[i] == arr1[j])
            c++;
        }
    }
    if(c>=n2)
    printf("arr2 is a subset of arr1\n");
    else
    printf("arr2 is not a subset of arr1\n");
}