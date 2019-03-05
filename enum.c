#include <stdio.h>

enum event_id {
	EVT_INVALID = -1,
	EVT_0,
	EVT_1,
	EVT_MAX,
};

int a[EVT_MAX];

#define ARRAY_SIZE(a) (sizeof(a)/(sizeof((a)[0])))

int main()
{
	printf("EVT_MAX = %d\n", EVT_MAX);
	printf("EVT_MAX + 1 = %d\n", EVT_MAX + 1);

	printf("size of a = %ld\n", ARRAY_SIZE(a));
}


