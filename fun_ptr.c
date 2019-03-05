#include <stdio.h>

#define ARRAY_SIZE(a) ((sizeof(a))/(sizeof((a)[0])))

int print_foo(int tmp)
{
	printf("%s: tmp %d\n", __func__, tmp);
}

typedef int (*fun_ptr)(int);
fun_ptr func[3];

typedef int fun(int);
fun *func2[3];

int main()
{
	int (*foo)(int);

	foo = print_foo;
	foo(8899);	

	foo = &print_foo;
	foo(7788);

	for (int i = 0; i < ARRAY_SIZE(func); i++)
		func[i] = print_foo;

	for (int i = 0; i < ARRAY_SIZE(func); i++)
		func[i](i);

	for (int i = 0; i < ARRAY_SIZE(func2); i++)
		func2[i] = print_foo;
		
	for (int i = 0; i < ARRAY_SIZE(func2); i++)
		func2[i](i+3);
}
