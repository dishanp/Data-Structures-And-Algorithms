/*Given a 2D array of size m X n, containing either 1 or 0. As we traverse through,
where ever we encounter 0, we need to convert the whole corresponding row and
column to 0, where the original value may or may not be 0. Devise an algorithm to
solve the problem minimizing the time and space complexity.*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m,n;
    printf("Enter dimensions (m & n) : ");
    scanf("%d%d", &m, &n);
    int **arr;
    arr = (int**)malloc(m*sizeof(int*));
    for(int i = 0 ; i < m ; i++)
    {
        arr[i] = (int*)malloc(n*sizeof(int));
    }
    printf("Enter elements : \n");
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            scanf("%d", &arr[i][j]);//arr + i*n + j
        }
    }
    //copying into temp array
    int arr2[m][n];
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            arr2[i][j] = arr[i][j];
        }
    }

     for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(arr[i][j] == 0)
            {
                for(int r = 0 ; r < n ; r++)
                {
                    arr2[r][j] = 0;
                }
                for(int c = 0 ; c < m ; c++)
                {
                    arr2[i][c] = 0;
                }
            }
        }
    }
    //copying back into original array
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            arr[i][j] = arr2[i][j];
        }
    }

    //printing new 2d array
    printf("\nNew 2D array : \n");
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            printf("%d ", arr[i][j]);//arr + i*n + j
        }
        printf("\n");
    }


}