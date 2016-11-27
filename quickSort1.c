#include <stdio.h>
#include <stdlib.h>

/**
 *  zhenma
 *    2016-11-27
 * */

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partion(int *p, int l, int r)
{
    int x = p[r];
    int i = l - 1;
    int j;

    for(j = l; j < r; j++)
    {
        if(p[j] < x)
        {
            i += 1;
            swap(p + i, p + j);
        }
    }
    swap(p + i + 1, p + r);
    return i + 1;
}

void quickSort(int *p, int l, int r)
{
    if(p == NULL)
        return;

    if(l < r)
    {
        int x = partion(p, l, r);
        quickSort(p, l, x - 1);
        quickSort(p, x + 1, r);
    }
}

int main()
{
    int a[] = {1, 6, 2, 0, 5, 3, 7, 4};

    quickSort(a, 0, 7);

    int i = 0;
    for(i = 0; i < 8; i++){
        printf("%d\t", a[i]);
    }

    printf("\n");
    return 0;
}


