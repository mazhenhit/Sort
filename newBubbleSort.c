#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *p, int length)
{
    int i,j;

    if(length <= 1)
        return;

    for(i = 0; i < length; i++)
    {
        for(j = length - 1; j > i; j--)
        {
            if(p[j] < p[j - 1])
            {
                int tmp = p[j];
                p[j] = p[j - 1];
                p[j - 1] = tmp;
            }
        }
    }
}


int main()
{
    int a[] = {1, 6, 2, 0, 5, 3, 7, 4};

    bubbleSort(a, 8);

    int i = 0;
    for(i = 0; i < 8; i++){
        printf("%d\t", a[i]);
    }

    printf("\n");
    return 0;
}

