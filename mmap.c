#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(array) (sizeof(array)/sizeof((array)[0]))

struct shared_mw {
	uint32_t magic;
	uint32_t link_sta;
	uint32_t partition_id;
	uint64_t mw_size[128];
	uint32_t spad[128];
};

int main(int argc, char *argv[])
{
	int fd;
	void *map;
	int ret;
	int i, j;
	unsigned long cnt;
	struct shared_mw shared_mw;
	int read;

	for (i = 0; i < argc; i++)
		fprintf(stdout, "argv[%d]:%s\n", i, argv[i]);

	if (argc < 3) {
		fprintf(stderr, "usage ./mmap <cnt> <r/w>\n");
		return -1;
	}

	cnt = strtol(argv[1], NULL, 0);
	fprintf(stdout, "cnt: %ld\n", cnt);

	read = argv[2][0] == 'r' ? 1 : 0;
	fprintf(stdout, "%s\n", read ? "read" : "write");

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

	for (i = 0; i < cnt; i++) {
		if (read) {
			memcpy(&shared_mw, map, sizeof(shared_mw));

			fprintf(stdout, "magic %x\n", shared_mw.magic);
			//fprintf(stdout, "link_sta %x\n", shared_mw.link_sta);
			//fprintf(stdout, "partition %x\n", shared_mw.partition_id);

			for (j = 0; j < ARRAY_SIZE(shared_mw.mw_size); j++) {
				//fprintf(stdout, "mw_size[%d] %lx\n", j, shared_mw.mw_size[j]);
			}
		} else {
			memcpy(map, &shared_mw, sizeof(shared_mw));
		}
	}

	munmap(map, 4096);
}
