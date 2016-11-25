#include <stdio.h>
#include <stdlib.h>

void insertSort(int *p, int length)
{
    int i = 0, j = 0;

    if(length <= 1)
        return;

    for(i = 1; i < length; i++)
    {
       if(p[i] < p[i -1])
       {
           int tmp = p[i];
           for(j = i - 1; j >= 0; j--)
           {
               if(p[j] > tmp)
                   p[j + 1] = p[j];
               else
                   break;
           }
           p[j + 1] = tmp;
       }
    }
}

int main()
{
    int p[] = {1, 5, 6, 2, 9, 4, 3, 0, 8, 7};

    insertSort(p, 10);

    int i = 0;
    for(i = 0; i < 10; i++)
    {
        printf("%d\t", p[i]);
    }
    printf("\n");
    return 0;
}

