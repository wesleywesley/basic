#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
	if (getenv("SWITCHTEC_COMPLETE"))
		printf("string %s\n", getenv("SWITCHTEC_COMPLETE"));
	else
		printf("null case %p\n", getenv("SWITCHTEC_COMPLETE"));

	if (getenv("TERM"))
		printf("TERM %s\n", getenv("TERM"));
	else
		printf("null case %p\n", getenv("TERM"));
		
}


