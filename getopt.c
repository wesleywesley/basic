#include <stdio.h>
#include <unistd.h>
#include <getopt.h>


/* 
a::, argument optional, -a200
b: , argument must, -b 100, -b100, (-b=100 false)
c: , same as b:
d  , no argument, -d
*/

int main(int argc, char *argv[])
{
	int opt;
	char *short_opts = "a::b:c:d"; 

	while ((opt = getopt(argc, argv, short_opts)) != -1)
	{
		printf("opt = %c\t\t", opt);
		printf("optarg = %s\t\t", optarg);
		printf("optind = %d\t\t", optind);
		printf("argv[optind] = %s\n", argv[optind]);
	}
}
