#include <stdio.h>

int main()
{
#if 0
	unsigned char a = 254;
	printf("unsigned char a = %hhu\n", a);

	char b = a;
	printf("signed char b = %hhd\n", b);
#endif

#if 1
	int i = 0; 
	char b = 254;
	for (char a = 254; a < 254 && i < 255; a++) {
		i++;
		int val = b - a;
		printf("a = %hhu (%hhd), b = %hhu (%hhd), (char)(b) - (char)(a) = %hhd\n", a, a, b, b, val); 
	}

#endif

}
