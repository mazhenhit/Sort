#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
	int a[] = {0, 4, 2, 8, 5, 9, 1, 3, 7, 6};

//	quickSort(a, 0, 9);

	for(i = 0; i < 10; i++)
	{
		printf("%d\t", a[i]);
	}
    printf("\n");

    return 0;
}

