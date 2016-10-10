#include <stdio.h>
#include <stdlib.h>

void mergeArray(int *a, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int *left = (int *)malloc(sizeof(int) * n1);
    int *right = (int *)malloc(sizeof(int) * n2);

    int i;
    for(i = 0; i < n1; i++)
    {
        left[i] = a[p + i];
    }

    for(i = 0; i < n2; i++)
    {
        right[i] = a[q + i + 1];
    }

    int j = 0;
    int k;
    for(k = p, i = 0, j = 0; k <= r && i < n1 && j < n2; k++)
    {
        if(left[i] <= right[j])
        {
            a[k] = left[i++];
        }
        else
        {
            a[k] = right[j++];
        }
    }

    while(i < n1)
    {
        a[k++] = left[i++];
    }

    while(j < n2)
    {
        a[k++] = right[j++];
    }


    free(left);
    free(right);
}

void mergeSort(int *a, int p, int r)
{
    int q;
    if(p < r)
    {
        q = (p + r) / 2;
        mergeSort(a, p , q);
        mergeSort(a, q + 1, r);
        mergeArray(a, p, q, r);
    }
}

int main()
{
    int a[] = {3, 5, 1, 2, 9, 6, 4, 0};
    int i = 0;
    for(i = 0; i < 8; i++)
        printf("%d\t", a[i]);
    mergeSort(a, 0, 7);

    printf("\n");
    for(i = 0; i < 8; i++)
        printf("%d\t", a[i]);
    return 0;
}


