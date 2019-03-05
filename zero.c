#include <stdio.h>
#include <string.h>

int main()
{
	if (0 == '\0')
		printf("equal\n");
	else
		printf("not equal\n");

	char buf[] = "abcde";
	printf("str leng %ld\n", strlen(buf));
	const char *str = "abcde";
	printf("str leng %ld\n", strlen(str));
}
