#include <stdio.h>
#include <string.h>

int main()
{
	const char *delims = ",; $";
	const char *str = " abc, 678; 9ab efg$666";
	char buf[1024];
	char *tok;

	printf("original string:%s\n", str);
	printf("delims:%s\n", delims);

	strcpy(buf, str);
	tok = strtok(buf, delims);

	while(tok != NULL) {
		printf("%s\n", tok);
		tok = strtok(NULL, delims);
	}
}
