static int spawn_proc(int fd_in, int fd_out, int fd_close,
		      const char *cmd)
{
	pid_t pid;

	pid = fork();

	if (pid != 0)
		return pid;

	close(fd_close);

	if (fd_in != STDIN_FILENO) {
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
	}

	if (fd_out != STDOUT_FILENO) {
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
	}

	return execlp(cmd, cmd, NULL);
}

static int pipe_to_hd_less(struct switchtec_dev *dev, gasptr_t map,
			   size_t map_size)
{
	int hd_fds[2];
	int less_fds[2];
	int less_pid, hd_pid;
	int ret;

	ret = pipe(less_fds);
	if (ret) {
		perror("pipe");
		return -1;
	}

	less_pid = spawn_proc(less_fds[0], STDOUT_FILENO, less_fds[1], "less");
	if (less_pid < 0) {
		perror("less");
		return -1;
	}
	close(STDOUT_FILENO);
	close(less_fds[0]);

	ret = pipe(hd_fds);
	if (ret) {
		perror("pipe");
		return -1;
	}

	hd_pid = spawn_proc(hd_fds[0], less_fds[1], hd_fds[1], "hd");
	if (hd_pid < 0) {
		perror("hd");
		return -1;
	}

	close(hd_fds[0]);
	close(less_fds[1]);

	ret = write_from_gas(dev, hd_fds[1], map, map_size);
	close(hd_fds[1]);
	waitpid(less_pid, NULL, 0);
	return ret;
}
