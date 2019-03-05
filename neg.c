#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>

int  main()
{
/*
	int8_t b8 = 0xff;
	int16_t b16 = 0xffff;
	int32_t b32 = 0xffffffff;
	uint32_t ub32 = 0xffffffff;

	uint8_t	t8 = 0;

	printf("%x %d %d\n", b8, b8, sizeof(b8));
	printf("%x %d\n", b16, b16);
	printf("%x %d\n", b32, b32);
	printf("%x %d\n", ub32, ub32);

	t8 = t8 - 1;
	printf("%x %hhu\n", t8, t8);


	errno = 12;
	printf("%m\n");
*/

	/* printf */
	uint8_t u8 = 0xff;
	printf("u8=0xff, (%%ld) %ld, (%%lld) %lld, (%%d) %d, (%%hd) %hd, (%%hhd) %hhd\n", u8, u8, u8, u8, u8);
	printf("u8=0xff, (%%lu) %lu, (%%llu) %llu, (%%u) %u, (%%hu) %hu, (%%hhu) %hhu\n", u8, u8, u8, u8, u8);
	printf("u8=0xff, (%%zu) %zu\n", u8);
	printf("u8=0xff, (%%zx) %zx\n", u8);
	printf("u8=0xff, (%%zX) %zX\n", u8);
	printf("u8=0xff, (%%zd) %zd\n", u8);
	printf("u8=0xff, (%%zi) %zi\n", u8);

	printf("u8=0xff, (%%08x) %08x\n", u8);
	printf("u8=0xff, (%%08d) %08d\n", u8);

	printf("\033[1mChoices for %s: \033[0m\n", "test");
	printf("Choices for %s:\n", "test");

	printf("%s\n", __func__);

	printf("%-15s %s\n", "version", "shows the program version");
	printf("%15s %s\n", "version", "shows the program version");

	printf("*\n");

	printf("%06X - 0x%0*" "llX" "\n", 0x2000, 5, 8);

	/* convert */

	uint8_t us8 = 0xff;
	uint8_t tmp = 0;

	uint16_t us16 = 0xffff;
	uint16_t tmp16 = 0;
	uint32_t us32 = 0xffffffff;
	uint32_t tmp32 = 0;
	uint64_t us64 = 0xffffffffffffffff;
	uint64_t tmp64 = 0;

	tmp = tmp -1;
	printf("tmp, (%%ld) %ld, (%%lld) %lld, (%%d) %d, (%%hd) %hd, (%%hhd) %hhd\n", tmp, tmp, tmp, tmp, tmp);
	printf("tmp, (%%lu) %lu, (%%llu) %llu, (%%u) %u, (%%hu) %hu, (%%hhu) %hhu\n", tmp, tmp, tmp, tmp, tmp);

	if (us8 == tmp)
		printf("equal us8 : tmp\n");
	else
		printf("not equal us8 : tmp\n");

	tmp16 = tmp16 -1;
	tmp32 = tmp32 - 1;
	tmp64 = tmp64 -1;

	if (us16 == tmp16)
		printf("equal us16 : tmp\n");
	else
		printf("not equal us16 : tmp\n");

	if (us32 == tmp32)
		printf("equal us32 : tmp\n");
	else
		printf("not equal us32 : tmp\n");

	if (us64 == tmp64)
		printf("equal us64 : tmp\n");
	else
		printf("not equal us64 : tmp\n");


	//uint32_t temp = 1;
	unsigned int temp = 1;
	printf("temp = %d, !temp = %d\n", temp, !temp);

	temp = 2; 
	printf("temp = %d, !temp = %d\n", temp, !temp);

	temp = 0xf; 
	printf("temp = %d, !temp = %d\n", temp, !temp);

}
