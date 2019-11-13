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

#define ERR_PLANARREGION		10752  /**/
#define ERR_PLANARREGION_OFFSET_X		10708  /**/
#define ERR_PLANARREGION_OFFSET_Y		10719  /**/
#define ERR_PLANARREGION_SIZE_X		10730  /**/
#define ERR_PLANARREGION_SIZE_Y		10741  /**/
flag PlanarRegion_IsConstraintValid(const PlanarRegion* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_PLANARREGION		10753  /**/
#define ERR_UPER_ENCODE_PLANARREGION_OFFSET_X_2		10715  /**/
#define ERR_UPER_ENCODE_PLANARREGION_OFFSET_Y_2		10726  /**/
#define ERR_UPER_ENCODE_PLANARREGION_SIZE_X_2		10737  /**/
#define ERR_UPER_ENCODE_PLANARREGION_SIZE_Y_2		10748  /**/
#define PlanarRegion_REQUIRED_BYTES_FOR_ENCODING       8 
#define PlanarRegion_REQUIRED_BITS_FOR_ENCODING        64

flag PlanarRegion_Encode(const PlanarRegion* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_PLANARREGION		10754  /**/
#define ERR_UPER_DECODE_PLANARREGION_OFFSET_X_2		10716  /**/
#define ERR_UPER_DECODE_PLANARREGION_OFFSET_Y_2		10727  /**/
#define ERR_UPER_DECODE_PLANARREGION_SIZE_X_2		10738  /**/
#define ERR_UPER_DECODE_PLANARREGION_SIZE_Y_2		10749  /**/
flag PlanarRegion_Decode(PlanarRegion* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- PolarRegion --------------------------------------------*/
typedef struct {
    T_Float offset_x;
    T_Float offset_y;
    T_Float size_x;
    T_Float size_y;

} PolarRegion;

void PolarRegion_Initialize(PolarRegion* pVal);

#define ERR_POLARREGION		10803  /**/
#define ERR_POLARREGION_OFFSET_X		10759  /**/
#define ERR_POLARREGION_OFFSET_Y		10770  /**/
#define ERR_POLARREGION_SIZE_X		10781  /**/
#define ERR_POLARREGION_SIZE_Y		10792  /**/
flag PolarRegion_IsConstraintValid(const PolarRegion* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_POLARREGION		10804  /**/
#define ERR_UPER_ENCODE_POLARREGION_OFFSET_X_2		10766  /**/
#define ERR_UPER_ENCODE_POLARREGION_OFFSET_Y_2		10777  /**/
#define ERR_UPER_ENCODE_POLARREGION_SIZE_X_2		10788  /**/
#define ERR_UPER_ENCODE_POLARREGION_SIZE_Y_2		10799  /**/
#define PolarRegion_REQUIRED_BYTES_FOR_ENCODING       52 
#define PolarRegion_REQUIRED_BITS_FOR_ENCODING        416

flag PolarRegion_Encode(const PolarRegion* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_POLARREGION		10805  /**/
#define ERR_UPER_DECODE_POLARREGION_OFFSET_X_2		10767  /**/
#define ERR_UPER_DECODE_POLARREGION_OFFSET_Y_2		10778  /**/
#define ERR_UPER_DECODE_POLARREGION_SIZE_X_2		10789  /**/
#define ERR_UPER_DECODE_POLARREGION_SIZE_Y_2		10800  /**/
flag PolarRegion_Decode(PolarRegion* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

#endif
