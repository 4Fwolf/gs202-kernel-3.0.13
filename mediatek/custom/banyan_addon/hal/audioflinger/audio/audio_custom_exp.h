/*******************************************************************************
 *
 * Filename:
 * ---------
 * audio_custom_exp.h
 *
 * Project:
 * --------
 *   ALPS
 *
 * Description:
 * ------------
 * This file is the header of audio customization related function or definition.
 *
 * Author:
 * -------
 * ChiPeng
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:$
 * $Modtime:$
 * $Log:$
 *
 * 04 21 2011 weiguo.li
 * [ALPS00042230] add macro for Camera Shutter Sound
 * .
 *
 * 06 29 2010 chipeng.chang
 * [ALPS00120725][Phone sound] The ringer volume is not high enough when setting ringer volume 
 * update for audio customization for volume base level.
 *
 * 05 26 2010 chipeng.chang
 * [ALPS00002287][Need Patch] [Volunteer Patch] ALPS.10X.W10.11 Volunteer patch for audio paramter
 * modify for Audio parameter
 *
 * 05 11 2010 chipeng.chang
 * [ALPS00002041]Audio Customization
 * add aduio user space customization
 *
 *
 * Mar 15 2010 mtk02308
 *    Init Audio_custom_exp.h
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef AUDIO_CUSTOM_EXP_H
#define AUDIO_CUSTOM_EXP_H

namespace android {

// a step means 0.5 dB  ex:20==> attenuation  for 10 dB
static uint32_t Stream_Atten[] =
    {  0, //VOICE_CALL ,no use
        0, //SYSTEM
        0, //RINGONE
        0, //MUSIC
        0, //ALARM
        0, //NOTIFICATION
        0, //BLUETOOTH_SCO , no use
        0, //ENFORCED_AUDIBLE
        0, //DTMF
        0  //TTS
        };

static uint32_t Stream_Base[] =
    {  0, //VOICE_CALL ,no use
        0, //SYSTEM
        30, //RINGONE
        30, //MUSIC
        30, //ALARM
        30, //NOTIFICATION
        0, //BLUETOOTH_SCO , no use
        30, //ENFORCED_AUDIBLE
        30, //DTMF
        30  //TTS
        };



#ifndef DEVICE_ATTEN_MAX
#define DEVICE_ATTEN_MAX        (24)
#endif

#ifndef INVER_DEVICE_MAX
#define INVER_DEVICE_MAX       (0xFFFF/(DEVICE_ATTEN_MAX<<1))
#endif

#ifndef DEVICE_MAX_VOLUME
#define DEVICE_MAX_VOLUME      (24)
#endif

#ifndef DEVICE_MIN_VOLUME
#define DEVICE_MIN_VOLUME      (-23)
#endif

#ifndef INTERNAL_AMP_ATTEN_VOLUME
#define INTERNAL_AMP_ATTEN_VOLUME      (10)  //6, 9, 12, 15, 18, 21, 24, 27
#endif


//#define ENABLE_AUDIO_COMPENSATION_FILTER  //Define this will enable audio compensation filter 
                                          //Please see ACF Document for detail
                                          
//#define ENABLE_AUDIO_DRC_SPEAKER  //Define this will enable DRC for loudspeaker                                          
                                          
//#define ENABLE_HEADPHONE_COMPENSATION_FILTER  //Define this will enable headphone compensation filter
                                          //Please see HCF Document for detail
                                          
//#define FORCE_CAMERA_SHUTTER_SOUND_AUDIBLE   //Define this will enable camera shutter sound audible 
                                               //even if in silent mode    

// DeFine FM use analog or digital input , below can only define one , means digital or analog.
//#define FM_USE_DIGITAL_IN
#define FM_USE_ANALOG_IN

#ifdef ENABLE_HEADPHONE_COMPENSATION_FILTER
    #define HEADPHONE_COMPENSATION_FLT_MODE (4)
#endif

#define USE_REFMIC_IN_LOUDSPK (0)         //(1)->Use Ref Mic as main mic; (0)->Use original main mic.
}

#endif
