#include <linux/module.h>

/*This can be used ONLY by the M4U driver!*/
/*
 *      inner_dcache_flush_all()
 *
 *      Flush (clean + invalidate) the entire L1 data cache.
 *      This can be used ONLY by the M4U driver.
 *      Other drivers should NOT use this function at all. They should use DMA-mapping APIs.
 *
 *      After calling the function, the buffer should not be touched anymore.
 *      And the M4U driver should then call outer_flush_all() immediately.
 *      Here is the example:
 *          // Cannot touch the buffer from here.
 *          inner_dcache_flush_all();
 *          outer_flush_all();
 *          // Can touch the buffer from here.
 *      If preemption occurs and the driver cannot guarantee that no other process will touch the buffer,
 *      the driver should use LOCK to protect this code segment.
 */
void inner_dcache_flush_all(void)
{
    unsigned int way = 0x3; /* 4 ways */
    unsigned int set = 0xFF;    /* 32KB cache size */
    unsigned int Rt = 0;

    asm volatile(
        "1:\n"
        "mov %1, #3\n"
        "2:\n"
        "mov %0, #0\n"
        "orr %0, %0, %1, lsl #30\n"
        "orr %0, %0, %2, lsl #5\n"
        "mcr p15, 0, %0, c7, c14, #2\n"
        "subs %1, %1, #1\n"
        "bge 2b\n"
        "subs %2, %2, #1\n"
        "bge 1b\n"
        "dsb\n"
        "isb\n"
        : "+r" (Rt), "+r" (way), "+r" (set)
        : 
        : "cc"
    );
}

EXPORT_SYMBOL(inner_dcache_flush_all);
