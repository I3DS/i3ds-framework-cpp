#ifndef GENERATED_ASN1SCC_Region_H
#define GENERATED_ASN1SCC_Region_H
/*
Code automatically generated by asn1scc tool
*/
#include "taste-extended.h"
#include "asn1crt.h"

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

#define ERR_PLANARREGION		2622  /**/
#define ERR_PLANARREGION_OFFSET_X		2578  /**/
#define ERR_PLANARREGION_OFFSET_Y		2589  /**/
#define ERR_PLANARREGION_SIZE_X		2600  /**/
#define ERR_PLANARREGION_SIZE_Y		2611  /**/
flag PlanarRegion_IsConstraintValid(const PlanarRegion* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_PLANARREGION		2623  /**/
#define ERR_UPER_ENCODE_PLANARREGION_OFFSET_X_2		2585  /**/
#define ERR_UPER_ENCODE_PLANARREGION_OFFSET_Y_2		2596  /**/
#define ERR_UPER_ENCODE_PLANARREGION_SIZE_X_2		2607  /**/
#define ERR_UPER_ENCODE_PLANARREGION_SIZE_Y_2		2618  /**/
#define PlanarRegion_REQUIRED_BYTES_FOR_ENCODING       8 
#define PlanarRegion_REQUIRED_BITS_FOR_ENCODING        64

flag PlanarRegion_Encode(const PlanarRegion* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_PLANARREGION		2624  /**/
#define ERR_UPER_DECODE_PLANARREGION_OFFSET_X_2		2586  /**/
#define ERR_UPER_DECODE_PLANARREGION_OFFSET_Y_2		2597  /**/
#define ERR_UPER_DECODE_PLANARREGION_SIZE_X_2		2608  /**/
#define ERR_UPER_DECODE_PLANARREGION_SIZE_Y_2		2619  /**/
flag PlanarRegion_Decode(PlanarRegion* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- PolarRegion --------------------------------------------*/
typedef struct {
    T_Float offset_x;
    T_Float offset_y;
    T_Float size_x;
    T_Float size_y;

} PolarRegion;

void PolarRegion_Initialize(PolarRegion* pVal);

#define ERR_POLARREGION		2673  /**/
#define ERR_POLARREGION_OFFSET_X		2629  /**/
#define ERR_POLARREGION_OFFSET_Y		2640  /**/
#define ERR_POLARREGION_SIZE_X		2651  /**/
#define ERR_POLARREGION_SIZE_Y		2662  /**/
flag PolarRegion_IsConstraintValid(const PolarRegion* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_POLARREGION		2674  /**/
#define ERR_UPER_ENCODE_POLARREGION_OFFSET_X_2		2636  /**/
#define ERR_UPER_ENCODE_POLARREGION_OFFSET_Y_2		2647  /**/
#define ERR_UPER_ENCODE_POLARREGION_SIZE_X_2		2658  /**/
#define ERR_UPER_ENCODE_POLARREGION_SIZE_Y_2		2669  /**/
#define PolarRegion_REQUIRED_BYTES_FOR_ENCODING       52 
#define PolarRegion_REQUIRED_BITS_FOR_ENCODING        416

flag PolarRegion_Encode(const PolarRegion* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_POLARREGION		2675  /**/
#define ERR_UPER_DECODE_POLARREGION_OFFSET_X_2		2637  /**/
#define ERR_UPER_DECODE_POLARREGION_OFFSET_Y_2		2648  /**/
#define ERR_UPER_DECODE_POLARREGION_SIZE_X_2		2659  /**/
#define ERR_UPER_DECODE_POLARREGION_SIZE_Y_2		2670  /**/
flag PolarRegion_Decode(PolarRegion* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

#endif
