#include <time.h>
#include <sys/time.h>
#include <sys/times.h>
#include <unistd.h>
#include <stdio.h>

void print_line()
{
	printf("======\n");
}

int main()
{
	int i;
	int ret;

	//sysconf
	long hz;
	hz = sysconf(_SC_CLK_TCK);
	if (hz == -1)
		perror("sysconf");
	fprintf(stdout, "hz %ld\n", hz);
	print_line();

	//time
	time_t t;
	printf("current time: %ld\n", (long)time(&t));
	printf("the same value: %ld\n", (long)t);
	print_line();

	//clock_getres
	clockid_t clocks[] = {
		CLOCK_REALTIME,
		CLOCK_MONOTONIC,
		CLOCK_PROCESS_CPUTIME_ID,
		CLOCK_THREAD_CPUTIME_ID,
		CLOCK_MONOTONIC_RAW,
		(clockid_t)-1
	};

	for (i = 0; clocks[i] != (clockid_t)-1; i++) {
		struct timespec res;

		ret = clock_getres(clocks[i], &res);
		if (ret == -1)
			perror("clock_getres");
		else
			printf("clock=%d sec=%ld, nsec=%ld\n",
			       clocks[i], res.tv_sec, res.tv_nsec);
	}
	print_line();

	//clock_gettime
	for (i = 0; clocks[i] != (clockid_t)-1; i++) {
		struct timespec ts;

		ret = clock_gettime(clocks[i], &ts);
		if (ret)
			perror("clock_gettime");
		else
			printf("clock=%d sec=%ld, nsec=%ld\n",
			       clocks[i], ts.tv_sec, ts.tv_nsec);
	}
	print_line();

	//gettimeofday
	struct timeval tv;
	ret = gettimeofday(&tv, NULL);
	if (ret)
		perror("gettimeofday");
	else
		printf("sec %ld, usec %ld\n",
		       tv.tv_sec, tv.tv_usec);
	print_line();


	//times
	struct tms buf;
	times(&buf);
	printf("ut %ld, st %ld, utc %ld, ust %ld\n",
	       buf.tms_utime, buf.tms_stime, buf.tms_cutime, buf.tms_cstime);
	print_line();
	

	
}
