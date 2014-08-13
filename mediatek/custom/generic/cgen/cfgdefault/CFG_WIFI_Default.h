/*******************************************************************************
 *
 * Filename:
 * ---------
 *   cfg_wifi_default.h
 *
 * Project:
 * --------
 *   DUMA
 *
 * Description:
 * ------------
 *    give the default MT5921 config data.
 *
 * Author:
 * -------
 *   Renbang (MTK80150) 06/08/2009
 *
 *------------------------------------------------------------------------------
 * $Revision:$
 * $Modtime:$
 * $Log:$
 *
 * 11 05 2010 renbang.jiang
 * [ALPS00134025] [Wi-Fi] move Wi-Fi NVRAM definition source file to project folder from common folder
 * .
 *
 * 11 05 2010 renbang.jiang
 * [ALPS00134025] [Wi-Fi] move Wi-Fi NVRAM definition source file to project folder from common folder
 * .
 *
 * 07 10 2010 renbang.jiang
 * [ALPS00121785][Need Patch] [Volunteer Patch] use NVRAM to save Wi-Fi custom data 
 * .
 *
 *    mtk80150
 * [DUMA00131389] [wifi] enable MT5921 NVRAM
 * Enable Daisy Chain in default setting
 *
 * Jul 9 2009 mtk80306
 * [DUMA00122953] optimize nvram and change meta clean boot flag.
 * 
 * 
 *
 *******************************************************************************/



#ifndef _CFG_WIFI_D_H
#define _CFG_WIFI_D_H

#include "../cfgfileinc/CFG_Wifi_File.h"
#include "../inc/wifi_custom.h"
// the default value of Wi-Fi nvram file

WIFI_CFG_PARAM_STRUCT stWifiCfgDefault =
{
    0x5921,    0x0000,    0xD880,    0x0000,
    0x0000,    0x0000,    0x7C00,    0x0000,
    0x0355,    0x0105,    0xA000,    0x2430,
    0xD900,    0x0000,    0x0000,    0x504A,
    
    0x076C,    0x4001,    0x0301,    0x0C00,
    0x09E7,    0x0000,    0x0300,    0x0A03,
    0x0F20,    0x201C,    0x1C0F,    0x0F20,
    0x201C,    0x1C0F,    0x0F20,    0x201C,
    
    0x1C0F,    0x0F20,    0x201C,    0x1C0F,
    0x0F20,    0x201C,    0x1C0F,    0x0F20,
    0x201C,    0x1C0F,    0x0F20,    0x201C,
    0x1C0F,    0x0D22,    0x221C,    0x1C0D,
    
    0x0D22,    0x221C,    0x1C0D,    0x0D22,
    0x221C,    0x1C0D,    0x0D22,    0x221C,
    0x1C0D,    0x0D22,    0x221C,    0x1C0D,
    0x0D22,    0x221C,    0x1C0D,    0x0D22,
    
    0x221C,    0x1C0D,    0x0D22,    0x221C,
    0x1C0D,    0x0D22,    0x221C,    0x1C0D,
    0x0D22,    0x221C,    0x1C0D,    0x0D22,
    0x221C,    0x1C0D,    0x0D22,    0x221C,
    
    0x1C0D,    0x0D22,    0x221C,    0x1C0D,
    0x0D22,    0x221C,    0x1C0D,    0x0D22,
    0x221C,    0x1C0D,    0x0D22,    0x221C,
    0x1C0D,    0x0D22,    0x221C,    0x1C0D,
    
    0x0D22,    0x221C,    0x1C0D,    0x0D22,
    0x221C,    0x1C0D,    0x0D22,    0x221C,
    0x1C0D,    0x0D22,    0x221C,    0x1C0D,
    0x0D22,    0x221C,    0x1C0D,    0x0D22,
    
    0x221C,    0x1C0D,    0x0D22,    0x221C,
    0x1C0D,    0x0D22,    0x221C,    0x1C0D,
    0x0D22,    0x221C,    0x1C0D,    0x0D22,
    0x221C,    0x1C0D,    0x0D22,    0x221C,
          
    0x1C0D,    0x1C19,    0x0100,    0x0000,
    0x0000,    0x0000,    0x0000,    0x0000,
    0x0000,    0x0000,    0x0000,    0x0000,
    0x0000,    0x0000,    0x0000,    0x0000,
    
    0x0000,    0x0000,    0x0000,    0x0000,
    0x0000,    0x0000,    0x0000,    0x0000,
    0x0000,    0x0000,    0x0000,    0x0000,
    0x0000,    0x0000,    0x0000,    0xE900,
    
    0x0221,    0x000C,    0x0422,    0x0000,
    0x5A08,    0x0420,    0x037A,    0x5921,
    0x1B15,    0x0008,    0x654D,    0x6964,
    0x5461,    0x6B65,    0x5700,    0x414C,
    
    0x204E,    0x6441,    0x7061,    0x6574,
    0x0072,    0x0000,    0xFFFF,    0x0000,
    0x0221,    0x000C,    0x1C22,    0x0101,
    0x0010,    0x0000,    0x0000,    0x0000,
    
    0x0300,    0x0800,    0x0000,    0x007C,
    0x9664,    0x0AC8,    0x140F,    0x0032,
    0x05DC,    0x00FF,    0x0000,    0x0000,
    0x0000,    0x0000,    0x0000,    0x0000,

    0x0000,    0x0000,    0x0000,    0x0000,
    0x0000,    0x0000,    0x0000,    0x0000,
    0x0000,    0x0000,    0x0000,    0x0000,
    0x0000,    0x0000,    0x0000,    0x0000,

    0x0000,    0x0000,    0x0000,    0x0000,
    0x0000,    0x0000,    0x0000,    0x0000,
    0x0000,    0x0000,    0x0000,    0x0000,
    0x0000,    0x0000,    0x0000,    0x0000,

    0x0000,    0x0000,    0x0000,    0x0000,
    0x0000,    0x0000,    0x0000,    0x0000,
    0x0000,    0x0000,    0x0000,    0x0000,
    0x0000,    0x0000,    0x0000,    0x0000
};

