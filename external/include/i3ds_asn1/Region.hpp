#ifndef i3ds_asn1_GENERATED_ASN1SCC_Region_H
#define i3ds_asn1_GENERATED_ASN1SCC_Region_H
/*
Code automatically generated by asn1scc tool
*/
#include <i3ds_asn1/asn1crt.hpp>
#include <i3ds_asn1/asn1crt_encoding.hpp>

#include <i3ds_asn1/taste-extended.hpp>

namespace i3ds_asn1 {


/*-- PlanarRegion --------------------------------------------*/
typedef struct {
    T_UInt16 offset_x;
    T_UInt16 offset_y;
    T_UInt16 size_x;
    T_UInt16 size_y;

} PlanarRegion;

void PlanarRegion_Initialize(PlanarRegion* pVal);

#define i3ds_asn1_ERR_PLANARREGION		3718  /**/
#define i3ds_asn1_i3ds_asn1_ERR_PLANARREGION_OFFSET_X_2		3669  /**/
#define i3ds_asn1_i3ds_asn1_ERR_PLANARREGION_OFFSET_Y_2		3683  /**/
#define i3ds_asn1_i3ds_asn1_ERR_PLANARREGION_SIZE_X_2		3697  /**/
#define i3ds_asn1_i3ds_asn1_ERR_PLANARREGION_SIZE_Y_2		3711  /**/
flag PlanarRegion_IsConstraintValid(const PlanarRegion* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_PLANARREGION		3719  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_PLANARREGION_OFFSET_X_2		3670  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_PLANARREGION_OFFSET_Y_2		3684  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_PLANARREGION_SIZE_X_2		3698  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_PLANARREGION_SIZE_Y_2		3712  /**/
#define i3ds_asn1_PlanarRegion_REQUIRED_BYTES_FOR_ENCODING       8 
#define i3ds_asn1_PlanarRegion_REQUIRED_BITS_FOR_ENCODING        64

flag PlanarRegion_Encode(const PlanarRegion* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_PLANARREGION		3720  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_PLANARREGION_OFFSET_X_2		3671  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_PLANARREGION_OFFSET_Y_2		3685  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_PLANARREGION_SIZE_X_2		3699  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_PLANARREGION_SIZE_Y_2		3713  /**/
flag PlanarRegion_Decode(PlanarRegion* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- PolarRegion --------------------------------------------*/
typedef struct {
    T_Float offset_x;
    T_Float offset_y;
    T_Float size_x;
    T_Float size_y;

} PolarRegion;

void PolarRegion_Initialize(PolarRegion* pVal);

#define i3ds_asn1_ERR_POLARREGION		3781  /**/
#define i3ds_asn1_i3ds_asn1_ERR_POLARREGION_OFFSET_X_2		3732  /**/
#define i3ds_asn1_i3ds_asn1_ERR_POLARREGION_OFFSET_Y_2		3746  /**/
#define i3ds_asn1_i3ds_asn1_ERR_POLARREGION_SIZE_X_2		3760  /**/
#define i3ds_asn1_i3ds_asn1_ERR_POLARREGION_SIZE_Y_2		3774  /**/
flag PolarRegion_IsConstraintValid(const PolarRegion* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_POLARREGION		3782  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_POLARREGION_OFFSET_X_2		3733  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_POLARREGION_OFFSET_Y_2		3747  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_POLARREGION_SIZE_X_2		3761  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_POLARREGION_SIZE_Y_2		3775  /**/
#define i3ds_asn1_PolarRegion_REQUIRED_BYTES_FOR_ENCODING       52 
#define i3ds_asn1_PolarRegion_REQUIRED_BITS_FOR_ENCODING        416

flag PolarRegion_Encode(const PolarRegion* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_POLARREGION		3783  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_POLARREGION_OFFSET_X_2		3734  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_POLARREGION_OFFSET_Y_2		3748  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_POLARREGION_SIZE_X_2		3762  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_POLARREGION_SIZE_Y_2		3776  /**/
flag PolarRegion_Decode(PolarRegion* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 



} // namespace i3ds_asn1
#endif
