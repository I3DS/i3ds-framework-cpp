#ifndef i3ds_asn1_GENERATED_ASN1SCC_Sensor_H
#define i3ds_asn1_GENERATED_ASN1SCC_Sensor_H
/*
Code automatically generated by asn1scc tool
*/
#include <i3ds_asn1/asn1crt.hpp>
#include <i3ds_asn1/asn1crt_encoding.hpp>

#include <i3ds_asn1/taste-extended.hpp>
#include <i3ds_asn1/taste-types.hpp>
#include <i3ds_asn1/base.hpp>

namespace i3ds_asn1 {


typedef T_UInt32 SamplePeriod;


void SamplePeriod_Initialize(SamplePeriod* pVal);

#define i3ds_asn1_ERR_SAMPLEPERIOD_2		9957  /**/
flag SamplePeriod_IsConstraintValid(const SamplePeriod* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_SAMPLEPERIOD_2		9958  /**/
#define i3ds_asn1_SamplePeriod_REQUIRED_BYTES_FOR_ENCODING       4 
#define i3ds_asn1_SamplePeriod_REQUIRED_BITS_FOR_ENCODING        32

flag SamplePeriod_Encode(const SamplePeriod* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_SAMPLEPERIOD_2		9959  /**/
flag SamplePeriod_Decode(SamplePeriod* pVal, BitStream* pBitStrm, int* pErrCode);
typedef T_UInt32 BatchSize;


void BatchSize_Initialize(BatchSize* pVal);

#define i3ds_asn1_ERR_BATCHSIZE_2		9969  /**/
flag BatchSize_IsConstraintValid(const BatchSize* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_BATCHSIZE_2		9970  /**/
#define i3ds_asn1_BatchSize_REQUIRED_BYTES_FOR_ENCODING       4 
#define i3ds_asn1_BatchSize_REQUIRED_BITS_FOR_ENCODING        32

flag BatchSize_Encode(const BatchSize* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_BATCHSIZE_2		9971  /**/
flag BatchSize_Decode(BatchSize* pVal, BitStream* pBitStrm, int* pErrCode);
typedef T_UInt32 BatchCount;


void BatchCount_Initialize(BatchCount* pVal);

#define i3ds_asn1_ERR_BATCHCOUNT_2		9981  /**/
flag BatchCount_IsConstraintValid(const BatchCount* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_BATCHCOUNT_2		9982  /**/
#define i3ds_asn1_BatchCount_REQUIRED_BYTES_FOR_ENCODING       4 
#define i3ds_asn1_BatchCount_REQUIRED_BITS_FOR_ENCODING        32

flag BatchCount_Encode(const BatchCount* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_BATCHCOUNT_2		9983  /**/
flag BatchCount_Decode(BatchCount* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- SampleCommand --------------------------------------------*/
typedef struct {
    T_UInt32 period;
    T_UInt32 batch_size;
    T_UInt32 batch_count;

} SampleCommand;

void SampleCommand_Initialize(SampleCommand* pVal);

#define i3ds_asn1_ERR_SAMPLECOMMAND		10037  /**/
#define i3ds_asn1_i3ds_asn1_ERR_SAMPLECOMMAND_PERIOD_2_2		9998  /**/
#define i3ds_asn1_i3ds_asn1_ERR_SAMPLECOMMAND_BATCH_SIZE_2_2		10015  /**/
#define i3ds_asn1_i3ds_asn1_ERR_SAMPLECOMMAND_BATCH_COUNT_2_2		10032  /**/
flag SampleCommand_IsConstraintValid(const SampleCommand* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_SAMPLECOMMAND		10038  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_SAMPLECOMMAND_PERIOD_2_2		9999  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_SAMPLECOMMAND_BATCH_SIZE_2_2		10016  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_SAMPLECOMMAND_BATCH_COUNT_2_2		10033  /**/
#define i3ds_asn1_SampleCommand_REQUIRED_BYTES_FOR_ENCODING       12 
#define i3ds_asn1_SampleCommand_REQUIRED_BITS_FOR_ENCODING        96

flag SampleCommand_Encode(const SampleCommand* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_SAMPLECOMMAND		10039  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_SAMPLECOMMAND_PERIOD_2_2		10000  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_SAMPLECOMMAND_BATCH_SIZE_2_2		10017  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_SAMPLECOMMAND_BATCH_COUNT_2_2		10034  /**/
flag SampleCommand_Decode(SampleCommand* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- SensorConfiguration --------------------------------------------*/
typedef struct {
    T_String device_name;
    T_UInt32 period;
    T_UInt32 batch_size;
    T_UInt32 batch_count;

} SensorConfiguration;

void SensorConfiguration_Initialize(SensorConfiguration* pVal);

#define i3ds_asn1_ERR_SENSORCONFIGURATION		10107  /**/
#define i3ds_asn1_i3ds_asn1_ERR_SENSORCONFIGURATION_DEVICE_NAME_2		10051  /**/
#define i3ds_asn1_i3ds_asn1_ERR_SENSORCONFIGURATION_PERIOD_2_2		10068  /**/
#define i3ds_asn1_i3ds_asn1_ERR_SENSORCONFIGURATION_BATCH_SIZE_2_2		10085  /**/
#define i3ds_asn1_i3ds_asn1_ERR_SENSORCONFIGURATION_BATCH_COUNT_2_2		10102  /**/
flag SensorConfiguration_IsConstraintValid(const SensorConfiguration* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_SENSORCONFIGURATION		10108  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_SENSORCONFIGURATION_DEVICE_NAME_2		10052  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_SENSORCONFIGURATION_PERIOD_2_2		10069  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_SENSORCONFIGURATION_BATCH_SIZE_2_2		10086  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_SENSORCONFIGURATION_BATCH_COUNT_2_2		10103  /**/
#define i3ds_asn1_SensorConfiguration_REQUIRED_BYTES_FOR_ENCODING       53 
#define i3ds_asn1_SensorConfiguration_REQUIRED_BITS_FOR_ENCODING        422

flag SensorConfiguration_Encode(const SensorConfiguration* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_SENSORCONFIGURATION		10109  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_SENSORCONFIGURATION_DEVICE_NAME_2		10053  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_SENSORCONFIGURATION_PERIOD_2_2		10070  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_SENSORCONFIGURATION_BATCH_SIZE_2_2		10087  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_SENSORCONFIGURATION_BATCH_COUNT_2_2		10104  /**/
flag SensorConfiguration_Decode(SensorConfiguration* pVal, BitStream* pBitStrm, int* pErrCode);
typedef enum {
    inactive = 0,
    standby = 1,
    operational = 2,
    failure = 3
} SensorState;

// please use the following macros to avoid breaking code.
#define i3ds_asn1_SensorState_inactive inactive
#define i3ds_asn1_SensorState_standby standby
#define i3ds_asn1_SensorState_operational operational
#define i3ds_asn1_SensorState_failure failure

void SensorState_Initialize(SensorState* pVal);

#define i3ds_asn1_ERR_SENSORSTATE		9893  /**/
flag SensorState_IsConstraintValid(const SensorState* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_SENSORSTATE		9894  /**/
#define i3ds_asn1_SensorState_REQUIRED_BYTES_FOR_ENCODING       1 
#define i3ds_asn1_SensorState_REQUIRED_BITS_FOR_ENCODING        2

flag SensorState_Encode(const SensorState* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_SENSORSTATE		9895  /**/
flag SensorState_Decode(SensorState* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- SensorStatus --------------------------------------------*/
typedef struct {
    SensorState current_state;
    Base_Temperature device_temperature;

} SensorStatus;

void SensorStatus_Initialize(SensorStatus* pVal);

#define i3ds_asn1_ERR_SENSORSTATUS		9943  /**/
#define i3ds_asn1_i3ds_asn1_ERR_SENSORSTATUS_CURRENT_STATE_2		9914  /**/
#define i3ds_asn1_i3ds_asn1_ERR_SENSORSTATUS_DEVICE_TEMPERATURE_2		9938  /**/
flag SensorStatus_IsConstraintValid(const SensorStatus* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_SENSORSTATUS		9944  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_SENSORSTATUS_CURRENT_STATE_2		9915  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_SENSORSTATUS_DEVICE_TEMPERATURE_2		9939  /**/
#define i3ds_asn1_SensorStatus_REQUIRED_BYTES_FOR_ENCODING       14 
#define i3ds_asn1_SensorStatus_REQUIRED_BITS_FOR_ENCODING        106

flag SensorStatus_Encode(const SensorStatus* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_SENSORSTATUS		9945  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_SENSORSTATUS_CURRENT_STATE_2		9916  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_SENSORSTATUS_DEVICE_TEMPERATURE_2		9940  /**/
flag SensorStatus_Decode(SensorStatus* pVal, BitStream* pBitStrm, int* pErrCode);
typedef enum {
    activate = 0,
    start = 1,
    stop = 2,
    deactivate = 3
} StateCommand;

// please use the following macros to avoid breaking code.
#define i3ds_asn1_StateCommand_activate activate
#define i3ds_asn1_StateCommand_start start
#define i3ds_asn1_StateCommand_stop stop
#define i3ds_asn1_StateCommand_deactivate deactivate

void StateCommand_Initialize(StateCommand* pVal);

#define i3ds_asn1_ERR_STATECOMMAND		9900  /**/
flag StateCommand_IsConstraintValid(const StateCommand* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_STATECOMMAND		9901  /**/
#define i3ds_asn1_StateCommand_REQUIRED_BYTES_FOR_ENCODING       1 
#define i3ds_asn1_StateCommand_REQUIRED_BITS_FOR_ENCODING        2

flag StateCommand_Encode(const StateCommand* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_STATECOMMAND		9902  /**/
flag StateCommand_Decode(StateCommand* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 



} // namespace i3ds_asn1
#endif