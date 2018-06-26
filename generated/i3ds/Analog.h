#ifndef GENERATED_ASN1SCC_Analog_H
#define GENERATED_ASN1SCC_Analog_H
/*
Code automatically generated by asn1scc tool
*/
#include "taste-extended.h"
#include "taste-types.h"
#include "Sensor.h"
#include "SampleAttribute.h"
#include "asn1crt.h"

#ifdef  __cplusplus
extern "C" {
#endif



typedef T_UInt8 SeriesCount;

#define SeriesCount_REQUIRED_BYTES_FOR_ENCODING       1 
#define SeriesCount_REQUIRED_BITS_FOR_ENCODING        8
#define SeriesCount_REQUIRED_BYTES_FOR_ACN_ENCODING   1 
#define SeriesCount_REQUIRED_BITS_FOR_ACN_ENCODING    8
#define SeriesCount_REQUIRED_BYTES_FOR_XER_ENCODING   47

void SeriesCount_Initialize(SeriesCount* pVal);
flag SeriesCount_IsConstraintValid(const SeriesCount* val, int* pErrCode);


typedef struct {    int nCount; 
    
    T_Float arr[10000];
} AnalogMeasurement10K_samples;

#define AnalogMeasurement10K_samples_REQUIRED_BYTES_FOR_ENCODING       130002 
#define AnalogMeasurement10K_samples_REQUIRED_BITS_FOR_ENCODING        1040014
#define AnalogMeasurement10K_samples_REQUIRED_BYTES_FOR_ACN_ENCODING   130002 
#define AnalogMeasurement10K_samples_REQUIRED_BITS_FOR_ACN_ENCODING    1040014
#define AnalogMeasurement10K_samples_REQUIRED_BYTES_FOR_XER_ENCODING   690061

void AnalogMeasurement10K_samples_Initialize(AnalogMeasurement10K_samples* pVal);
flag AnalogMeasurement10K_samples_IsConstraintValid(const AnalogMeasurement10K_samples* val, int* pErrCode);
#ifndef ERR_AnalogMeasurement10K_samples 
#define ERR_AnalogMeasurement10K_samples		1001  /*(SIZE(0 .. 10000))*/
#endif

typedef struct {
    SampleAttributes attributes;
    AnalogMeasurement10K_samples samples;
    SeriesCount series;
    BatchSize batch_size;
} AnalogMeasurement10K;

#define AnalogMeasurement10K_REQUIRED_BYTES_FOR_ENCODING       130110 
#define AnalogMeasurement10K_REQUIRED_BITS_FOR_ENCODING        1040875
#define AnalogMeasurement10K_REQUIRED_BYTES_FOR_ACN_ENCODING   130110 
#define AnalogMeasurement10K_REQUIRED_BITS_FOR_ACN_ENCODING    1040875
#define AnalogMeasurement10K_REQUIRED_BYTES_FOR_XER_ENCODING   691371

void AnalogMeasurement10K_Initialize(AnalogMeasurement10K* pVal);
flag AnalogMeasurement10K_IsConstraintValid(const AnalogMeasurement10K* val, int* pErrCode);


typedef struct {    int nCount; 
    
    T_Float arr[3000];
} AnalogMeasurement3K_samples;

#define AnalogMeasurement3K_samples_REQUIRED_BYTES_FOR_ENCODING       39002 
#define AnalogMeasurement3K_samples_REQUIRED_BITS_FOR_ENCODING        312012
#define AnalogMeasurement3K_samples_REQUIRED_BYTES_FOR_ACN_ENCODING   39002 
#define AnalogMeasurement3K_samples_REQUIRED_BITS_FOR_ACN_ENCODING    312012
#define AnalogMeasurement3K_samples_REQUIRED_BYTES_FOR_XER_ENCODING   207059

void AnalogMeasurement3K_samples_Initialize(AnalogMeasurement3K_samples* pVal);
flag AnalogMeasurement3K_samples_IsConstraintValid(const AnalogMeasurement3K_samples* val, int* pErrCode);
#ifndef ERR_AnalogMeasurement3K_samples 
#define ERR_AnalogMeasurement3K_samples		1002  /*(SIZE(0 .. 3000))*/
#endif

typedef struct {
    SampleAttributes attributes;
    AnalogMeasurement3K_samples samples;
    SeriesCount series;
    BatchSize batch_size;
} AnalogMeasurement3K;

#define AnalogMeasurement3K_REQUIRED_BYTES_FOR_ENCODING       39110 
#define AnalogMeasurement3K_REQUIRED_BITS_FOR_ENCODING        312873
#define AnalogMeasurement3K_REQUIRED_BYTES_FOR_ACN_ENCODING   39110 
#define AnalogMeasurement3K_REQUIRED_BITS_FOR_ACN_ENCODING    312873
#define AnalogMeasurement3K_REQUIRED_BYTES_FOR_XER_ENCODING   208369

void AnalogMeasurement3K_Initialize(AnalogMeasurement3K* pVal);
flag AnalogMeasurement3K_IsConstraintValid(const AnalogMeasurement3K* val, int* pErrCode);


typedef struct {    int nCount; 
    
    T_Float arr[1000];
} AnalogMeasurement1K_samples;

#define AnalogMeasurement1K_samples_REQUIRED_BYTES_FOR_ENCODING       13002 
#define AnalogMeasurement1K_samples_REQUIRED_BITS_FOR_ENCODING        104010
#define AnalogMeasurement1K_samples_REQUIRED_BYTES_FOR_ACN_ENCODING   13002 
#define AnalogMeasurement1K_samples_REQUIRED_BITS_FOR_ACN_ENCODING    104010
#define AnalogMeasurement1K_samples_REQUIRED_BYTES_FOR_XER_ENCODING   69059

void AnalogMeasurement1K_samples_Initialize(AnalogMeasurement1K_samples* pVal);
flag AnalogMeasurement1K_samples_IsConstraintValid(const AnalogMeasurement1K_samples* val, int* pErrCode);
#ifndef ERR_AnalogMeasurement1K_samples 
#define ERR_AnalogMeasurement1K_samples		1003  /*(SIZE(0 .. 1000))*/
#endif

typedef struct {
    SampleAttributes attributes;
    AnalogMeasurement1K_samples samples;
    SeriesCount series;
    BatchSize batch_size;
} AnalogMeasurement1K;

#define AnalogMeasurement1K_REQUIRED_BYTES_FOR_ENCODING       13109 
#define AnalogMeasurement1K_REQUIRED_BITS_FOR_ENCODING        104871
#define AnalogMeasurement1K_REQUIRED_BYTES_FOR_ACN_ENCODING   13109 
#define AnalogMeasurement1K_REQUIRED_BITS_FOR_ACN_ENCODING    104871
#define AnalogMeasurement1K_REQUIRED_BYTES_FOR_XER_ENCODING   70369

void AnalogMeasurement1K_Initialize(AnalogMeasurement1K* pVal);
flag AnalogMeasurement1K_IsConstraintValid(const AnalogMeasurement1K* val, int* pErrCode);


typedef struct {    int nCount; 
    
    T_Float arr[300];
} AnalogMeasurement300_samples;

#define AnalogMeasurement300_samples_REQUIRED_BYTES_FOR_ENCODING       3902 
#define AnalogMeasurement300_samples_REQUIRED_BITS_FOR_ENCODING        31209
#define AnalogMeasurement300_samples_REQUIRED_BYTES_FOR_ACN_ENCODING   3902 
#define AnalogMeasurement300_samples_REQUIRED_BITS_FOR_ACN_ENCODING    31209
#define AnalogMeasurement300_samples_REQUIRED_BYTES_FOR_XER_ENCODING   20761

void AnalogMeasurement300_samples_Initialize(AnalogMeasurement300_samples* pVal);
flag AnalogMeasurement300_samples_IsConstraintValid(const AnalogMeasurement300_samples* val, int* pErrCode);
#ifndef ERR_AnalogMeasurement300_samples 
#define ERR_AnalogMeasurement300_samples		1004  /*(SIZE(0 .. 300))*/
#endif

typedef struct {
    SampleAttributes attributes;
    AnalogMeasurement300_samples samples;
    SeriesCount series;
    BatchSize batch_size;
} AnalogMeasurement300;

#define AnalogMeasurement300_REQUIRED_BYTES_FOR_ENCODING       4009 
#define AnalogMeasurement300_REQUIRED_BITS_FOR_ENCODING        32070
#define AnalogMeasurement300_REQUIRED_BYTES_FOR_ACN_ENCODING   4009 
#define AnalogMeasurement300_REQUIRED_BITS_FOR_ACN_ENCODING    32070
#define AnalogMeasurement300_REQUIRED_BYTES_FOR_XER_ENCODING   22071

void AnalogMeasurement300_Initialize(AnalogMeasurement300* pVal);
flag AnalogMeasurement300_IsConstraintValid(const AnalogMeasurement300* val, int* pErrCode);


 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

flag SeriesCount_Encode(const SeriesCount* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag SeriesCount_Decode(SeriesCount* pVal, BitStream* pBitStrm, int* pErrCode);
flag AnalogMeasurement10K_samples_Encode(const AnalogMeasurement10K_samples* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag AnalogMeasurement10K_samples_Decode(AnalogMeasurement10K_samples* pVal, BitStream* pBitStrm, int* pErrCode);
flag AnalogMeasurement10K_Encode(const AnalogMeasurement10K* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag AnalogMeasurement10K_Decode(AnalogMeasurement10K* pVal, BitStream* pBitStrm, int* pErrCode);
flag AnalogMeasurement3K_samples_Encode(const AnalogMeasurement3K_samples* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag AnalogMeasurement3K_samples_Decode(AnalogMeasurement3K_samples* pVal, BitStream* pBitStrm, int* pErrCode);
flag AnalogMeasurement3K_Encode(const AnalogMeasurement3K* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag AnalogMeasurement3K_Decode(AnalogMeasurement3K* pVal, BitStream* pBitStrm, int* pErrCode);
flag AnalogMeasurement1K_samples_Encode(const AnalogMeasurement1K_samples* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag AnalogMeasurement1K_samples_Decode(AnalogMeasurement1K_samples* pVal, BitStream* pBitStrm, int* pErrCode);
flag AnalogMeasurement1K_Encode(const AnalogMeasurement1K* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag AnalogMeasurement1K_Decode(AnalogMeasurement1K* pVal, BitStream* pBitStrm, int* pErrCode);
flag AnalogMeasurement300_samples_Encode(const AnalogMeasurement300_samples* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag AnalogMeasurement300_samples_Decode(AnalogMeasurement300_samples* pVal, BitStream* pBitStrm, int* pErrCode);
flag AnalogMeasurement300_Encode(const AnalogMeasurement300* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag AnalogMeasurement300_Decode(AnalogMeasurement300* pVal, BitStream* pBitStrm, int* pErrCode); 


#ifdef  __cplusplus
}

#endif

#endif