WIFI_CUSTOM_PARAM_STRUCT stWifiCustomDefault =
{
    WIFI_CUSTOM_SD_BLOCK_SIZE,      /* SDIO block size */
    WIFI_CUSTOM_SD_BUS_WIDTH,
    WIFI_CUSTOM_SD_CLOCK_RATE,

    WIFI_CUSTOM_BT_COEXIST_WINDOW_T,
    WIFI_CUSTOM_ENABLE_TX_AUTO_FRAGMENT_FOR_BT,
    WIFI_CUSTOM_BTCR0,
    WIFI_CUSTOM_BTCR1,
    WIFI_CUSTOM_BTCR2,
    WIFI_CUSTOM_BTCR3,
    
    WIFI_CUSTOM_SINGLE_ACL_BTCR0,
    WIFI_CUSTOM_SINGLE_ACL_BTCR1,
    WIFI_CUSTOM_SINGLE_ACL_BTCR2,
    WIFI_CUSTOM_SINGLE_ACL_BTCR3,
    
    
    WIFI_CUSTOM_SINGLE_MIX_BTCR0,
    WIFI_CUSTOM_SINGLE_MIX_BTCR1,
    WIFI_CUSTOM_SINGLE_MIX_BTCR2,
    WIFI_CUSTOM_SINGLE_MIX_BTCR3,
    
    WIFI_CUSTOM_DUAL_ACL_BTCR0,
    WIFI_CUSTOM_DUAL_ACL_BTCR1,
    WIFI_CUSTOM_DUAL_ACL_BTCR2,
    WIFI_CUSTOM_DUAL_ACL_BTCR3,
    
        
    WIFI_CUSTOM_DUAL_MIX_BTCR0,
    WIFI_CUSTOM_DUAL_MIX_BTCR1,
    WIFI_CUSTOM_DUAL_MIX_BTCR2,
    WIFI_CUSTOM_DUAL_MIX_BTCR3,
        
    WIFI_CUSTOM_BT_SETTING,
    WIFI_CUSTOM_SINGLE_ANT,
    WIFI_CUSTOM_BT_PROFILE,
    WIFI_CUSTOM_PTA_ENABLED,
    
    WIFI_CUSTOM_MAC_ADDRESS,
    WIFI_CUSTOM_COUNTRY_CODE,
    WIFI_CUSTOM_UAPSD_AC,
    WIFI_CUSTOM_POWER_MODE,
    WIFI_CUSTOM_ATIM_WINDOW,
    WIFI_CUSTOM_VOIP_INTERVAL,
    WIFI_CUSTOM_POLL_INTERVAL,
    WIFI_CUSTOM_POLL_INTERVAL_B,
    WIFI_CUSTOM_L3_PKT_FILTER_EN,
    WIFI_CUSTOM_ADHOC_MODE,
    WIFI_CUSTOM_ROAMING_EN,
    
    WIFI_CUSTOM_MULTI_DOMAIN_CAP,
    
    WIFI_CUSTOM_GPIO2_MODE,
    
    WIFI_CUSTOM_VI_AIFSN_BIAS,
    
    WIFI_CUSTOM_VI_MAX_TXOP_LIMIT,
    
    WIFI_CUSTOM_INIT_DELAY_IND,
    
    WIFI_CUSTOM_USE_WAPI,
    
    WIFI_CUSTOM_DAISY_CHAIN_EN,
    
    WIFI_CUSTOM_LED_BLINK_MODE,
    WIFI_CUSTOM_LED_BLINK_ON_TIME,
    WIFI_CUSTOM_LED_BLINK_OFF_TIME,
    
    WIFI_CUSTOM_WMM_PS_EN,
    
    WIFI_CUSTOM_RESERVED
};

#endif
