#ifndef GENERATED_ASN1SCC_IMU_H
#define GENERATED_ASN1SCC_IMU_H
/*
Code automatically generated by asn1scc tool
*/
#include "Sensor.h"
#include "SampleAttribute.h"
#include "taste-types.h"
#include "taste-extended.h"
#include "asn1crt.h"

#ifdef  __cplusplus
extern "C" {
#endif


/*-- IMUSample --------------------------------------------*/
typedef struct {
    T_Double axis_x_rate;
    T_Double axis_x_acceleration;
    T_Double axis_y_rate;
    T_Double axis_y_acceleration;
    T_Double axis_z_rate;
    T_Double axis_z_acceleration;

} IMUSample;

void IMUSample_Initialize(IMUSample* pVal);

#define ERR_IMUSAMPLE		801  /**/
#define ERR_IMUSAMPLE_AXIS_X_RATE		735  /**/
#define ERR_IMUSAMPLE_AXIS_X_ACCELERATION		746  /**/
#define ERR_IMUSAMPLE_AXIS_Y_RATE		757  /**/
#define ERR_IMUSAMPLE_AXIS_Y_ACCELERATION		768  /**/
#define ERR_IMUSAMPLE_AXIS_Z_RATE		779  /**/
#define ERR_IMUSAMPLE_AXIS_Z_ACCELERATION		790  /**/
flag IMUSample_IsConstraintValid(const IMUSample* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_IMUSAMPLE		802  /**/
#define ERR_UPER_ENCODE_IMUSAMPLE_AXIS_X_RATE_2		742  /**/
#define ERR_UPER_ENCODE_IMUSAMPLE_AXIS_X_ACCELERATION_2		753  /**/
#define ERR_UPER_ENCODE_IMUSAMPLE_AXIS_Y_RATE_2		764  /**/
#define ERR_UPER_ENCODE_IMUSAMPLE_AXIS_Y_ACCELERATION_2		775  /**/
#define ERR_UPER_ENCODE_IMUSAMPLE_AXIS_Z_RATE_2		786  /**/
#define ERR_UPER_ENCODE_IMUSAMPLE_AXIS_Z_ACCELERATION_2		797  /**/
#define IMUSample_REQUIRED_BYTES_FOR_ENCODING       78 
#define IMUSample_REQUIRED_BITS_FOR_ENCODING        624

flag IMUSample_Encode(const IMUSample* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_IMUSAMPLE		803  /**/
#define ERR_UPER_DECODE_IMUSAMPLE_AXIS_X_RATE_2		743  /**/
#define ERR_UPER_DECODE_IMUSAMPLE_AXIS_X_ACCELERATION_2		754  /**/
#define ERR_UPER_DECODE_IMUSAMPLE_AXIS_Y_RATE_2		765  /**/
#define ERR_UPER_DECODE_IMUSAMPLE_AXIS_Y_ACCELERATION_2		776  /**/
#define ERR_UPER_DECODE_IMUSAMPLE_AXIS_Z_RATE_2		787  /**/
#define ERR_UPER_DECODE_IMUSAMPLE_AXIS_Z_ACCELERATION_2		798  /**/
flag IMUSample_Decode(IMUSample* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- IMUMeasurement20 --------------------------------------------*/


typedef struct {
    int nCount; 
    
    IMUSample arr[20];
} IMUMeasurement20_samples;
typedef struct {
    SampleAttributes attributes;
    IMUMeasurement20_samples samples;
    T_UInt32 batch_size;

} IMUMeasurement20;

void IMUMeasurement20_samples_Initialize(IMUMeasurement20_samples* pVal);
void IMUMeasurement20_Initialize(IMUMeasurement20* pVal);

#define ERR_IMUMEASUREMENT20		1028  /**/
#define ERR_IMUMEASUREMENT20_ATTRIBUTES		918  /**/
#define ERR_IMUMEASUREMENT20_ATTRIBUTES_TIMESTAMP		808  /**/
#define ERR_IMUMEASUREMENT20_ATTRIBUTES_VALIDITY		823  /**/
#define ERR_IMUMEASUREMENT20_ATTRIBUTES_ATTRIBUTES		911  /**/
#define ERR_IMUMEASUREMENT20_ATTRIBUTES_ATTRIBUTES_ELM		900  /**/
#define ERR_IMUMEASUREMENT20_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_KEY		834  /**/
#define ERR_IMUMEASUREMENT20_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE		889  /**/
#define ERR_IMUMEASUREMENT20_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_BOOLEAN_VALUE		845  /**/
#define ERR_IMUMEASUREMENT20_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_DISCRETE_VALUE		856  /**/
#define ERR_IMUMEASUREMENT20_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_REAL_VALUE		867  /**/
#define ERR_IMUMEASUREMENT20_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_STRING_VALUE		878  /**/
#define ERR_IMUMEASUREMENT20_SAMPLES		1006  /**/
#define ERR_IMUMEASUREMENT20_SAMPLES_ELM		995  /**/
#define ERR_IMUMEASUREMENT20_SAMPLES_ELM_AXIS_X_RATE		929  /**/
#define ERR_IMUMEASUREMENT20_SAMPLES_ELM_AXIS_X_ACCELERATION		940  /**/
#define ERR_IMUMEASUREMENT20_SAMPLES_ELM_AXIS_Y_RATE		951  /**/
#define ERR_IMUMEASUREMENT20_SAMPLES_ELM_AXIS_Y_ACCELERATION		962  /**/
#define ERR_IMUMEASUREMENT20_SAMPLES_ELM_AXIS_Z_RATE		973  /**/
#define ERR_IMUMEASUREMENT20_SAMPLES_ELM_AXIS_Z_ACCELERATION		984  /**/
#define ERR_IMUMEASUREMENT20_BATCH_SIZE		1013  /**/
flag IMUMeasurement20_IsConstraintValid(const IMUMeasurement20* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_IMUMEASUREMENT20		1029  /**/
#define ERR_UPER_ENCODE_IMUMEASUREMENT20_ATTRIBUTES_2		925  /**/
#define ERR_UPER_ENCODE_IMUMEASUREMENT20_SAMPLES		1007  /**/
#define ERR_UPER_ENCODE_IMUMEASUREMENT20_SAMPLES_ELM_2		1002  /**/
#define ERR_UPER_ENCODE_IMUMEASUREMENT20_BATCH_SIZE_2_2		1024  /**/
#define IMUMeasurement20_REQUIRED_BYTES_FOR_ENCODING       1631 
#define IMUMeasurement20_REQUIRED_BITS_FOR_ENCODING        13042

flag IMUMeasurement20_Encode(const IMUMeasurement20* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_IMUMEASUREMENT20		1030  /**/
#define ERR_UPER_DECODE_IMUMEASUREMENT20_ATTRIBUTES_2		926  /**/
#define ERR_UPER_DECODE_IMUMEASUREMENT20_SAMPLES		1008  /**/
#define ERR_UPER_DECODE_IMUMEASUREMENT20_SAMPLES_ELM_2		1003  /**/
#define ERR_UPER_DECODE_IMUMEASUREMENT20_BATCH_SIZE_2_2		1025  /**/
flag IMUMeasurement20_Decode(IMUMeasurement20* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

#endif
