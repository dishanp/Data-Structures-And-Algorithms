/*Given a dynamic array, WAP to print the next greater element (NGE) for every element.
The next greater element for an element x is the first greater element on the right side of x in array.
Elements for which no greater element exist, consider next greater element as -1.*/
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
      int next, j;
    for (i=0; i<n; i++)
    {
        next = -1;
        for (j = i+1; j<n; j++)
        {
            if (*(data + i) < *(data + j))
            {
                next = *(data + j);
                break;
            }
        }
        printf("%d -- %d\n", *(data + i), next);
     }
}