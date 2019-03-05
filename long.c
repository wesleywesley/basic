#include <stdio.h>

#define INVALID_POINTER_VALUE 0xFFFFFFFFL

long function(long l)
{
	return l;
}


int main()
{
	const signed long INVALID_PTR = 0xFFFFFFFF;

	int myint = 1;
	long mylong = 1;
	long long mylonglong = 1;
	printf("%d\n", myint);
	printf("%ld\n", mylong);
	printf("%lld\n", mylonglong);
	printf("------\n");

	ssize_t myssize_t = 1;
	size_t mysize_t = 1;
	printf("%lu\n", mysize_t);
	printf("%zu\n", mysize_t);
	printf("%ld\n", myssize_t);
	printf("%zd\n", myssize_t);
	printf("------\n");

	//printf("%d\n", INVALID_POINTER_VALUE);
	printf("%ld\n", INVALID_POINTER_VALUE);

	//printf("%d\n", INVALID_PTR);
	printf("%ld\n",INVALID_PTR);
	printf("------\n");
	
#if 0
	int i = -2;
	unsigned k = 1U;
	printf("sizeof(unsigned) %ld\n", sizeof(unsigned));
	long n = function(i+k);
#endif

//#if defined (__LP64__) || defined (_LP64) || defined (__64BIT__) || (__WORDSIZE == 64)
#if defined (__LP64__) 
	printf("1 __LP64__\n");
#endif

#if defined (_LP64)
	printf("2 _LP64\n");
#endif

#if defined (__64BIT__) // false
	printf("3 __64BIT__\n");
#endif

#if (__WORDSIZE == 64)
	printf("4 LP64\n");
#else
	printf("4 ILP32\n");
#endif
	printf("------\n");

	long k;
	int i = -2;
	unsigned int j = 1;
	k =  i + j;
	printf("long k = %ld, %lx\n", k, k);
	k =  i + (int)j;
	printf("long k = %ld, %lx\n", k, k);
	printf("------\n");

	printf("sizeof(unsigned) %ld\n", sizeof(unsigned));
	printf("------\n");

	printf("size of ptr %ld, size of void %ld\n", sizeof(void *), sizeof(void));
	printf("------\n");
}
