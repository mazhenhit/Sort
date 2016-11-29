#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeArray(int *p, int l, int m, int r)
{
    int lenA = m - l + 1;
    int lenB = r - m;

    if(p == NULL)
        return;

    int *pA = (int *)malloc(lenA * sizeof(int));
    int *pB = (int *)malloc(lenB * sizeof(int));

    int i, j, k;

    for(i = 0; i < lenA; i++)
    {
        pA[i] = p[i + l];
    }

    for(i = 0; i < lenB; i++)
    {
        pB[i] = p[i + m + 1];
    }

    for(i = 0, j = 0, k = l; i < lenA && j < lenB; k++)
    {
        if(pA[i] <= pB[j])
        {
            p[k] = pA[i++];
        }
        else
        {
            p[k] = pB[j++];
        }
    }

    while(i < lenA)
        p[k++] = pA[i++];

    while(j < lenB)
        p[k++] = pB[j++];

    free(pA);
    free(pB);
}

void mergeSort(int *p, int l, int r)
{
    if(p == NULL)
        return;
    
    if(l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(p, l, mid);
        mergeSort(p, mid + 1, r);
        mergeArray(p, l, mid, r);
    }
}

int main()
{
    int i = 0;
    int a[10] = {0};

    srand(time(0));

	for(i = 0; i < 10; i++)
	{
        a[i] = rand() % 10;
	}

    mergeSort(a, 0, 9);

	for(i = 0; i < 10; i++)
	{
        printf("%d\t", a[i]);
	}
    
    printf("\n");
    return 0;
}


