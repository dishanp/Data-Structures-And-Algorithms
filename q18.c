//Write an algorithm to find a triplet that sum to a given value.
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
    printf("Enter sum : ");
    scanf("%d", &sum);
    printf("\n");
    int c = 0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i + 1 ; j < n ; j++)
        {
            for(int k = j + 1 ; k < n ; k++)
            {
                if(arr[i] + arr[j] + arr[k] == sum)
                printf("%d, %d, %d", arr[i], arr[j], arr[k]);
                c++;
            }
        }
    }
    printf("\n");
    if(c == 0)
    printf("No Triplets\n");
}