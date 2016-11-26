#include <stdio.h>
#include <stdlib.h>

void selectSort(int *p, int length)
{
    int i, j;
    int min;

    if(length <= 1)
        return;

    for(i = 0; i < length; i++)
    {
        min = i;

        for(j = i; j < length; j++)
        {
            if(p[min] > p[j])
            {
                min = j;
            }
        }

        if(min != i)
        {
            int tmp = p[i];
            p[i] = p[min];
            p[min] = tmp;
        }
    }
}

void selectSortII(int *p, int length)
{
    int i, j;
    int min, max;

    if(p == NULL)
        return;

    for(i = 0; i <= length / 2; i++)
    {
        min = i;
        max = i;

        for(j = i; j < length; j++)
        {
            if(p[min] > p[j])
            {
                min = j;
            }

            if(p[max] < p[j])
            {
                max = j;
            }
        }

        if(min != i)
        {
            int tmp = p[i];
            p[i] = p[min];
            p[min] = tmp;
        }
        
        if(max != i)
        {
            int tmp = p[length - 1 - i];
            p[length - 1 - i] = p[max];
            p[max] = tmp;
        }
    }
}

int main()
{
    int a[] = {1, 6, 2, 0, 5, 3, 7, 4};

    selectSort(a, 8);

    int i = 0;
    for(i = 0; i < 8; i++){
        printf("%d\t", a[i]);
    }

    printf("\n");
    return 0;
}


