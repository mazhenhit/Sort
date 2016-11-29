#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    return 0;
}

