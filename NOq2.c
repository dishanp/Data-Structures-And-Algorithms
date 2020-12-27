/*Write an algorithm to add the original sparse matrix with the transpose of the same matrix.*/
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


/*struct sparse *add(struct sparse* s1, struct sparse *s2)
{
    int i = 0 ,j = 0 ,k = 0;
    struct sparse *sum;
    sum = (struct sparse *)malloc(sizeof(struct sparse));
    sum->ele = (struct element*)malloc((s1->num + s2->num)*sizeof(struct element));
    while(i < s1->num && j < s2->num)
    {
        if(s1->ele[i].row < s2->ele[j].row)
        {
            sum->ele[k] = s1->ele[i];
            k++;
            i++;
        }
        else if(s1->ele[i].row > s2->ele[j].row)
        {
            sum->ele[k] = s2->ele[j];
            k++;
            j++;
        }
        else//rows are same
        {
            if(s1->ele[i].col < s2->ele[j].col)
            {
                sum->ele[k] = s1->ele[i];
                k++;
                i++;
            }
            else if(s1->ele[i].col > s2->ele[j].col)
            {
                sum->ele[k] = s2->ele[j];
                k++;
                j++;
            }
            else//cols also same
            {
                sum->ele[k] = s1->ele[i];
                sum->ele[k].x = s1->ele[i].x + s2->ele[i].x;
                k++;
                i++;
                j++;
            }
        }

    }
    //to print remaining elements
    for(; i < s1->num ; i++)
    {
        sum->ele[k] = s1->ele[i];
        k++;
    }
    for(; j < s2->num ; j++)
    {
        sum->ele[k] = s2->ele[j];
        k++;
    }
    sum->r = s1->r;
    sum->c = s1->c;
    sum->num = k;//no of non zero ele
    return sum;
}*/

int main()
{
    struct sparse s1, s2, *s3;
    int temp;
    int k = 0;
    printf("Enter number of rows : ");
    scanf("%d", &s1.r);
    printf("Enter number of columns : ");
    scanf("%d", &s1.c);
    printf("Enter number of non-zero elements : ");
    scanf("%d", &s1.num);
    s1.ele = (struct element *)malloc(s1.num * sizeof(struct element));
    printf("Enter elements : \n");
    for(int i = 1 ; i <= s1.r ; i++)
    {
        for(int j = 1 ; j <= s1.c ; j++)
        {
            scanf("%d", &temp);
            if(temp != 0)
            {
                s1.ele[k].row = i;
                s1.ele[k].col = j;
                s1.ele[k].x = temp;
                k++;
            }
        }
    }
    printf("\nColumnar representation of the Sparse Matrix : \n");
        printf("| %d ", s1.r);
        for(int i = 0; i < s1.num ; i++)
        {
            printf("| %d ", s1.ele[i].row);
        }
        printf("|\n| %d ", s1.c);
        for(int i = 0; i < s1.num ; i++)
        {
            printf("| %d ", s1.ele[i].col);
        }
        printf("|\n| %d ", s1.num);
        for(int i = 0; i < s1.num ; i++)
        {
            printf("| %d ", s1.ele[i].x);
        }
        printf("|\n\n");
    s2.r = s1.c;
    s2.c = s1.r;
    s2.num = s1.num;
    s2.ele = (struct element *)malloc(s2.num * sizeof(struct element));
    for(int i = 0 ; i < s2.num ; i++)
    {
        s2.ele[i].row = s1.ele[i].col;
        s2.ele[i].col = s1.ele[i].row;
        s2.ele[i].x = s1.ele[i].x;
    }

    //to sort the new columnar representation in ascending
    struct element t;
    for(int i = 0 ; i < s2.num - 1 ; i++)
    {
        for(int j = 0 ; j < s2.num - i - 1 ; j++)
        {
            if(s2.ele[j].row > s2.ele[j+1].row)
            {
                t.row = s2.ele[j].row ;
                s2.ele[j].row = s2.ele[j+1].row ;
                s2.ele[j+1].row = t.row;

                t.col = s2.ele[j].col ;
                s2.ele[j].col = s2.ele[j+1].col ;
                s2.ele[j+1].col = t.col;

                t.x = s2.ele[j].x ;
                s2.ele[j].x = s2.ele[j+1].x ;
                s2.ele[j+1].x = t.x;
            }
            if(s2.ele[j].row == s2.ele[j+1].row)
            {
                if(s2.ele[j].col > s2.ele[j+1].col)
                {
                    t.row = s2.ele[j].row ;
                    s2.ele[j].row = s2.ele[j+1].row ;
                    s2.ele[j+1].row = t.row;

                    t.col = s2.ele[j].col ;
                    s2.ele[j].col = s2.ele[j+1].col ;
                    s2.ele[j+1].col = t.col;

                    t.x = s2.ele[j].x ;
                    s2.ele[j].x = s2.ele[j+1].x ;
                    s2.ele[j+1].x = t.x;
                }
            }
        }
    }
    printf("\n");
    k = 0;
    for(int i = 1 ; i <=s2.r ; i++)
    {
        for(int j = 1 ; j <= s2.c ; j++)
        {
            if(s2.ele[k].row == i && s2.ele[k].col == j)
            {
                printf("%d ", s2.ele[k].x);
                k++;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }

    printf("\nColumnar representation of the Transpose of Sparse Matrix : \n");
    printf("| %d ", s2.r);
    for(int i = 0; i < s2.num ; i++)
    {
        printf("| %d ", s2.ele[i].row);
    }
    printf("|\n| %d ", s2.c);
    for(int i = 0; i < s2.num ; i++)
    {
        printf("| %d ", s2.ele[i].col);
    }
    printf("|\n| %d ", s2.num);
    for(int i = 0; i < s2.num ; i++)
    {
        printf("| %d ", s2.ele[i].x);
    }
    printf("|\n\n");

    //s1 = original sparse matix ; s2 = transposed sparse matrix
    
}