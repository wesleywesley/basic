#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

int main()
{
	struct mw {
		uint32_t a;
		uint32_t b;
		uint32_t c ;
		uint64_t d[128];
		uint32_t e[128];
	};
	
	struct mw inst;

	printf("inst %p\n", &inst);
	printf("offset a %x\n", (void *)&inst.a - (void *)&inst);
	printf("offset a %x\n", (void *)&inst.b - (void *)&inst);
	printf("offset a %x\n", (void *)&inst.c - (void *)&inst);
	printf("offset a %x\n", (void *)&inst.d - (void *)&inst);
	printf("offset a %x\n", (void *)&inst.e - (void *)&inst);
/*
	printf("offset b %p\n", );
	printf("offset c %p\n", );
	printf("offset d %p\n", );
	printf("offset e %p\n", );
*/
}
