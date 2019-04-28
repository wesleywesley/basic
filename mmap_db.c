#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int fd;
	int ret;
	struct stat stat;
	void *map;
	ssize_t msize;
	char partition[16] = {0};
	uint32_t db_offset;
	uint64_t db_bit;
	uint64_t *db_addr;
	unsigned long i;
	unsigned long cnt;
	uint64_t flush_mb;

	//for (i = 0; i < argc; i++)
	//	fprintf(stdout, "argv[%d]:%s\n", i, argv[i]);

	if (argc < 2) {
		fprintf(stdout, "usage: ./mmap_db <cnt>\n");
		return -1;
	}

	cnt = strtol(argv[1], NULL, 0);
	fprintf(stdout, "cnt: %ld\n", cnt);

	fd = open("/sys/class/switchtec/switchtec0/partition", O_RDONLY);
	if (fd < 0) {
		fprintf(stderr, "@@@ open: partition\n");
		return -1;
	}
	ret = read(fd, partition, sizeof(partition));
	if (ret < 0) {
		fprintf(stderr, "@@@ read: partition\n");
		close(fd);
		return -1;
	}
	close(fd);

	if (partition[0] == '0') {
		fprintf(stderr, "partition 0\n");
		db_offset = 0x74000;
		db_bit = 0x100000000;
	} else {
		fprintf(stderr, "partition 1\n");
		db_offset = 0x78000;
		db_bit = 0x1;
	}

	fd = open("/sys/class/switchtec/switchtec0/device/resource0", O_RDWR);
	if (fd < 0) {
		fprintf(stderr, "@@@ open: resource0\n");
		return -1;
	}

	ret = fstat(fd, &stat);
	if (ret < 0) {
		fprintf(stderr, "@@@ fstat\n");
		close(fd);
		return -1;
	}
	msize = stat.st_size;
	//fprintf(stdout, "msize %d %x\n", msize, msize);

	map = mmap(NULL, msize, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (map == NULL) {
		fprintf(stderr, "@@@ mmap PRIVATE\n");
		close(fd);
		return -1;
	}

	map = mmap(map + 0x1000, msize - 0x1000, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0x1000);
	close(fd);

	if (map == NULL) {
		fprintf(stderr, "@@@ mmap\n");
		return -1;
	}
	//fprintf(stdout, "msize %d %x\n", msize, msize);

	db_addr = (map + db_offset);
	for (i = 0; i < cnt; i++) {
		//Method for make compiler not combine the write
		//1, not work
		//asm volatile("":::"memory");
		//2. not work
		//flush_mb = *db_addr;
		//3. not work
		//fprintf(stdout, "%d\n", i);
		*db_addr = db_bit;
	}

	munmap(map, msize);

}
