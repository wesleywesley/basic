#include <stdio.h>
#include <unistd.h>
#include <linux/limits.h>

int main()
{
	char buf[PATH_MAX];
	char str[] = "/sys/class/switchtec/switchtec0";

	readlink(str, buf, sizeof(buf));

	printf("%s : %s\n", str, buf);
}
