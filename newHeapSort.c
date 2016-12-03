#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 *
 * 针对数组的堆排序
 *  @auth zhenma 
 *  @date 20161203
 */

void swap(int *a, int *b)
{
    if(a == NULL || b == NULL)
        return;

    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void maxHeapFy(int *p, int k, int length)
{
    int l = 2 * k + 1;
    int r = 2 * k + 2;
    int largest = k;

    if(l <= length - 1 && p[l] > p[k])
    {
        largest = l;
    }

    if(r <= length - 1 && p[r] > p[k] && p[r] > p[l])
    {
        largest = r;
    }

    if(largest != k)
    {
        swap(&p[largest], &p[k]);
        maxHeapFy(p, largest, length);
    }
}

void buildHeap(int *p, int length)
{
    int i;

    for(i = length / 2 - 1; i >= 0; i--)
    {
        maxHeapFy(p, i, length);
    }
}

void heapSort(int *p, int length)
{
    if(p == NULL)
        return;
    //建立堆结构
    buildHeap(p, length);

    int i;
    for(i = length - 1; i > 0; i--)
    {
        swap(&p[0], &p[i]);
        maxHeapFy(p, 0, i);
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

	for(i = 0; i < 10; i++)
	{
        printf("%d\t", a[i]);
	}
    
    printf("\n");

    heapSort(a, 10);

	for(i = 0; i < 10; i++)
	{
        printf("%d\t", a[i]);
	}
    
    printf("\n");

    return 0;
}

