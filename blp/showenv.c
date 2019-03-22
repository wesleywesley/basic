#include <stdlib.h>
#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[])
{
	char **temp;
	temp = environ;

	while (*temp) {
		printf("%s\n", *temp);
		temp++;
	}
}
