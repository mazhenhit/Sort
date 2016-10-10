#include <stdio.h>
#include <stdlib.h>

/** 调整堆结构 */
void maxHeapIfy(int *a, int i, int length)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;

    if(left <= length && a[left] > a[i] && a[left] > a[right])
    {
        largest = left;
    }
    else if(right <= length && a[right] > a[i] && a[right] > a[left])
    {
        largest = right;
    }
    else
    {
        largest = i;
    }

    if(largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        maxHeapIfy(a, largest, length);
    }
}

/** 建堆 */
void buildMaxHeap(int *a, int length)
{
    int i;

    for(i = length / 2; i >= 1; i--)
    {
        maxHeapIfy(a, i, length);
    }
}

/** 堆排序 */
void heapSort(int *a, int length)
{
    int i;

    buildMaxHeap(a, length);

    for(i = length; i >= 2; i--)
    {
        int temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        maxHeapIfy(a, 1, --length);
    }
}

/** 主函数 */
int main()
{
    int a[] = {1, 4, 7, 3, 2, 8};
    int length = 5;
    heapSort(a, length);

    int i;
    for(i = 1; i <= length; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\n");
}


