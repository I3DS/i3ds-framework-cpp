#ifndef i3ds_asn1_GENERATED_ASN1SCC_Radar_H
#define i3ds_asn1_GENERATED_ASN1SCC_Radar_H
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


/*-- RadarRegion --------------------------------------------*/
typedef struct {
    T_Boolean enable;
    PlanarRegion region;

} RadarRegion;

void RadarRegion_Initialize(RadarRegion* pVal);

#define i3ds_asn1_ERR_RADARREGION		11414  /**/
#define i3ds_asn1_i3ds_asn1_ERR_RADARREGION_ENABLE_2		11349  /**/
#define i3ds_asn1_i3ds_asn1_ERR_RADARREGION_REGION_2		11409  /**/
flag RadarRegion_IsConstraintValid(const RadarRegion* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_RADARREGION		11415  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_RADARREGION_ENABLE_2		11350  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_RADARREGION_REGION_2		11410  /**/
#define i3ds_asn1_RadarRegion_REQUIRED_BYTES_FOR_ENCODING       9 
#define i3ds_asn1_RadarRegion_REQUIRED_BITS_FOR_ENCODING        65

flag RadarRegion_Encode(const RadarRegion* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_RADARREGION		11416  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_RADARREGION_ENABLE_2		11351  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_RADARREGION_REGION_2		11411  /**/
flag RadarRegion_Decode(RadarRegion* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- RadarConfiguration --------------------------------------------*/
typedef struct {
    T_Boolean region_enabled;
    PlanarRegion region;

} RadarConfiguration;

void RadarConfiguration_Initialize(RadarConfiguration* pVal);

#define i3ds_asn1_ERR_RADARCONFIGURATION		11493  /**/
#define i3ds_asn1_i3ds_asn1_ERR_RADARCONFIGURATION_REGION_ENABLED_2		11428  /**/
#define i3ds_asn1_i3ds_asn1_ERR_RADARCONFIGURATION_REGION_2		11488  /**/
flag RadarConfiguration_IsConstraintValid(const RadarConfiguration* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_RADARCONFIGURATION		11494  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_RADARCONFIGURATION_REGION_ENABLED_2		11429  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_RADARCONFIGURATION_REGION_2		11489  /**/
#define i3ds_asn1_RadarConfiguration_REQUIRED_BYTES_FOR_ENCODING       9 
#define i3ds_asn1_RadarConfiguration_REQUIRED_BITS_FOR_ENCODING        65

flag RadarConfiguration_Encode(const RadarConfiguration* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_RADARCONFIGURATION		11495  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_RADARCONFIGURATION_REGION_ENABLED_2		11430  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_RADARCONFIGURATION_REGION_2		11490  /**/
flag RadarConfiguration_Decode(RadarConfiguration* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

} // namespace i3ds_asn1
#endif
