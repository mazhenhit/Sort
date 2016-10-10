#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *a, int length)
{
    int i, j;
    
    if(length < 0)
        return;

    for(i = 1; i < length; i++)
    {
        for(j = length - 1; j >= i; j--)
        {
            if(a[j] < a[j - 1])
            {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}

int main()
{
    int a[] = {3, 5, 1, 7, 0, 2, 4, 8};
    int i;

    for(i = 0; i < 8; i ++)
        printf("%d\t", a[i]);
    printf("\n");

    bubbleSort(a, 8);

    for(i = 0; i < 8; i ++)
        printf("%d\t", a[i]);

    return 0;
}

