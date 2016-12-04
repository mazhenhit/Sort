#include <stdio.h>
#include <stdlib.h>

void insertSort(int *p, int gap, int length)
{
    if(p == NULL)
        return;

    int i, j;
    int tmp;
    for(i = gap; i < length; i ++)
    {
        tmp = p[i];
        for(j = i - gap; j >= 0; j -= gap)
        {
            if(p[j] > tmp)
            {
                p[j + gap] = p[j];
            }
            else
            {
                break;
            }
        }
        p[j + gap] = tmp;
    }
}

void shellSort(int *p, int length)
{
    if(p == NULL)
        return;

    int i;

    for(i = length / 2; i >= 1; i /= 2)
    {
        insertSort(p, i, length);
    }
}

int main()
{
    int i = 0;
    int a[] = {1, 4, 5, 9, 0, 3, 6, 2, 8, 7};

    for(i = 0; i < 10; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");

    //sort
    shellSort(a, 10);

    for(i = 0; i < 10; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");

    return 0;
}

