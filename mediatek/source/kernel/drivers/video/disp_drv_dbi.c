#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/semaphore.h>

#include <linux/disp_assert_layer.h>
#include "disp_drv.h"
#include "disp_drv_platform.h"
#include "disp_drv_log.h"
#include "lcd_drv.h"
#include "lcm_drv.h"
#include "dpi_drv.h"
#include "dsi_drv.h"

// ---------------------------------------------------------------------------
//  Private Variables
// ---------------------------------------------------------------------------

extern LCM_DRIVER *lcm_drv;
extern LCM_PARAMS *lcm_params;



// ---------------------------------------------------------------------------
//  Private Functions
// ---------------------------------------------------------------------------

static BOOL disp_drv_dbi_init_context(void)
{
    if (lcm_drv != NULL && lcm_params!= NULL) 
		return TRUE;
    else 
		printk("%s, lcm_drv=0x%08x, lcm_params=0x%08x\n", __func__, (unsigned int)lcm_drv, (unsigned int)lcm_params);

	printk("%s, lcm_drv=0x%08x\n", __func__, (unsigned int)lcm_drv);
    if (NULL == lcm_drv) {
		printk("%s, lcm_drv is NULL\n", __func__);
        return FALSE;
    }

    lcm_drv->get_params(lcm_params);


    return TRUE;
}

#define ALIGN_TO(x, n)  \
	(((x) + ((n) - 1)) & ~((n) - 1))

static UINT32 get_fb_size(void)
{
    return ALIGN_TO(DISP_GetScreenWidth(), 32) * 
           ALIGN_TO(DISP_GetScreenHeight(), 32) * 
           ((DISP_GetScreenBpp() + 7) >> 3) * 
           DISP_GetPages();
}


static void init_assertion_layer(UINT32 fbVA, UINT32 fbPA)
{
    UINT32 offset = get_fb_size();
    DAL_STATUS ret = DAL_Init(fbVA + offset, fbPA + offset);
    ASSERT(DAL_STATUS_OK == ret);
}


static void init_lcd(void)
{
    // Config LCD Controller

    LCD_CHECK_RET(LCD_LayerEnable(LCD_LAYER_ALL, FALSE));
    LCD_CHECK_RET(LCD_LayerSetTriggerMode(LCD_LAYER_ALL, LCD_SW_TRIGGER));
    LCD_CHECK_RET(LCD_EnableHwTrigger(FALSE));

    LCD_CHECK_RET(LCD_SetBackgroundColor(0));
    LCD_CHECK_RET(LCD_SetRoiWindow(0, 0, lcm_params->width, lcm_params->height));

    LCD_CHECK_RET(LCD_SetOutputMode(LCD_OUTPUT_TO_LCM));
    LCD_CHECK_RET(LCD_WaitDPIIndication(FALSE));
    LCD_CHECK_RET(LCD_FBEnable(LCD_FB_0, FALSE));
    LCD_CHECK_RET(LCD_FBEnable(LCD_FB_1, FALSE));
    LCD_CHECK_RET(LCD_FBEnable(LCD_FB_2, FALSE));
}


void init_lcd_te_control(void)
{
    const LCM_DBI_PARAMS *dbi = &(lcm_params->dbi);

    if(!DISP_IsLcmFound())
    {
	printk("%s, lcm not connected, we will disable tearing free control\n", __func__);
    }

#if !defined(CONFIG_ARCH_MT6575) /*FIXME, must remove after bootmode is ready*/
    if ((META_BOOT == get_boot_mode() || ADVMETA_BOOT == get_boot_mode()) &&
        LCM_DBI_TE_MODE_DISABLED != dbi->te_mode) {
        DISP_LOG_PRINT(ANDROID_LOG_WARN, "DBI", "Force disable TE due to enter META mode\n");
        LCD_CHECK_RET(LCD_TE_Enable(FALSE));
        return;
    }
#endif

    if (LCM_DBI_TE_MODE_DISABLED == dbi->te_mode) {
        LCD_CHECK_RET(LCD_TE_Enable(FALSE));
        return;
    }

    if (LCM_DBI_TE_MODE_VSYNC_ONLY == dbi->te_mode) {
        LCD_CHECK_RET(LCD_TE_SetMode(LCD_TE_MODE_VSYNC_ONLY));
    } else if (LCM_DBI_TE_MODE_VSYNC_OR_HSYNC == dbi->te_mode) {
        LCD_CHECK_RET(LCD_TE_SetMode(LCD_TE_MODE_VSYNC_OR_HSYNC));
        LCD_CHECK_RET(LCD_TE_ConfigVHSyncMode(dbi->te_hs_delay_cnt,
                                              dbi->te_vs_width_cnt,
                     (LCD_TE_VS_WIDTH_CNT_DIV)dbi->te_vs_width_cnt_div));
    } else ASSERT(0);

    LCD_CHECK_RET(LCD_TE_SetEdgePolarity(dbi->te_edge_polarity));
    LCD_CHECK_RET(LCD_TE_Enable(TRUE));
}

