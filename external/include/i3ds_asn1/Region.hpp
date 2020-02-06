#ifndef i3ds_asn1_GENERATED_ASN1SCC_Region_H
#define i3ds_asn1_GENERATED_ASN1SCC_Region_H
/*
Code automatically generated by asn1scc tool
*/
#include <i3ds_asn1/asn1crt.hpp>
#include <i3ds_asn1/asn1crt_encoding.hpp>

#include <i3ds_asn1/taste-extended.hpp>
namespace i3ds_asn1 {

#ifdef  __cplusplus
extern "C" {
#endif


/*-- PlanarRegion --------------------------------------------*/
typedef struct {
    T_UInt16 offset_x;
    T_UInt16 offset_y;
    T_UInt16 size_x;
    T_UInt16 size_y;

} PlanarRegion;

void PlanarRegion_Initialize(PlanarRegion* pVal);

#define i3ds_asn1_ERR_PLANARREGION		11548  /**/
#define i3ds_asn1_i3ds_asn1_ERR_PLANARREGION_OFFSET_X_2		11507  /**/
#define i3ds_asn1_i3ds_asn1_ERR_PLANARREGION_OFFSET_Y_2		11519  /**/
#define i3ds_asn1_i3ds_asn1_ERR_PLANARREGION_SIZE_X_2		11531  /**/
#define i3ds_asn1_i3ds_asn1_ERR_PLANARREGION_SIZE_Y_2		11543  /**/
flag PlanarRegion_IsConstraintValid(const PlanarRegion* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_PLANARREGION		11549  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_PLANARREGION_OFFSET_X_2		11508  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_PLANARREGION_OFFSET_Y_2		11520  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_PLANARREGION_SIZE_X_2		11532  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_PLANARREGION_SIZE_Y_2		11544  /**/
#define i3ds_asn1_PlanarRegion_REQUIRED_BYTES_FOR_ENCODING       8 
#define i3ds_asn1_PlanarRegion_REQUIRED_BITS_FOR_ENCODING        64

flag PlanarRegion_Encode(const PlanarRegion* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_PLANARREGION		11550  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_PLANARREGION_OFFSET_X_2		11509  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_PLANARREGION_OFFSET_Y_2		11521  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_PLANARREGION_SIZE_X_2		11533  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_PLANARREGION_SIZE_Y_2		11545  /**/
flag PlanarRegion_Decode(PlanarRegion* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- PolarRegion --------------------------------------------*/
typedef struct {
    T_Float offset_x;
    T_Float offset_y;
    T_Float size_x;
    T_Float size_y;

} PolarRegion;

void PolarRegion_Initialize(PolarRegion* pVal);

#define i3ds_asn1_ERR_POLARREGION		11603  /**/
#define i3ds_asn1_i3ds_asn1_ERR_POLARREGION_OFFSET_X_2		11562  /**/
#define i3ds_asn1_i3ds_asn1_ERR_POLARREGION_OFFSET_Y_2		11574  /**/
#define i3ds_asn1_i3ds_asn1_ERR_POLARREGION_SIZE_X_2		11586  /**/
#define i3ds_asn1_i3ds_asn1_ERR_POLARREGION_SIZE_Y_2		11598  /**/
flag PolarRegion_IsConstraintValid(const PolarRegion* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_POLARREGION		11604  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_POLARREGION_OFFSET_X_2		11563  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_POLARREGION_OFFSET_Y_2		11575  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_POLARREGION_SIZE_X_2		11587  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_POLARREGION_SIZE_Y_2		11599  /**/
#define i3ds_asn1_PolarRegion_REQUIRED_BYTES_FOR_ENCODING       52 
#define i3ds_asn1_PolarRegion_REQUIRED_BITS_FOR_ENCODING        416

flag PolarRegion_Encode(const PolarRegion* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_POLARREGION		11605  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_POLARREGION_OFFSET_X_2		11564  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_POLARREGION_OFFSET_Y_2		11576  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_POLARREGION_SIZE_X_2		11588  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_POLARREGION_SIZE_Y_2		11600  /**/
flag PolarRegion_Decode(PolarRegion* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

} // namespace i3ds_asn1
#endif
