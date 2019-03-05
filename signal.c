#include <signal.h>
#include <unistd.h>
#include <stdio.h>

/*

jobs/fg/bg/ps -aux/kill -9 [pid]/ctrl+x

*/

void sigroutine(int dunno)
{
	printf("Get a signal -- %d\n", dunno);

	switch (dunno) {
		case 1:
		
		printf("Get a signal SIGHUP-- %d\n", dunno);
		break;

		case 2:
		printf("Get a signal SIGINT-- %d\n", dunno);
		break;

		case 3:
		printf("Get a signal SIGQUIT -- %d\n", dunno);
		break;
	}
}

int main(int argc, char *argv[])
{
	printf("pid is %d\n", getpid());

	signal(SIGBUS, sigroutine);
	signal(SIGHUP, sigroutine);
	signal(SIGINT, sigroutine);
	signal(SIGBUS, sigroutine);

	while (1);
}
