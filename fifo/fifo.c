#include "common.h"

MODULE_LICENSE("Dual BSD/GPL");

//#define LOCK_VER

struct student {
	int id;
};

static struct student *stu[5];

static void print_student(struct student *);

static int fifo_init(void)
{
	struct kfifo *kfifo;
	int ret;
	int i;
	struct student stu_tmp;

	#if defined (LOCK_VER)
	spinlock_t sl; 
	spin_lock_init(&sl);
	printk(KERN_ALERT "LOCK VER");
	#else
	printk(KERN_ALERT "NO LOCK VER");
	#endif

	printk(KERN_ALERT "%s\n", __func__);

	kfifo = kzalloc(sizeof(*kfifo), GFP_KERNEL);
	if (kfifo ==  NULL)
		goto err;

	ret = kfifo_alloc(kfifo, PAGE_SIZE, GFP_KERNEL);
	if (ret)
		goto err;

	for (i = 0; i < ARRAY_SIZE(stu); i++) {
		stu[i] = kzalloc(sizeof(*stu[i]), GFP_KERNEL);
		if (stu[i] == NULL)
			goto err;

		stu[i]->id = i;
		
		//kfifo_in_spinlocked/out
		#if defined (LOCK_VER)
		ret = kfifo_in_spinlocked(kfifo, stu[i], sizeof(*stu[i]), &sl);
		//kfifo_in/out
		#else
		ret = kfifo_in(kfifo, stu[i], sizeof(*stu[i]));
		#endif

		if (ret != sizeof(*stu[i]))
			goto err;
	}

	printk(KERN_ALERT "+++ kfifo length %d +++\n", kfifo_len(kfifo));
	printk(KERN_ALERT "+++ kfifo available %d +++\n", kfifo_avail(kfifo));

	for (i = 0; i < ARRAY_SIZE(stu); i ++) {
		//kfifo_in_spinlocked/out
		#if defined (LOCK_VER)
		ret = kfifo_out_spinlocked(kfifo, &stu_tmp, sizeof(stu_tmp), &sl);
		//kfifo_in/out
		#else
		ret = kfifo_out(kfifo, &stu_tmp, sizeof(stu_tmp));
		#endif

		print_student(&stu_tmp);
	}

	printk(KERN_ALERT "--- kfifo length %d ---\n", kfifo_len(kfifo));
	printk(KERN_ALERT "--- kfifo avail %d ---\n", kfifo_avail(kfifo));

err:
	if (kfifo)
		kfifo_free(kfifo);

	for (i = 0; i < ARRAY_SIZE(stu); i++) {
		if (stu[i])
			kfree(stu[i]);
	}
	
	return 0;
	
}

static void fifo_exit(void)
{
	printk(KERN_ALERT "------\n");
	printk(KERN_ALERT "%s\n", __func__);
	printk(KERN_ALERT "------\n");
}

static void print_student(struct student *stu)
{
	printk(KERN_ALERT "======\n");
	print_time(1);
	printk(KERN_ALERT "id %d\n", stu->id);
	printk(KERN_ALERT "======\n");
	
}

module_init(fifo_init);
module_exit(fifo_exit);
