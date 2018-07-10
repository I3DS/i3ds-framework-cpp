#ifndef GENERATED_ASN1SCC_Temperature_H
#define GENERATED_ASN1SCC_Temperature_H
/*
Code automatically generated by asn1scc tool
*/
#include "taste-extended.h"
#include "taste-types.h"
#include "asn1crt.h"

#ifdef  __cplusplus
extern "C" {
#endif



typedef struct {
    T_Double kelvin;
} Temperature;

#define Temperature_REQUIRED_BYTES_FOR_ENCODING       13 
#define Temperature_REQUIRED_BITS_FOR_ENCODING        104
#define Temperature_REQUIRED_BYTES_FOR_ACN_ENCODING   13 
#define Temperature_REQUIRED_BITS_FOR_ACN_ENCODING    104
#define Temperature_REQUIRED_BYTES_FOR_XER_ENCODING   94

void Temperature_Initialize(Temperature* pVal);
flag Temperature_IsConstraintValid(const Temperature* val, int* pErrCode);


 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

flag Temperature_Encode(const Temperature* val, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);
flag Temperature_Decode(Temperature* pVal, BitStream* pBitStrm, int* pErrCode); 


#ifdef  __cplusplus
}

#endif

#endif