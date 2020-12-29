//WAP to reverse the contents of a dynamic array of n elements
#include <stdio.h>
#include <stdlib.h>
int main()
{
      int i, j, n,*data;
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

      for (i = 0 , j = n-1; i < j ; i++, j--)
      {
            int temp = *(data + i) ;
            *(data + i) = *(data + j) ;
            *(data + j) = temp ;
      }
      printf("\n");
      for(i = 0; i < n; ++i)
      {
            printf("%d", *(data + i));
      }
            printf("\n");
}