//Given an unsorted dynamic array of size n, WAP to find and display the number of elements between two elements a and b (both inclusive).
#include <stdio.h>
#include <stdlib.h>
int main()
{
      int i, n,*data, a, b;
      printf("No of elements : ");
      scanf("%d", &n);
      data = (int*) calloc(n, sizeof(int));
      if(data == NULL)
      {
            printf("Error");
            return 1 ;
      }
      printf("\n");
      for(i = 0; i < n; ++i)
      {
            printf("Enter Number %d: ", i + 1);
            scanf("%d", data + i);
      }

      printf("Enter a : ");
      scanf("%d", &a);
      printf("Enter b : ");
      scanf("%d", &b);

      for(i = 0; i < n; ++i)
      {
            if(*(data + i) >= a && *(data + i) <= b)
            {
                  printf("%d\t", *(data + i));
            }
      }
      printf ("\n");

}