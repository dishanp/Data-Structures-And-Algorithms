/*Write an algorithm that takes as input the size of the array and the elements
in the array and a particular index and prints the element at that index.*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,index;
    printf("Enter size of the array : ");
    scanf("%d", &n);
    int *A;
    A = (int*)malloc(n*sizeof(int));

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter element no %d : ", i + 1);
        scanf("%d",&A[i]);
    }
    printf("Enter index : ");
    scanf("%d", &index);
    printf("Element at index %d : %d\n", index, A[index]);
}