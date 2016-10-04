#include <stdio.h>
#include <Stdlib.h>

/**
 *
 * 计算排序
 *
 * */
void countSort(int *num, int length, int key)
{
	int tmp[length];
	int count[key + 1];

	int i;
	/* 初始化计数数组 */
	for(i = 0; i <= key; i++)
		count[i] = 0;

	for(i = 0; i < length; i++)
		count[num[i]]++;
	
	for(i = 1; i <= key; i++)
		count[i] += count[i - 1];
	
	for(i = length - 1; i >= 0; i--)
		tmp[--count[num[i]]] = num[i];

	for(i = 0; i < length; i++)
		num[i] = tmp[i];
}

/**主函数*/
int main()
{
	int num[] = {5, 3, 2, 1, 6, 7, 4, 9, 0, 8};
	countSort(num, 10, 10);

	int i = 0;
	for(i = 0; i < 10; i++)
	{
		printf("%d\t", num[i]);
	}

	return 0;
}

