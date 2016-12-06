#include <stdio.h>
#include <stdlib.h>

void countSort(int *p, int length, int maxNum)
{
    if(p == NULL)
        return;

    int tmp[length];
    int count[maxNum + 1];

    int i;
    for(i = 0; i <= maxNum; i++)
    {
        count[i] = 0;
    }
    
    for(i = 0; i < length; i++)
    {
        count[p[i]]++;
    }

    for(i = 1; i < maxNum + 1; i++)
    {
        count[i] += count[i - 1];
    }

    for(i = length - 1; i >= 0; i--)
    {
        tmp[--count[p[i]]] = p[i];
    }
    
    for(i = 0; i < length; i++)
    {
        p[i] = tmp[i];
    }
}

int main()
{
    int i = 0;
    int a[] = {1, 5, 5, 5, 0, 3, 6, 2, 8, 7};

    for(i = 0; i < 10; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");

    //sort
    countSort(a, 10, 9);

    for(i = 0; i < 10; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");

    return 0;
}

