#include <linux/init.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>

MODULE_LICENSE("Dual BSD/GPL");

struct student {
	int id;
	struct list_head list;
};

static struct student *stu[5];

static void print_student(struct student *);

static int list_init(void)
{
	struct student *student;
	int i;

	LIST_HEAD(list_head);

	if (list_empty(&list_head))
		printk(KERN_ALERT "list init\n");	

	for (i = 0; i < ARRAY_SIZE(stu); i++) {
		//stu[i] = kmalloc(sizeof(struct student), GFP_KERNEL);
		stu[i] = kmalloc(sizeof(*stu[i]), GFP_KERNEL);
		if (stu[i] == NULL)
			goto err;
		stu[i]->id = i;
		INIT_LIST_HEAD(&stu[i]->list);
		list_add_tail(&stu[i]->list, &list_head);
	}

	if (!list_empty(&list_head))
		printk(KERN_ALERT "list init done\n");	

	list_for_each_entry(student, &list_head, list) {
		print_student(student);
	}

	list_for_each_entry_reverse(student, &list_head, list) {
		print_student(student);
	}

	return 0;

err:
	printk(KERN_ALERT "err\n");
	for (i = 0; i < ARRAY_SIZE(stu); i++) {
		if (stu[i])
			kfree(stu[i]);
	}
		
	return 0;

}

static void list_exit(void)
{
	int i;

	printk(KERN_ALERT "------\n");	
	printk(KERN_ALERT "list exit\n");	
	for (i = 0; i < ARRAY_SIZE(stu); i++) {
		if (stu[i])
			kfree(stu[i]);
	}
	printk(KERN_ALERT "------\n");	
}

static void print_student(struct student *student)
{
	printk(KERN_ALERT "======\n");
	printk(KERN_ALERT "id = %d\n", student->id);
	printk(KERN_ALERT "======\n");
}

module_init(list_init);
module_exit(list_exit);
