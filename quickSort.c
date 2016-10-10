#include <stdio.h>
#include <stdlib.h>

/**交换两个数字*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**拆分为两个部分*/
int patition(int *num, int left, int right)
{
	int tmp = num[right];

	while(left < right)
	{
		while(left < right && num[left] <= tmp)
		{
			left++;
		}

		swap(&num[left], &num[right]);

		while(left < right && num[right] >= tmp)
		{
			right--;
		}

		swap(&num[left], &num[right]);
	}
	return left;
}

/**快速排序*/
void quickSort(int *num, int left, int right)
{
	int tmp;

	if(left < right)
	{
		tmp = patition(num, left, right);
		quickSort(num, left, tmp - 1);
		quickSort(num, tmp + 1, right);
	}
}

/**主函数*/
int main()
{
	int i = 0;
	int a[] = {0, 4, 2, 8, 5, 9, 1, 3, 7, 6};

	quickSort(a, 0, 9);

	for(i = 0; i < 10; i++)
	{
		printf("%d\t", a[i]);
	}
	return 0;
}

