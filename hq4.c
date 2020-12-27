//Write an algorithm to find the number of occurrence of kth element in an integer array.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,*arr,k;
    printf("Enter number of elements of array : ");
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));
    printf("Enter elements for array : \n");
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter value of k : ");
    scanf("%d", &k);
    int key = arr[k];
    int c = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(key == arr[i])
        c++;
    }
    printf("%dth element occurs %d times.\n", k, c);

}