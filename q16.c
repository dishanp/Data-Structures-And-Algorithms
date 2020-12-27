//Write down the algorithm to delete all the vowels in a character array.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    char *arr;
    printf("Enter number of characters : ");
    scanf("%d", &n);
    arr = (char*)malloc(n*sizeof(char));
    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter character %d : ", i+1);
        scanf(" %c", arr + i);
    }
    printf("Original character array : ");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%c ", *(arr + i));
    }

     for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')//only lowercase
        {
            for(int j = i ; j < n - 1 ; j++)
            {
                arr[j] = arr[j + 1];
            }
            n--;
        }
    }

    printf("\n\nNew character array : ");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%c ", *(arr + i));
    }
    printf("\n");


}