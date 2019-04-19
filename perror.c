#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
	errno = 0;
	perror("errno = 0");	

	errno = 1;
	perror("errno = 1");	

	errno = 2;
	perror("errno = 2");	

	errno = 3;
	perror("errno = 3");	

	errno = ENXIO;
	printf("ENXIO %d : %d\n", errno, ENXIO);
	perror("errno = ENXIO");	

	
	errno = 6;
	perror("errno = 6");	

	errno = 8;
	perror("errno = 8");

	errno = ENOEXEC;
	perror("errno = ENOEXEC");

	errno = EBUSY;
	printf("EBUSY %d : %d\n", errno, EBUSY);
	perror("errno = EBUSY");	

	printf("+++ strerror ---\n");
	errno = EBUSY;
	printf("%s\n", strerror(errno));
}
