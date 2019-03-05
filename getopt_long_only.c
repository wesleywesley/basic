#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

/*
./a.out 
--reqarg 100/--reqarg=100 
--optarg=200/--optarg (--optarg 200, false)
--noarg

*/

int main(int argc, char *argv[])
{
	int opt;
	char *short_opts = "a::b:c:d";
	int option_index = 0;
	int digit_optind = 0;

	static struct option long_options[] = {
		{"reqarg", required_argument, NULL, 'r'},
		{"optarg", optional_argument, NULL, 'o'},
		{"noarg", no_argument, NULL, 'n'},
		{},
	};

	while ((opt = getopt_long_only(argc, argv, short_opts, long_options, &option_index)) != -1)
	{
		printf("opt = %c\t\t", opt);
		printf("optarg = %s\t\t", optarg);
		printf("optind = %d\t\t", optind);
		printf("argv[optind] = %s\t\t", argv[optind]);
		printf("option index = %d\n", option_index);
	}
}
