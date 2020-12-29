//WAP to sort a dynamic array of n numbers.
#include<stdio.h>
#include<stdlib.h>
int main()
{
      int *a,n,i,j,t;
      printf("Number of elements : ");
      scanf("%d",&n);
      a=(int *)calloc(n, sizeof(int));
      printf("\nEnter %d Numbers: \n\n",n);
      for(i=0;i<=n-1;i++)
      {
            scanf("%d", (a+i));
      }
      for(i=0;i<n-1;i++)
      {
            for(j=0;j<n-i-1;j++)
            {
                  if(*(a+j)>*(a+j+1))
                  {
                        t=*(a+j);
                        *(a+j)=*(a+j+1);
                        *(a+j+1)=t;
                  }
            }
      }
      printf("\nAscending Order: \n");
      for(i=0;i<n;i++)
      printf("%d\t",*(a+i));
      printf("\n") ;
      return 0;
}