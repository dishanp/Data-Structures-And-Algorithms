//WAP to find out the smallest and largest element stored in an array of n integers.
#include <stdio.h>
#include <stdlib.h>
int main()
{
      int i, n,*data;
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
      int min = *data ;
      int max = *data ;
      for(i = 0; i < n; ++i)
      {
            if (min > *(data + i))
            {
                  min = *(data + i) ;
            }
            if (max < (*data + i))
            {
                  max = *(data + i) ;
            }
      }
      printf("MIN = %d\n", min) ;
      printf("MAX = %d\n", max) ;
      return 0;
}