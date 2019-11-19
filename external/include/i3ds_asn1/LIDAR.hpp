#ifndef i3ds_asn1_GENERATED_ASN1SCC_LIDAR_H
#define i3ds_asn1_GENERATED_ASN1SCC_LIDAR_H
/*
Code automatically generated by asn1scc tool
*/
#include <i3ds_asn1/asn1crt.hpp>
#include <i3ds_asn1/asn1crt_encoding.hpp>

#include <i3ds_asn1/Region.hpp>
#include <i3ds_asn1/taste-types.hpp>
namespace i3ds_asn1 {

#ifdef  __cplusplus
extern "C" {
#endif


/*-- LIDARRegion --------------------------------------------*/
typedef struct {
    T_Boolean enable;
    PolarRegion region;

} LIDARRegion;

void LIDARRegion_Initialize(LIDARRegion* pVal);

#define i3ds_asn1_ERR_LIDARREGION		10962  /**/
#define i3ds_asn1_i3ds_asn1_ERR_LIDARREGION_ENABLE_2		10897  /**/
#define i3ds_asn1_i3ds_asn1_ERR_LIDARREGION_REGION_2		10957  /**/
flag LIDARRegion_IsConstraintValid(const LIDARRegion* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_LIDARREGION		10963  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_LIDARREGION_ENABLE_2		10898  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_LIDARREGION_REGION_2		10958  /**/
#define i3ds_asn1_LIDARRegion_REQUIRED_BYTES_FOR_ENCODING       53 
#define i3ds_asn1_LIDARRegion_REQUIRED_BITS_FOR_ENCODING        417

flag LIDARRegion_Encode(const LIDARRegion* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_LIDARREGION		10964  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_LIDARREGION_ENABLE_2		10899  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_LIDARREGION_REGION_2		10959  /**/
flag LIDARRegion_Decode(LIDARRegion* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- LIDARConfiguration --------------------------------------------*/
typedef struct {
    T_Boolean region_enabled;
    PolarRegion region;

} LIDARConfiguration;

void LIDARConfiguration_Initialize(LIDARConfiguration* pVal);

#define i3ds_asn1_ERR_LIDARCONFIGURATION		11041  /**/
#define i3ds_asn1_i3ds_asn1_ERR_LIDARCONFIGURATION_REGION_ENABLED_2		10976  /**/
#define i3ds_asn1_i3ds_asn1_ERR_LIDARCONFIGURATION_REGION_2		11036  /**/
flag LIDARConfiguration_IsConstraintValid(const LIDARConfiguration* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_LIDARCONFIGURATION		11042  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_LIDARCONFIGURATION_REGION_ENABLED_2		10977  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_LIDARCONFIGURATION_REGION_2		11037  /**/
#define i3ds_asn1_LIDARConfiguration_REQUIRED_BYTES_FOR_ENCODING       53 
#define i3ds_asn1_LIDARConfiguration_REQUIRED_BITS_FOR_ENCODING        417

flag LIDARConfiguration_Encode(const LIDARConfiguration* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_LIDARCONFIGURATION		11043  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_LIDARCONFIGURATION_REGION_ENABLED_2		10978  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_LIDARCONFIGURATION_REGION_2		11038  /**/
flag LIDARConfiguration_Decode(LIDARConfiguration* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

} // namespace i3ds_asn1
#endif
