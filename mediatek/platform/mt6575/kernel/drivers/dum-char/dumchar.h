#ifndef __DUMCHAR_H__
#define __DUMCHAR_H__


#include <linux/ioctl.h>
#include <linux/cdev.h>
#include <linux/mtd/mtd.h>
#include <linux/semaphore.h>

/*
 * Macros to help debugging
 */
#define DUMCHAR_DEBUG
//#undef DUMCHAR_DEBUG             /* undef it, just in case */

#ifdef DUMCHAR_DEBUG
#define DDEBUG(fmt, args...) printk( KERN_DEBUG "dumchar_debug: " fmt, ## args)
#else
#define DDEBUG(fmt, args...) 
#endif


#define DUMCHAR_MAJOR        0   /* dynamic major by default */
#define MAX_SD_BUFFER		(512)
#define ALIE_LEN		512

#define  PMT_MAGIC	 'p'
#define PMT_READ		_IOW(PMT_MAGIC, 1, int)
#define PMT_WRITE 		_IOW(PMT_MAGIC, 2, int)

//#define PrintBuff 1

struct dumchar_dev {
	char *dumname;	//nvram boot userdata...
	char actname[64];	//full act name /dev/mt6573_sd0 /dev/mtd/mtd1	
	struct semaphore sem;     /* Mutual exclusion */
	dev_type type; //nand device or emmc device?
	unsigned long long size; //partition size
	struct cdev cdev;	
	Region region; //for emmc
	unsigned long long start_address; //for emmc
	unsigned int mtd_index;	 //for nand
};

struct Region_Info {
	Region region;
	unsigned long long	size_Byte;
};

struct file_obj {
	struct file *act_filp; 
	int index; //index in dumchar_dev arry
};


struct msdc_ioctl{
	int  opcode;
	int  host_num;
	int  iswrite;
	int  trans_type;
	u32  total_size;
	u32  address;
	u32* buffer;
	int  cmd_pu_driving;
	int  cmd_pd_driving;
	int  dat_pu_driving;
	int  dat_pd_driving;
	int  clk_pu_driving;
	int  clk_pd_driving;
	int  clock_freq;
    Region region;
	int  result;
};
#define REGION_NUM 						8
#define EXT_CSD_BOOT_SIZE_MULT          226 /* R */
#define EXT_CSD_RPMB_SIZE_MULT          168 /* R */

#define	MSDC_RAW_DEVICE					"/dev/misc-sd"
#define MSDC_DRIVING_SETTING              (0)
#define MSDC_CLOCK_FREQUENCY              (1)
#define MSDC_SINGLE_READ_WRITE            (2)
#define MSDC_MULTIPLE_READ_WRITE          (3)
#define MSDC_GET_CID                      (4)
#define MSDC_GET_CSD                      (5)
#define MSDC_GET_EXCSD                    (6)
#define MSDC_CARD_DUNM_FUNC               (0xff)


#define mtd_for_each_device(mtd)			\
	for ((mtd) = __mtd_next_device(0);		\
	     (mtd) != NULL;				\
	     (mtd) = __mtd_next_device(mtd->index + 1))

#endif /*__DUMCHAR_H__ */

