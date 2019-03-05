#include "common.h"
#include <linux/rbtree.h>

MODULE_LICENSE("Dual BSD/GPL");

struct student {
	int id;
	struct rb_node node;
};

static struct student *stu[5];

static void print_student(struct student *);

static int insert(struct student *, struct rb_root *);
static int remove(struct student *, struct rb_root *);
static int display(struct rb_root *, int);
static int display_from_big(struct rb_root *);
static int display_from_sml(struct rb_root *);

static int rbtree_init(void)
{
	struct rb_root root = RB_ROOT;
	int i;
 	for (i = 0; i < ARRAY_SIZE(stu); i++) {
		stu[i] = kzalloc(sizeof(*stu[i]), GFP_KERNEL);
		if (!stu[i])
			goto err;
		stu[i]->id = i;
		stu[i]->node.rb_left = NULL;
		stu[i]->node.rb_right = NULL;
	}
		
 	for (i = 0; i < ARRAY_SIZE(stu); i++) {
		printk(KERN_ALERT "id = %d\n", stu[i]->id);
	}

 	for (i = 0; i < ARRAY_SIZE(stu); i++) {
		insert(stu[i], &root);
	}

	printk(KERN_ALERT "small\n");
	display(&root, -1);
	printk(KERN_ALERT "big\n");
	display(&root, 1);

	printk(KERN_ALERT "remove stu[3]\n");
	remove(stu[3], &root);
	display(&root, -1);

err:
 	for (i = 0; i < ARRAY_SIZE(stu); i++) {
		if (stu[i])
			kfree(stu[i]);
	}

	return 0;
}

static void print_student(struct student *student)
{
	printk(KERN_ALERT "======\n");
	printk(KERN_ALERT "id = %d\n", student->id);
	printk(KERN_ALERT "======\n");
}

static void rbtree_exit(void)
{
	printk(KERN_ALERT "------\n");	
	printk(KERN_ALERT "%s exit\n", __func__);	
	printk(KERN_ALERT "------\n");	
}

module_init(rbtree_init);
module_exit(rbtree_exit);