static void init_io_driving_current(void)
{
	LCD_CHECK_RET(LCD_Set_DrivingCurrent(lcm_params));
}

// ---------------------------------------------------------------------------
//  DBI Display Driver Public Functions
// ---------------------------------------------------------------------------
static void init_io_pad(void)
{
   LCD_CHECK_RET(LCD_Init_IO_pad(lcm_params));
}

static DISP_STATUS dbi_init(UINT32 fbVA, UINT32 fbPA, BOOL isLcmInited)
{
    if (!disp_drv_dbi_init_context()) 
        return DISP_STATUS_NOT_IMPLEMENTED;
    init_io_pad();
	init_io_driving_current();
    init_lcd();
    init_assertion_layer(fbVA, fbPA);


    if (NULL != lcm_drv->init && !isLcmInited) {
        lcm_drv->init();
    }

    init_lcd_te_control();
	DPI_PowerOn();
	DPI_PowerOff();
	DSI_PowerOn();
	DSI_PowerOff();
    return DISP_STATUS_OK;
}


static DISP_STATUS dbi_enable_power(BOOL enable)
{
    if (enable) {
	LCD_CHECK_RET(LCD_PowerOn());
        init_io_pad();
    } else {
        LCD_CHECK_RET(LCD_PowerOff());
    }
    return DISP_STATUS_OK;
}


static DISP_STATUS dbi_set_fb_addr(UINT32 fbPhysAddr)
{
    LCD_CHECK_RET(LCD_LayerSetAddress(FB_LAYER, fbPhysAddr));

    return DISP_STATUS_OK;
}


static DISP_STATUS dbi_update_screen(void)
{

    LCD_CHECK_RET(LCD_StartTransfer(FALSE));

    return DISP_STATUS_OK;
}


static UINT32 dbi_get_vram_size(void)
{
    UINT32 vramSize = get_fb_size();

    // assertion layer
    vramSize += DAL_GetLayerSize();

    
    return vramSize;
}


static PANEL_COLOR_FORMAT dbi_get_panel_color_format(void)
{
    disp_drv_dbi_init_context();

    switch(lcm_params->dbi.data_format.format)
    {
    case LCM_DBI_FORMAT_RGB332 : return PANEL_COLOR_FORMAT_RGB332;
    case LCM_DBI_FORMAT_RGB444 : return PANEL_COLOR_FORMAT_RGB444;
    case LCM_DBI_FORMAT_RGB565 : return PANEL_COLOR_FORMAT_RGB565;
    case LCM_DBI_FORMAT_RGB666 : return PANEL_COLOR_FORMAT_RGB666;
    case LCM_DBI_FORMAT_RGB888 : return PANEL_COLOR_FORMAT_RGB888;
    default : ASSERT(0);
    }
    return PANEL_COLOR_FORMAT_RGB888;
}


static UINT32 dbi_get_dithering_bpp(void)
{
	return PANEL_COLOR_FORMAT_TO_BPP(dbi_get_panel_color_format());
}

DISP_STATUS dbi_capture_framebuffer(UINT32 pvbuf, UINT32 bpp)
{
    LCD_CHECK_RET(LCD_Capture_Framebuffer(pvbuf, bpp));

	return DISP_STATUS_OK;	
}

const DISP_DRIVER *DISP_GetDriverDBI()
{
    static const DISP_DRIVER DBI_DISP_DRV =
    {
        .init                   = dbi_init,
        .enable_power           = dbi_enable_power,
        .set_fb_addr            = dbi_set_fb_addr,
        .update_screen          = dbi_update_screen,
        
        .get_vram_size          = dbi_get_vram_size,
        .get_panel_color_format = dbi_get_panel_color_format,
        .init_te_control        = init_lcd_te_control,
        .get_dithering_bpp		= dbi_get_dithering_bpp,
		.capture_framebuffer	= dbi_capture_framebuffer, 
    };

    return &DBI_DISP_DRV;
}

