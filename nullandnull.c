#include <stdio.h>

typedef int (*probe_fun)(void);
typedef void (*remove_fun)(void); 

int main()
{
	probe_fun probe;
	remove_fun remove;

	probe = NULL;
	remove = NULL;

	int a = probe && remove;
	printf("a = %d\n", a);

	int b = probe && remove && 1;
	printf("b = %d\n", b);
}
