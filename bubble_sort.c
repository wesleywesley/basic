#include <stdio.h>

#define ARRAY_SIZE(a) ((sizeof(a))/(sizeof(a[0]))) 

int main()
{
	int a[] = {13, 2, 6, 99, 78, 65, 32, 89, 90};
	int i;
	int j;
	int temp;
	
	for (i = 0; i < ARRAY_SIZE(a); i++)
		printf("a[%d]:%d\n", i, a[i]);

	printf("------\n");
	
	for (i = 0; i < ARRAY_SIZE(a)-1; i++) {
	//for (i = 0; i < ARRAY_SIZE(a); i++) {
		for (j = 0; j < ARRAY_SIZE(a) - i - 1; j++) {
			printf("B: a[%d]=%d, a[%d]=%d\n", j, a[j], j+1, a[j+1]);
			if (a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp; 
			}
			printf("A: a[%d]=%d, a[%d]=%d\n", j, a[j], j+1, a[j+1]);
		}
	}

	for (i = 0; i < ARRAY_SIZE(a); i++)
		printf("a[%d]:%d\n", i, a[i]);
}
	

