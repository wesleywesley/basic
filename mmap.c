#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>

int main()
{
	int fd;
	void *map;

	fd = open("/sys/class/switchtec/switchtec0/device/resource2_wc", O_RDWR);
	if (fd < 0) {
		fprintf(stderr, "@@@ open\n");
		return -1; 
	}

	map = mmap(NULL, 4096, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
	close(fd);

	if (map == NULL) {
		fprintf(stderr, "@@@ mmap\n");
		return -1; 
	}

	fprintf(stdout, "%x\n", *(uint32_t *)map);
}
