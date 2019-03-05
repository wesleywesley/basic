#include <stdio.h>

#define PDEBUG(fmt, args...) fprintf(stderr, fmt, ## args)

#define PRINTF(n) printf("token" #n "=%d\n", token##n)

int main(int argc, char **argv)
{
	PDEBUG("%s %d\n", __func__, 120);

	int token9 = 99;
	PRINTF(9);
}
