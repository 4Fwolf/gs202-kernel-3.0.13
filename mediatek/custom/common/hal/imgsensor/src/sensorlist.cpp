#include <utils/Log.h>
#include <utils/Errors.h>
#include <fcntl.h>
#include <math.h>

#include "MediaHal.h"
//#include "msdk_sensor_exp.h"
#include "camera_custom_sensor.h"
#if defined(IMX073_MIPI_RAW)
#include "camera_calibration_eeprom.h"
#endif
#include "kd_imgsensor.h"
//#include "image_sensor.h"

//TODO:remove once build system ready
//#include "camera_custom_cfg.h"

//#include "src/lib/inc/MediaLog.h"

//#define LOG_TAG "SENSORLIST"
//MUINT32 MT9P012_getCalData(PGET_SENSOR_CALIBRATION_DATA_STRUCT pGetCalData);


#define YUV_INFO(_id, name, getCalData)\
    {_id, name, \
    NSFeature::YUVSensorInfo<_id>::GetInstance, \
    NSFeature::YUVSensorInfo<_id>::GetDefaultData, \
    getCalData \
    }
#define RAW_INFO(_id, name, getCalData)\
    {_id, name, \
    NSFeature::RAWSensorInfo<_id>::GetInstance, \
    NSFeature::RAWSensorInfo<_id>::GetDefaultData, \
    getCalData \
    }


//MSDK_SENSOR_INIT_FUNCTION_STRUCT SensorList[MAX_NUM_OF_SUPPORT_SENSOR] =
MSDK_SENSOR_INIT_FUNCTION_STRUCT SensorList[] =
{
#if defined(IMX073_MIPI_RAW)
    RAW_INFO(IMX073_SENSOR_ID, SENSOR_DRVNAME_IMX073_MIPI_RAW,EEPROMGetCalData), 
#endif
#if defined(OV5642_RAW)
    RAW_INFO(OV5642_SENSOR_ID, SENSOR_DRVNAME_OV5642_RAW, NULL), 
#endif
#if defined(OV5642_MIPI_YUV)
    YUV_INFO(OV5642_SENSOR_ID, SENSOR_DRVNAME_OV5642_MIPI_YUV, NULL), 
#endif
#if defined(OV5642_MIPI_RGB)
    YUV_INFO(OV5642_SENSOR_ID, SENSOR_DRVNAME_OV5642_MIPI_RGB, NULL), 
#endif
#if defined(OV5642_MIPI_JPG)
    YUV_INFO(OV5642_SENSOR_ID, SENSOR_DRVNAME_OV5642_MIPI_JPG, NULL), 
#endif
#if defined(OV5642_YUV)
    YUV_INFO(OV5642_SENSOR_ID, SENSOR_DRVNAME_OV5642_YUV, NULL), 
#endif
#if defined(OV5647_RAW)
    RAW_INFO(OV5647_SENSOR_ID, SENSOR_DRVNAME_OV5647_RAW, NULL), 
#endif
#if defined(OV5650_RAW)
    RAW_INFO(OV5650_SENSOR_ID, SENSOR_DRVNAME_OV5650_RAW, NULL), 
#endif
#if defined(MT9P012_RAW)
    RAW_INFO(MT9P012_SENSOR_ID, SENSOR_DRVNAME_MT9P012_RAW, MT9P012_getCalData), 
#endif
#if defined(MT9P015_RAW)
    RAW_INFO(MT9P015_SENSOR_ID, SENSOR_DRVNAME_MT9P015_RAW, NULL), 
#endif
#if defined(MT9P017_RAW)
    RAW_INFO(MT9P017_SENSOR_ID, SENSOR_DRVNAME_MT9P017_RAW, NULL), 
#endif
#if defined(MT9P017_MIPI_RAW)
    RAW_INFO(MT9P017MIPI_SENSOR_ID, SENSOR_DRVNAME_MT9P017_MIPI_RAW, NULL), 
#endif

#if defined(OV3640_RAW)
    RAW_INFO(OV3640_SENSOR_ID, SENSOR_DRVNAME_OV3640_RAW, NULL), 
#endif
#if defined(OV3640_YUV)
    YUV_INFO(OV3640_SENSOR_ID, SENSOR_DRVNAME_OV3640_YUV, NULL), 
#endif
#if defined(OV3640_YUV_AF)
    YUV_INFO(OV3640_SENSOR_ID, SENSOR_DRVNAME_OV3640_YUV, NULL), 
#endif
#if defined(MT9T113_YUV)
    YUV_INFO(MT9T113_SENSOR_ID, SENSOR_DRVNAME_MT9T113_YUV,NULL), 
#endif
#if defined(MT9T113_MIPI_YUV)
    YUV_INFO(MT9T113MIPI_SENSOR_ID, SENSOR_DRVNAME_MT9T113_MIPI_YUV,NULL), 
#endif
#if defined(S5K5CAGX_YUV)
    YUV_INFO(S5K5CAGX_SENSOR_ID, SENSOR_DRVNAME_S5K5CAGX_YUV,NULL), 
#endif
#if defined(OV2650_RAW)
    RAW_INFO(OV2650_SENSOR_ID, SENSOR_DRVNAME_OV2650_RAW, NULL), 
#endif
#if defined(OV2655_YUV)
    YUV_INFO(OV2650_SENSOR_ID, SENSOR_DRVNAME_OV2655_YUV, NULL), 
#endif
#if defined(OV2659_YUV)
    YUV_INFO(OV2659_SENSOR_ID, SENSOR_DRVNAME_OV2659_YUV, NULL), 
#endif
#if defined(OV7675_YUV)
    YUV_INFO(OV7675_SENSOR_ID, SENSOR_DRVNAME_OV7675_YUV, NULL), 
#endif
#if defined(MT9V113_YUV)
    YUV_INFO(MT9V113_SENSOR_ID, SENSOR_DRVNAME_MT9V113_YUV, NULL), 
#endif
#if defined(MT9V114_YUV)
    YUV_INFO(MT9V114_SENSOR_ID, SENSOR_DRVNAME_MT9V114_YUV,NULL), 
#endif
#if defined(SIV120B_YUV)
    YUV_INFO(SIV120B_SENSOR_ID, SENSOR_DRVNAME_SIV120B_YUV, NULL), 
#endif
#if defined(PAS6180_SERIAL_YUV)
    YUV_INFO(PAS6180_SENSOR_ID, SENSOR_DRVNAME_PAS6180_SERIAL_YUV, NULL), 
#endif
#if defined(HI704_YUV)
    YUV_INFO(HI704_SENSOR_ID, SENSOR_DRVNAME_HI704_YUV,NULL), 
#endif
#if defined(IMX105_MIPI_RAW)
    RAW_INFO(IMX105_SENSOR_ID, SENSOR_DRVNAME_IMX105_MIPI_RAW,NULL), 
#endif

/*  ADD sensor driver before this line */
    {0,{0},NULL, NULL, NULL}//end of list
};

UINT32 GetSensorInitFuncList(MSDK_SENSOR_INIT_FUNCTION_STRUCT **ppSensorList)
{
    if (NULL == ppSensorList) {
        LOGE("ERROR: NULL pSensorList\n");
        return MHAL_UNKNOWN_ERROR;
    }
    *ppSensorList = &SensorList[0];
	return MHAL_NO_ERROR;
} // GetSensorInitFuncList()






