#ifndef i3ds_asn1_GENERATED_ASN1SCC_ToFCamera_H
#define i3ds_asn1_GENERATED_ASN1SCC_ToFCamera_H
/*
Code automatically generated by asn1scc tool
*/
#include <i3ds_asn1/asn1crt.hpp>
#include <i3ds_asn1/asn1crt_encoding.hpp>

#include <i3ds_asn1/taste-extended.hpp>
#include <i3ds_asn1/Region.hpp>
#include <i3ds_asn1/taste-types.hpp>

namespace i3ds_asn1 {


/*-- ToFRange --------------------------------------------*/
typedef struct {
    T_Float min_depth;
    T_Float max_depth;

} ToFRange;

void ToFRange_Initialize(ToFRange* pVal);

#define i3ds_asn1_ERR_TOFRANGE		12583  /**/
#define i3ds_asn1_i3ds_asn1_ERR_TOFRANGE_MIN_DEPTH_2		12566  /**/
#define i3ds_asn1_i3ds_asn1_ERR_TOFRANGE_MAX_DEPTH_2		12578  /**/
flag ToFRange_IsConstraintValid(const ToFRange* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_TOFRANGE		12584  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_TOFRANGE_MIN_DEPTH_2		12567  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_TOFRANGE_MAX_DEPTH_2		12579  /**/
#define i3ds_asn1_ToFRange_REQUIRED_BYTES_FOR_ENCODING       26 
#define i3ds_asn1_ToFRange_REQUIRED_BITS_FOR_ENCODING        208

flag ToFRange_Encode(const ToFRange* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_TOFRANGE		12585  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_TOFRANGE_MIN_DEPTH_2		12568  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_TOFRANGE_MAX_DEPTH_2		12580  /**/
flag ToFRange_Decode(ToFRange* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- ToFRegion --------------------------------------------*/
typedef struct {
    T_Boolean enable;
    PlanarRegion region;

} ToFRegion;

void ToFRegion_Initialize(ToFRegion* pVal);

#define i3ds_asn1_ERR_TOFREGION		12552  /**/
#define i3ds_asn1_i3ds_asn1_ERR_TOFREGION_ENABLE_2		12487  /**/
#define i3ds_asn1_i3ds_asn1_ERR_TOFREGION_REGION_2		12547  /**/
flag ToFRegion_IsConstraintValid(const ToFRegion* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_TOFREGION		12553  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_TOFREGION_ENABLE_2		12488  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_TOFREGION_REGION_2		12548  /**/
#define i3ds_asn1_ToFRegion_REQUIRED_BYTES_FOR_ENCODING       9 
#define i3ds_asn1_ToFRegion_REQUIRED_BITS_FOR_ENCODING        65

flag ToFRegion_Encode(const ToFRegion* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_TOFREGION		12554  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_TOFREGION_ENABLE_2		12489  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_TOFREGION_REGION_2		12549  /**/
flag ToFRegion_Decode(ToFRegion* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- ToFConfiguration --------------------------------------------*/
typedef struct {
    T_Boolean region_enabled;
    PlanarRegion region;
    T_Float min_depth;
    T_Float max_depth;

} ToFConfiguration;

void ToFConfiguration_Initialize(ToFConfiguration* pVal);

#define i3ds_asn1_ERR_TOFCONFIGURATION		12686  /**/
#define i3ds_asn1_i3ds_asn1_ERR_TOFCONFIGURATION_REGION_ENABLED_2		12597  /**/
#define i3ds_asn1_i3ds_asn1_ERR_TOFCONFIGURATION_REGION_2		12657  /**/
#define i3ds_asn1_i3ds_asn1_ERR_TOFCONFIGURATION_MIN_DEPTH_2		12669  /**/
#define i3ds_asn1_i3ds_asn1_ERR_TOFCONFIGURATION_MAX_DEPTH_2		12681  /**/
flag ToFConfiguration_IsConstraintValid(const ToFConfiguration* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_TOFCONFIGURATION		12687  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_TOFCONFIGURATION_REGION_ENABLED_2		12598  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_TOFCONFIGURATION_REGION_2		12658  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_TOFCONFIGURATION_MIN_DEPTH_2		12670  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_TOFCONFIGURATION_MAX_DEPTH_2		12682  /**/
#define i3ds_asn1_ToFConfiguration_REQUIRED_BYTES_FOR_ENCODING       35 
#define i3ds_asn1_ToFConfiguration_REQUIRED_BITS_FOR_ENCODING        273

flag ToFConfiguration_Encode(const ToFConfiguration* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_TOFCONFIGURATION		12688  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_TOFCONFIGURATION_REGION_ENABLED_2		12599  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_TOFCONFIGURATION_REGION_2		12659  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_TOFCONFIGURATION_MIN_DEPTH_2		12671  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_TOFCONFIGURATION_MAX_DEPTH_2		12683  /**/
flag ToFConfiguration_Decode(ToFConfiguration* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 



} // namespace i3ds_asn1
#endif
