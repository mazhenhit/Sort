#include <stdio.h>
#include <stdlib.h>
/**
 * insert sort
 *    by zhenma 2016.9.20
 */
void insertSort(int *num, int length)
{
    int i, j;
    int key;

    if(length <= 0)
        return;

    for(i = 1; i < length; i++)
    {
        key = num[i];
        j = i - 1;
        while(j >= 0 && key < num[j])
        {
            num[j + 1] = num[j];
            j--;
        }
        num[j + 1] = key;
    }
}

int main()
{
    int i;
    int a[] = {5, 2, 4, 7, 1, 0};
    int length = 6;

    for(i = 0; i < length; i++)
    {
        printf("%d\t", a[i]);
    }

    insertSort(a, length);
            
    printf("\n");
    for(i = 0; i < length; i++)
    {
        printf("%d\t", a[i]);
    }
}

