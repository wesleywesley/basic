#include <stdlib.h> 
#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;
	int ret;
	unsigned int uret;
	char *ptr;

	if (argc < 2) {
		printf("Usage: ./a.out <input>\n");
		return -1;
	}

	for (i = 1; i < argc; i++) {
		printf("argv[%d] = %s\n", i, argv[i]);

		ret = strtol(argv[i], &ptr, 0);
		printf("strtol %d, %u, 0x%x\n", ret, ret, ret);
		printf("%s\n", ret > 0 ? "> 0" : "< 0");

		uret =  strtoul(argv[i], &ptr, 0);
		printf("strtoul %d, %u, 0x%x\n", uret, uret, uret);
		printf("%s\n", uret > 0 ? "> 0" : "< 0");
	}

	printf("sizeof(long long) %ld\n", sizeof(long long));
	printf("sizeof(long int) %ld\n", sizeof(long int));
	printf("sizeof(int) %ld\n", sizeof(int));

	printf("sizeof(unsigned long long) %ld\n", sizeof(unsigned long long));
	printf("sizeof(unsinged long int) %ld\n", sizeof(unsigned long int));
	printf("sizeof(unsigned int) %ld\n", sizeof(unsigned int));
}
