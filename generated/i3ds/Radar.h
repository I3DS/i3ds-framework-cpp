#ifndef GENERATED_ASN1SCC_Radar_H
#define GENERATED_ASN1SCC_Radar_H
/*
Code automatically generated by asn1scc tool
*/
#include "taste-extended.h"
#include "taste-types.h"
#include "DepthMap.h"
#include "Region.h"
#include "SampleAttribute.h"
#include "asn1crt.h"

#ifdef  __cplusplus
extern "C" {
#endif



typedef struct {    int nCount; 
    
    Depth_validity_t arr[400000];
} RadarMeasurement400K_validity;

#define RadarMeasurement400K_validity_REQUIRED_BYTES_FOR_ENCODING       100009 
#define RadarMeasurement400K_validity_REQUIRED_BITS_FOR_ENCODING        800072
#define RadarMeasurement400K_validity_REQUIRED_BYTES_FOR_ACN_ENCODING   100003 
#define RadarMeasurement400K_validity_REQUIRED_BITS_FOR_ACN_ENCODING    800019
#define RadarMeasurement400K_validity_REQUIRED_BYTES_FOR_XER_ENCODING   16800063

void RadarMeasurement400K_validity_Initialize(RadarMeasurement400K_validity* pVal);
flag RadarMeasurement400K_validity_IsConstraintValid(const RadarMeasurement400K_validity* val, int* pErrCode);
#ifndef ERR_RadarMeasurement400K_validity 
#define ERR_RadarMeasurement400K_validity		1001  /*(SIZE(1 .. 400000))*/
#endif

typedef struct {    int nCount; 
    
    Depth_validity_t arr[200000];
} RadarMeasurement200K_validity;

#define RadarMeasurement200K_validity_REQUIRED_BYTES_FOR_ENCODING       50006 
#define RadarMeasurement200K_validity_REQUIRED_BITS_FOR_ENCODING        400048
#define RadarMeasurement200K_validity_REQUIRED_BYTES_FOR_ACN_ENCODING   50003 
#define RadarMeasurement200K_validity_REQUIRED_BITS_FOR_ACN_ENCODING    400018
#define RadarMeasurement200K_validity_REQUIRED_BYTES_FOR_XER_ENCODING   8400063

void RadarMeasurement200K_validity_Initialize(RadarMeasurement200K_validity* pVal);
flag RadarMeasurement200K_validity_IsConstraintValid(const RadarMeasurement200K_validity* val, int* pErrCode);
#ifndef ERR_RadarMeasurement200K_validity 
#define ERR_RadarMeasurement200K_validity		1002  /*(SIZE(1 .. 200000))*/
#endif

typedef struct {    int nCount; 
    
    Depth_validity_t arr[100000];
} RadarMeasurement100K_validity;

#define RadarMeasurement100K_validity_REQUIRED_BYTES_FOR_ENCODING       25004 
#define RadarMeasurement100K_validity_REQUIRED_BITS_FOR_ENCODING        200032
#define RadarMeasurement100K_validity_REQUIRED_BYTES_FOR_ACN_ENCODING   25003 
#define RadarMeasurement100K_validity_REQUIRED_BITS_FOR_ACN_ENCODING    200017
#define RadarMeasurement100K_validity_REQUIRED_BYTES_FOR_XER_ENCODING   4200063

void RadarMeasurement100K_validity_Initialize(RadarMeasurement100K_validity* pVal);
flag RadarMeasurement100K_validity_IsConstraintValid(const RadarMeasurement100K_validity* val, int* pErrCode);
#ifndef ERR_RadarMeasurement100K_validity 
#define ERR_RadarMeasurement100K_validity		1003  /*(SIZE(1 .. 100000))*/
#endif

typedef struct {    int nCount; 
    
    T_Float arr[400000];
} RadarMeasurement400K_distances;

#define RadarMeasurement400K_distances_REQUIRED_BYTES_FOR_ENCODING       5200009 
#define RadarMeasurement400K_distances_REQUIRED_BITS_FOR_ENCODING        41600072
#define RadarMeasurement400K_distances_REQUIRED_BYTES_FOR_ACN_ENCODING   5200003 
#define RadarMeasurement400K_distances_REQUIRED_BITS_FOR_ACN_ENCODING    41600019
#define RadarMeasurement400K_distances_REQUIRED_BYTES_FOR_XER_ENCODING   27600065

void RadarMeasurement400K_distances_Initialize(RadarMeasurement400K_distances* pVal);
flag RadarMeasurement400K_distances_IsConstraintValid(const RadarMeasurement400K_distances* val, int* pErrCode);
#ifndef ERR_RadarMeasurement400K_distances 
#define ERR_RadarMeasurement400K_distances		1004  /*(SIZE(1 .. 400000))*/
#endif

typedef struct {    int nCount; 
    
    T_Float arr[200000];
} RadarMeasurement200K_distances;

#define RadarMeasurement200K_distances_REQUIRED_BYTES_FOR_ENCODING       2600006 
#define RadarMeasurement200K_distances_REQUIRED_BITS_FOR_ENCODING        20800048
#define RadarMeasurement200K_distances_REQUIRED_BYTES_FOR_ACN_ENCODING   2600003 
#define RadarMeasurement200K_distances_REQUIRED_BITS_FOR_ACN_ENCODING    20800018
#define RadarMeasurement200K_distances_REQUIRED_BYTES_FOR_XER_ENCODING   13800065

void RadarMeasurement200K_distances_Initialize(RadarMeasurement200K_distances* pVal);
flag RadarMeasurement200K_distances_IsConstraintValid(const RadarMeasurement200K_distances* val, int* pErrCode);
#ifndef ERR_RadarMeasurement200K_distances 
#define ERR_RadarMeasurement200K_distances		1005  /*(SIZE(1 .. 200000))*/
#endif

typedef struct {    int nCount; 
    
    T_Float arr[100000];
} RadarMeasurement100K_distances;

#define RadarMeasurement100K_distances_REQUIRED_BYTES_FOR_ENCODING       1300004 
#define RadarMeasurement100K_distances_REQUIRED_BITS_FOR_ENCODING        10400032
#define RadarMeasurement100K_distances_REQUIRED_BYTES_FOR_ACN_ENCODING   1300003 
#define RadarMeasurement100K_distances_REQUIRED_BITS_FOR_ACN_ENCODING    10400017
#define RadarMeasurement100K_distances_REQUIRED_BYTES_FOR_XER_ENCODING   6900065

void RadarMeasurement100K_distances_Initialize(RadarMeasurement100K_distances* pVal);
flag RadarMeasurement100K_distances_IsConstraintValid(const RadarMeasurement100K_distances* val, int* pErrCode);
#ifndef ERR_RadarMeasurement100K_distances 
#define ERR_RadarMeasurement100K_distances		1006  /*(SIZE(1 .. 100000))*/
#endif

typedef struct {
    SampleAttributes attributes;
    RadarMeasurement100K_distances distances;
    RadarMeasurement100K_validity validity;
    PlanarRegion region;
} RadarMeasurement100K;

#define RadarMeasurement100K_REQUIRED_BYTES_FOR_ENCODING       1325119 
#define RadarMeasurement100K_REQUIRED_BITS_FOR_ENCODING        10600949
#define RadarMeasurement100K_REQUIRED_BYTES_FOR_ACN_ENCODING   1325115 
#define RadarMeasurement100K_REQUIRED_BITS_FOR_ACN_ENCODING    10600919
#define RadarMeasurement100K_REQUIRED_BYTES_FOR_XER_ENCODING   11101487

void RadarMeasurement100K_Initialize(RadarMeasurement100K* pVal);
flag RadarMeasurement100K_IsConstraintValid(const RadarMeasurement100K* val, int* pErrCode);


typedef struct {
    SampleAttributes attributes;
    RadarMeasurement200K_distances distances;
    RadarMeasurement200K_validity validity;
    PlanarRegion region;
} RadarMeasurement200K;

#define RadarMeasurement200K_REQUIRED_BYTES_FOR_ENCODING       2650123 
#define RadarMeasurement200K_REQUIRED_BITS_FOR_ENCODING        21200981
#define RadarMeasurement200K_REQUIRED_BYTES_FOR_ACN_ENCODING   2650116 
#define RadarMeasurement200K_REQUIRED_BITS_FOR_ACN_ENCODING    21200921
#define RadarMeasurement200K_REQUIRED_BYTES_FOR_XER_ENCODING   22201487

void RadarMeasurement200K_Initialize(RadarMeasurement200K* pVal);
flag RadarMeasurement200K_IsConstraintValid(const RadarMeasurement200K* val, int* pErrCode);


typedef struct {
    SampleAttributes attributes;
    RadarMeasurement400K_distances distances;
    RadarMeasurement400K_validity validity;
    PlanarRegion region;
} RadarMeasurement400K;

#define RadarMeasurement400K_REQUIRED_BYTES_FOR_ENCODING       5300129 
#define RadarMeasurement400K_REQUIRED_BITS_FOR_ENCODING        42401029
#define RadarMeasurement400K_REQUIRED_BYTES_FOR_ACN_ENCODING   5300116 
#define RadarMeasurement400K_REQUIRED_BITS_FOR_ACN_ENCODING    42400923
#define RadarMeasurement400K_REQUIRED_BYTES_FOR_XER_ENCODING   44401487

void RadarMeasurement400K_Initialize(RadarMeasurement400K* pVal);
flag RadarMeasurement400K_IsConstraintValid(const RadarMeasurement400K* val, int* pErrCode);


typedef struct {
    T_Boolean enable;
    PlanarRegion region;
} RadarRegion;

#define RadarRegion_REQUIRED_BYTES_FOR_ENCODING       9 
#define RadarRegion_REQUIRED_BITS_FOR_ENCODING        65
#define RadarRegion_REQUIRED_BYTES_FOR_ACN_ENCODING   9 
#define RadarRegion_REQUIRED_BITS_FOR_ACN_ENCODING    65
#define RadarRegion_REQUIRED_BYTES_FOR_XER_ENCODING   230

void RadarRegion_Initialize(RadarRegion* pVal);
flag RadarRegion_IsConstraintValid(const RadarRegion* val, int* pErrCode);


typedef struct {
    T_Boolean region_enabled;
    PlanarRegion region;
} RadarConfiguration;

#define RadarConfiguration_REQUIRED_BYTES_FOR_ENCODING       9 
#define RadarConfiguration_REQUIRED_BITS_FOR_ENCODING        65
#define RadarConfiguration_REQUIRED_BYTES_FOR_ACN_ENCODING   9 
#define RadarConfiguration_REQUIRED_BITS_FOR_ACN_ENCODING    65
#define RadarConfiguration_REQUIRED_BYTES_FOR_XER_ENCODING   260

void RadarConfiguration_Initialize(RadarConfiguration* pVal);
flag RadarConfiguration_IsConstraintValid(const RadarConfiguration* val, int* pErrCode);


 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

flag RadarMeasurement400K_validity_Encode(const RadarMeasurement400K_validity* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag RadarMeasurement400K_validity_Decode(RadarMeasurement400K_validity* pVal, BitStream* pBitStrm, int* pErrCode);
flag RadarMeasurement200K_validity_Encode(const RadarMeasurement200K_validity* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag RadarMeasurement200K_validity_Decode(RadarMeasurement200K_validity* pVal, BitStream* pBitStrm, int* pErrCode);
flag RadarMeasurement100K_validity_Encode(const RadarMeasurement100K_validity* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag RadarMeasurement100K_validity_Decode(RadarMeasurement100K_validity* pVal, BitStream* pBitStrm, int* pErrCode);
flag RadarMeasurement400K_distances_Encode(const RadarMeasurement400K_distances* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag RadarMeasurement400K_distances_Decode(RadarMeasurement400K_distances* pVal, BitStream* pBitStrm, int* pErrCode);
flag RadarMeasurement200K_distances_Encode(const RadarMeasurement200K_distances* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag RadarMeasurement200K_distances_Decode(RadarMeasurement200K_distances* pVal, BitStream* pBitStrm, int* pErrCode);
flag RadarMeasurement100K_distances_Encode(const RadarMeasurement100K_distances* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag RadarMeasurement100K_distances_Decode(RadarMeasurement100K_distances* pVal, BitStream* pBitStrm, int* pErrCode);
flag RadarMeasurement100K_Encode(const RadarMeasurement100K* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag RadarMeasurement100K_Decode(RadarMeasurement100K* pVal, BitStream* pBitStrm, int* pErrCode);
flag RadarMeasurement200K_Encode(const RadarMeasurement200K* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag RadarMeasurement200K_Decode(RadarMeasurement200K* pVal, BitStream* pBitStrm, int* pErrCode);
flag RadarMeasurement400K_Encode(const RadarMeasurement400K* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag RadarMeasurement400K_Decode(RadarMeasurement400K* pVal, BitStream* pBitStrm, int* pErrCode);
flag RadarRegion_Encode(const RadarRegion* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag RadarRegion_Decode(RadarRegion* pVal, BitStream* pBitStrm, int* pErrCode);
flag RadarConfiguration_Encode(const RadarConfiguration* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag RadarConfiguration_Decode(RadarConfiguration* pVal, BitStream* pBitStrm, int* pErrCode); 


#ifdef  __cplusplus
}

#endif

#endif
