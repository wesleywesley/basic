#include <stdlib.h>
#include <stdio.h>
#include <linux/types.h>

//#define KERNEL

#ifdef KERNEL
#include <linux/uaccess.h>
#endif

int is_align(int ptr, int align)
{
	return (ptr % align);
}

int is_align2(int ptr, int align)
{
	return (ptr & (align - 1));
}

int main(int argc, char *argv[])
{
	int ret;
	int i;
	char *pos;
	int addr;
	int align;

	for(i = 0; i< argc;) {
		printf("argc [%d]: %s\n", i, argv[i]);
		i++;
	}

	addr = strtol(argv[1], &pos, 0);
	printf("addr %s 0x%x\n", argv[1], addr);

	align = strtol(argv[2], &pos, 0);
	printf("align %s 0x%x %d(dec)\n", argv[2], align, align);

#ifdef KERNEL
	printf("%d 0x%x\n", BIT_ULL(align), BIT_ULL(align));
#endif

#ifdef KERNEL
	ret = IS_ALIGNED(addr, align);
#endif

#if 1
	ret = is_align(addr, align);
	if (!ret)
		printf("align \n");
	else
		printf("not align \n");
#endif
		
	ret = is_align2(addr, align);
	if (!ret)
		printf("align \n");
	else
		printf("not align \n");
}
