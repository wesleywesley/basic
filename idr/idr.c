#include "common.h"
#include <linux/idr.h>

MODULE_LICENSE("Dual BSD/GPL");

struct student {
	int id;
};

static struct student *stu[5];

static void print_student(struct student *);

static int test_idr_init(void)
{
	DEFINE_IDR(idp);
	int id, ret, i;

	printk(KERN_ALERT "------\n");
	printk(KERN_ALERT "%s INIT\n", __func__);
	printk(KERN_ALERT "------\n");

	for (i = 0; i < ARRAY_SIZE(stu); i++) {
		stu[i] = kzalloc(sizeof(*stu[i]), GFP_KERNEL);
		if (!stu[i])
			goto err;
		stu[i]->id = i;
	}

	for (i = 0; i < ARRAY_SIZE(stu); i++) {
		do {
			if (!idr_pre_get(&idp, GFP_KERNEL))
				return -ENOSPC;
			ret = idr_get_new(&idp, stu[i], &id);
			printk(KERN_ALERT "id = %d\n", id);
		} while (ret == -EAGAIN);
	}

	print_time(0);

err:
	for (i = 0; i < ARRAY_SIZE(stu); i++) {
		if (!stu[i])
			kfree(stu[i]);
	}

	idr_destroy(&idp);

	return 0;
}

static void test_idr_exit(void)
{
	printk(KERN_ALERT "------\n");
	printk(KERN_ALERT "%s EXIT\n", __func__);
	printk(KERN_ALERT "------\n");
}

module_init(test_idr_init);
module_exit(test_idr_exit);
