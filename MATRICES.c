/*Design array based data structure to represent
- Diagonal matrix
- Lower Triangular matrix
- Upper Triangular matrix
- Tri-diagonal matrix
- Toeplitz matrix
- Sparse Matrix
*/
#include <stdio.h>
#include <stdlib.h>

struct element//for sparse
{
    int row;
    int col;
    int x;
};
struct sparse//for sparse
{
    int r;
    int c;
    int num;
    struct element *ele;
};
int main()
{
    struct sparse s;
    int *A;//1D aray to store
    int n, m;//dimension
    int choice;
    int size = 0;//will determine size of 1D array to store elements
    int t;
    printf("1 : Diagonal Matrix\n2 : Lower Triangular Matrix\n");
    printf("3 : for Upper Triangular Matrix\n4 : Tri-diagonal Matrix\n");
    printf("5 : Toeplitz Matrix\n6 : Symmetric Matrix\n7 : Sparse Matrix\n");
    printf("Enter Choice : ");
    scanf("%d", &choice);
    printf("Enter Dimensions (same m & n values for options 1-6: ");
    scanf("%d%d",&m, &n);

    switch(choice)
    {
        case 1 :
        size = n;
        A = (int*)malloc(size * sizeof(int));
        printf("\nEnter elements : \n");
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                scanf("%d", &t);
                if(i == j)
                {
                    A[i - 1] = t ;
                }
            }
        }
        printf("\n1D array storing the elements : ");
        for(int i = 0 ; i < size ; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n\nDisplaying matrix from stored 1D array values :\n");
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                if(i == j)
                {
                    printf("%d ", A[i - 1]);
                }
                else
                {
                    printf("0 ");
                }
            }
            printf("\n");
        }
        break;

        case 2 :
        size = n*(n + 1) / 2;
        A = (int*)malloc(size * sizeof(int));
        printf("\nEnter elements : \n");
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                scanf("%d", &t);
                if(i >= j)
                {
                    //ROW MAJOR FORMULA can replace i and j in upper triag's RM to get CM here
                    A[i*(i-1)/2 + (j-1)] = t ;//ROW MAJOR FORMULA
                }
            }
        }
        printf("\n1D array storing the elements : ");
        for(int i = 0 ; i < size ; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n\nDisplaying matrix from stored 1D array values :\n");
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                if(i >= j)
                {
                    printf("%d ", A[i*(i-1)/2 + (j-1)]);
                }
                else
                {
                    printf("0 ");
                }
            }
            printf("\n");
        }
        break;

        case 3 :
        size = n * (n + 1) / 2;
        A = (int*)malloc(size * sizeof(int));
        printf("\nEnter elements : \n");
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                scanf("%d", &t);
                if(i <= j)
                {
                    //ROW MAJOR FORMULA can replace i and j in lower triag's rm to get col major here
                    A[(n*(i-1) - (i-1)*(i-2)/2) + (j-i)] = t ;
                }
            }
        }
        printf("\n1D array storing the elements : ");
        for(int i = 0 ; i < size ; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n\nDisplaying matrix from stored 1D array values :\n");
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                if(i <= j)
                {
                    printf("%d ", A[(n*(i-1) - (i-1)*(i-2)/2) + (j-i)]);
                }
                else
                {
                    printf("0 ");
                }
            }
            printf("\n");
        }
        break;

        case 4 :
        size = (3 * n) - 2;
        A = (int*)malloc(size * sizeof(int));
        printf("\nEnter elements : \n");
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                scanf("%d", &t);
                if((i - j) == 1)
                    A[i-2] = t;
                else if((i - j) == 0)
                    A[n - 1 + i - 1] = t;
                else if((i - j) == -1)
                    A[(2*n) - 1 + i - 1] = t;
            }
        }
        printf("\n1D array storing the elements : ");
        for(int i = 0 ; i < size ; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n\nDisplaying matrix from stored 1D array values :\n");
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                if((i - j) == 1)
                    printf("%d ", A[i - 2]);
                else if((i - j) == 0)
                    printf("%d ", A[n - 1 + i - 1]);
                else if((i - j) == -1)
                    printf("%d ", A[(2*n) - 1 + i - 1]);
                else
                    printf("0 ");
            }
            printf("\n");
        }
        break;

        case 5 :
        size = (2 * n) - 1;
        A = (int*)malloc(size * sizeof(int));
        printf("\nEnter elements : \n");
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                scanf("%d", &t);
                if(i <= j)
                    A[j - i] = t;
                else if(j < i)
                    A[n + i - j - 1] = t;
            }
        }
        printf("\n1D array storing the elements : ");
        for(int i = 0 ; i < size ; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n\nDisplaying matrix from stored 1D array values :\n");
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                if(i <= j)
                    printf("%d ", A[j - i]);
                else if(j < i)
                    printf("%d ", A[n + i - j - 1]);
            }
            printf("\n");
        }
        break;

        case 6 :
        size = n*(n + 1) / 2;
        A = (int*)malloc(size * sizeof(int));
        printf("\nEnter elements : \n");
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                scanf("%d", &t);
                if(i >= j)
                {
                    //ROW MAJOR FORMULA can replace i and j in upper triag's RM to get CM here
                    A[i*(i-1)/2 + (j-1)] = t ;//ROW MAJOR FORMULA
                }
            }
        }
        printf("\n1D array storing the elements : ");
        for(int i = 0 ; i < size ; i++)
        {
            printf("%d ", A[i]);
        }
        int temp1,temp2;
        printf("\n\nDisplaying matrix from stored 1D array values :\n");
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                if(i >= j)
                {
                    printf("%d ", A[i*(i-1)/2 + (j-1)]);
                }
                else
                {
                    temp1 = i;
                    temp2 = j;
                    printf("%d ", A[temp2*(temp2-1)/2 + (temp1-1)]);
                }
            }
            printf("\n");
        }
        break;

        case 7 :
        s.r = m;
        s.c = n;
        int k = 0;
        printf("\nEnter number of non-zero elements : ");
        scanf("%d", &s.num);
        s.ele = (struct element *)malloc(s.nu*sizeof(struct element));
        printf("\nEnter all elements : \n");
        for(int i = 1 ; i <= s.r ; i++)
        {
            for(int j = 1 ; j <= s.c ; j++)
            {
                scanf("%d", &t);
                if(t != 0)
                {
                    s.ele[k].row = i;
                    s.ele[k].col = j;
                    s.ele[k].x = t;
                    k++;
                }
            }
        }
        printf("\nColumnar representation of the Sparse Matrix : \n");
        printf("%d ", s.r);
        for(int i = 0; i < s.num ; i++)
        {
            printf("%d ", s.ele[i].row);
        }
        printf("\n%d ", s.c);
        for(int i = 0; i < s.num ; i++)
        {
            printf("%d ", s.ele[i].col);
        }
        printf("\n%d ", s.num);
        for(int i = 0; i < s.num ; i++)
        {
            printf("%d ", s.ele[i].x);
        }
        printf("\nDisplaying matrix from stored columnar representation : \n");
        k = 0;
        for(int i = 1 ; i <= s.r ; i++)
        {
            for(int j = 1 ; j <= s.c ; j++)
            {
                if(i == s.ele[k].row && j == s.ele[k].col)
                {
                    printf("%d ", s.ele[k].x);
                    k++;
                }
                else
                {
                    printf("0 ");
                }
            }
            printf("\n");
        }
    }
}