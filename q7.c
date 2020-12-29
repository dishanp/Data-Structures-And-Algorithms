/*Let A be nXn square dynamic matrix. WAP by using appropriate user defined functions for the following:
a) Find the number of nonzero elements in A
b) Find the sum of the elements above the leading diagonal.
c) Display the elements below the minor diagonal.
d) Find the product of the diagonal elements.*/
#include <stdio.h>
#include <stdlib.h>

int NonZero(int *arr, int row, int col)
{
   int counter = 0 ;
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
         if (*(arr + i*col + j) != 0)
         {
            counter++ ;
         }
      }
   }
   return counter ;
}

int Sum(int *arr, int row, int col)
{
   int d1 = 0;
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
        if(j>i)
	     d1+=*(arr + i*col + j);
      }
   }
   return d1 ;

}

void DisplayMinor(int *arr, int row, int col)
{
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
        if(i>j)
	     printf("%d\t",*(arr + i*col + j));
      }
      printf("\n");
   }
}

int DiagProduct(int *arr, int row, int col)
{
   int product_major = 1 ;
   for(int i = 0; i < row; ++i)
    {
       for(int j = 0; j < col; ++j)
      {
         if(i == j)
         product_major = product_major * (*(arr + i*col + j));
      }
    }
    return product_major ;
}
int main()
{
   int n;
   printf("Enter value of n :");
   scanf("%d", &n) ;
   int row = n, col = n;
   int *arr = (int *)malloc(row * col * sizeof(int));
   int i, j;
   printf("Enter Elements : ");
   for (i = 0; i < row; i++)
      for (j = 0; j < col; j++)
         scanf("%d", arr + i*col + j);
   printf("The matrix elements are:\n");
   for (i = 0; i < row; i++)
   {
      for (j = 0; j < col; j++)
      {
         printf("%d ", *(arr + i*col + j));
      }
      printf("\n");
   }
      printf("Number of Non Zero elemnts : %d ", NonZero(arr, row, col)) ;
      printf("\nSum of the elements above the leading diagonal : %d \n" ,Sum(arr, row, col));
      printf("Elements below the minor diagonal : \n");
      DisplayMinor(arr, row, col);
      printf("\n");
      printf("Product of the diagonal elements : %d\n", DiagProduct(arr, row, col)) ;
}
