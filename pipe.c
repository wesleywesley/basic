#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

//code with pipe/fork
//father write
//child read

int main(int argc, char *argv)
{
	int fd[2];
	int ret;
	int pid;
	char *msg = "message from father";
	char buf[1024];

	ret = pipe(fd);
	if (ret < 0) {
		//printf("%s: pipe return error\n", __func__);
		perror("pipe");
		exit(1);
	}

	pid = fork();
	if (pid < 0) {
		//printf("%s: fork return error, pid = %d\n", __func__, pid);
		perror("fork");
		exit(1);
	}

	if (pid) {
		// farther process
		close(fd[0]);
		
		ret = write(fd[1], msg, strlen(msg));
		if (ret < 0)
			exit(1);
	}
	else {
		// child process
		close(fd[1]);
		
		ret = read(fd[0], buf, sizeof(buf));
		if (ret < 0)
			exit(1);
		printf("print: %s\n", buf);
	}
}
