#include <stdio.h>

int main()
{
	int *p;
	int (*ptr)[3];
	int array[] = {1,2,3};

	p = array;

	ptr = &array;

	printf("p = %p, ptr = %p\n", p, ptr);

	p++;
	ptr++;

	printf("p = %p, ptr = %p\n", p, ptr);

	printf("*p = %d, *ptr = %p\n", *p, *ptr);
	
	return 0;
	
}
