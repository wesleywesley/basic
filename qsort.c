#include <stdio.h>
#include <stdlib.h>


#define ARRAY_SIZE(a) (sizeof(a)/sizeof((a)[0]))

int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int array[] = {5, 4, 7, 9, 1, 2, 0};

	for (int i = 0; i < ARRAY_SIZE(array); i++)
		printf("array[%d] = %d\n", i, array[i]);	

	qsort(array, ARRAY_SIZE(array), sizeof(int), compare);

	for (int i = 0; i < ARRAY_SIZE(array); i++)
		printf("array[%d] = %d\n", i, array[i]);	
}

