//Write down the algorithm to add two polynomials.

#include <stdio.h>
#include <stdlib.h>

struct term
{
    int coeff;
    int expo;
};

struct polynomial
{
    int n;
    struct term *t;
};
int main()
{
    struct polynomial p1, p2, sum;
    printf("Enter number of terms of 1st polynomial : ");
    scanf("%d", &p1.n);
    printf("Enter number of terms of 2nd polynomial : ");
    scanf("%d", &p2.n);
    p1.t = (struct term*)malloc(p1.n * sizeof(struct term));
    p2.t = (struct term*)malloc(p2.n * sizeof(struct term));
    printf("Enter Terms of 1st polynomial : (coefficient then exponent) : ");
    for(int i = 0 ; i < p1.n ; i++)
    {
        scanf("%d%d", &p1.t[i].coeff, &p1.t[i].expo);
    }
    printf("Enter Terms of 2nd polynomial : (coefficient then exponent) : ");
    for(int i = 0 ; i < p2.n ; i++)
    {
        scanf("%d%d", &p2.t[i].coeff, &p2.t[i].expo);
    }

    sum.t = (struct term*)malloc((p1.n + p2.n) * sizeof(struct term));
    int i = 0 ,j = 0 ,k = 0;
    while(i < p1.n && j < p2.n)
    {
        if(p1.t[i].expo > p2.t[j].expo)
        {
            sum.t[k] = p1.t[i];
            k++;
            i++;
        }
        else if(p1.t[i].expo < p2.t[j].expo)
        {
            sum.t[k] = p2.t[j];
            k++;
            j++;
        }
        else
        {
            sum.t[k] = p1.t[i];
            sum.t[k].coeff = sum.t[i].coeff + p2.t[j].coeff ;
            k++;
            i++;
            j++;
        }
    }
    for(; i < p1.n ; i++)
    {
        sum.t[k] = p1.t[i];
        k++;
    }
    for(; j < p2.n ; j++)
    {
        sum.t[k] = p2.t[i];
        k++;
    }
    sum.n = k;

    printf("Sum : ");
    for(i = 0 ; i < sum.n ; i++)
    {
        printf("%dx%d +", sum.t[i].coeff, sum.t[i].expo);
    }
    printf("\n");
}