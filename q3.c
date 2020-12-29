//WAP to search an element in a dynamic array of n numbers
#include <stdio.h>
#include <stdlib.h>
int main()
{
      int i, n,*arr;
      printf("No of elements : ");
      scanf("%d", &n);
      arr = (int*) calloc(n, sizeof(int));
      if(arr == NULL)
      {
            printf("Error");
            return 1 ;
      }
      printf("\n");
      for(i = 0; i < n; ++i)
      {
            printf("Enter Number %d: ", i + 1);
            scanf("%d", arr + i);
      }

      int ele ;
      printf("Enter element to be searched : ");
      scanf("%d", &ele);
      for(i = 0; i < n; ++i)
      {
            if (ele == *(arr + i))
            printf("Found at position : %d", i + 1);
      }
}
