#ifndef __aed_h
#define __aed_h

#include <linux/autoconf.h>
#include <linux/bug.h>
#include <linux/aee.h>
#include <linux/xlog.h>


#define AE_INVALID              0xAEEFF000
#define AE_NOT_AVAILABLE        0xAEE00000
#define AE_DEFAULT              0xAEE00001

typedef enum {
    AE_SUCC, 
    AE_FAIL
} AE_ERR;

typedef enum {
    AE_PASS_BY_MEM,
    AE_PASS_BY_FILE,
    AE_PASS_METHOD_END  
} AE_PASS_METHOD;

typedef enum {AE_REQ, AE_RSP, AE_IND, AE_CMD_TYPE_END}        AE_CMD_TYPE;

typedef enum  {
    AE_REQ_IDX,

    AE_REQ_CLASS,
    AE_REQ_TYPE,
    AE_REQ_PROCESS,
    AE_REQ_MODULE,
    AE_REQ_BACKTRACE,
    AE_REQ_DETAIL,    /* Content of response message rule:
                       *   if msg.arg1==AE_PASS_BY_FILE => msg->data=file path 
                       */
    
    AE_REQ_ROOT_LOG_DIR,
    AE_REQ_CURR_LOG_DIR,
    AE_REQ_DFLT_LOG_DIR,
    AE_REQ_MAIN_LOG_FILE_PATH,    

    AE_IND_FATAL_RAISED, // fatal event raised, indicate AED to notify users
    AE_IND_EXP_RAISED,   // exception event raised, indicate AED to notify users      
    AE_IND_WRN_RAISED,   // warning event raised, indicate AED to notify users    
    AE_IND_REM_RAISED,   // reminding event raised, indicate AED to notify users    

    AE_IND_LOG_STATUS, // arg = AE_ERR
    AE_IND_LOG_CLOSE,  // arg = AE_ERR

    AE_REQ_SWITCH_DAL_BEEP, // arg: dal on|off, seq: beep on|off
    AE_REQ_DB_COUNT, 		// arg: db count
    AE_REQ_DB_FORCE_PATH,   // arg: force db path yes\no
    AE_REQ_SWITCH_EXP_LEVEL,
    AE_REQ_IS_AED_READY,    // query if AED is ready for service
    AE_REQ_COREDUMP,        // msg->data=file path
    AE_REQ_SET_READFLAG,    // set read flag msg
    AE_REQ_E2S_INIT,        // Init notification of client side(application layer) of Exp2Server
    AE_CMD_ID_END
} AE_CMD_ID;

typedef struct {
    AE_CMD_TYPE    cmdType; // command type
    AE_CMD_ID      cmdId;   // command Id
    unsigned int   seq;     // sequence number for error checking
    unsigned int   arg;     // simple argument
    unsigned int   len;     // dynamic length argument
} AE_Msg;

/* Kernel IOCTL interface */
struct aee_dal_show {
	char msg[1024];
};

struct aee_dal_setcolor {
	unsigned int foreground;
	unsigned int background;
};

#define AEEIOCTL_DAL_SHOW      _IOW('p', 0x01, struct aee_dal_show) /* Show string on DAL layer  */
#define AEEIOCTL_DAL_CLEAN     _IO('p', 0x02) /* Clear DAL layer */
/* AEEIOCTL_BEEP 0x03 Beep (ms), removed */
#define AEEIOCTL_SETCOLOR      _IOW('p', 0x04, struct aee_dal_setcolor) /* RGB color 0x00RRGGBB */

/* AED debug support */

struct proc_dir_entry;

int aed_proc_debug_init(struct proc_dir_entry *aed_proc_dir);
int aed_proc_debug_done(struct proc_dir_entry *aed_proc_dir);

#define AEK_LOG_TAG "aee/aek"

#endif
