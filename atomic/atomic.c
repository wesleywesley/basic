#include "common.h"
#include <asm/atomic.h>
#include <linux/cred.h>

MODULE_LICENSE("Dual BSD/GPL");

static atomic_t atom = ATOMIC_INIT(1);
static uid_t owner;
static uid_t eowner;

static int atomic_init(void)
{
	if (!atomic_dec_and_test(&atom))	
		printk(KERN_ALERT "return 0\n");
	else
		printk(KERN_ALERT "return !0\n");

	owner = current_uid().val;
	eowner = current_euid().val;
	printk(KERN_ALERT "owner %d, eowner %d\n", owner, eowner);

	return -ENODEV;
}

static void atomic_exit(void)
{

}

module_init(atomic_init);
module_exit(atomic_exit);
