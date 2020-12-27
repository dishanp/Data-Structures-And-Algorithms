#include <stdio.h>
int main()
{
    int a[100];
    int freq[100];
    int size = 0;
    printf("Enter no of elements : ");
    scanf("%d", &size);
    for(int i = 0 ; i < size ; i++)
    {
        printf("Enter element %d : ", i+1);
        scanf("%d", &a[i]);
    }
    int count = 0;
    for(int i = 0 ; i < size ; i++)
    {
        count = 1;
        for(int j = i + 1 ; j < size ; j++)
        {
            if(a[i] == a[j+1])
            {
                count++;
                freq[j]++;
            }
        }
        if(freq[i] != 0)
        {
            freq[i] = count;
        }
    }
    printf("Frequency of all elements in array : \n");
    for(int i = 0 ; i < size ; i++)
    {
        if(freq[i] != 0)
        printf("Element %d appears %d times\n", a[i], freq[i]);
    }
}