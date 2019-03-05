#include <stdio.h>

int main()
{
	int x = 1;

	printf("char x = %hhd\n", (char)x);


	if (*(char *)&x == 1)
		printf("little\n");
	else
		printf("big\n");


	union data {
		int a;
		char b;
	};

	union data inst;
	inst.a = 1;

	printf("union data inst.b %hhd\n", inst.b);
	
}
	
