#ifndef GENERATED_ASN1SCC_Flash_H
#define GENERATED_ASN1SCC_Flash_H
/*
Code automatically generated by asn1scc tool
*/
#include "Camera.h"
#include "asn1crt.h"

#ifdef  __cplusplus
extern "C" {
#endif


/*-- FlashSetup --------------------------------------------*/
typedef struct {
    T_UInt32 duration;
    T_UInt8 strength;

} FlashSetup;

void FlashSetup_Initialize(FlashSetup* pVal);

#define ERR_FLASHSETUP		3601  /**/
#define ERR_FLASHSETUP_DURATION		3571  /**/
#define ERR_FLASHSETUP_STRENGTH		3586  /**/
flag FlashSetup_IsConstraintValid(const FlashSetup* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_FLASHSETUP		3602  /**/
#define ERR_UPER_ENCODE_FLASHSETUP_DURATION_2_2		3582  /**/
#define ERR_UPER_ENCODE_FLASHSETUP_STRENGTH_2_2		3597  /**/
#define FlashSetup_REQUIRED_BYTES_FOR_ENCODING       5 
#define FlashSetup_REQUIRED_BITS_FOR_ENCODING        40

flag FlashSetup_Encode(const FlashSetup* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_FLASHSETUP		3603  /**/
#define ERR_UPER_DECODE_FLASHSETUP_DURATION_2_2		3583  /**/
#define ERR_UPER_DECODE_FLASHSETUP_STRENGTH_2_2		3598  /**/
flag FlashSetup_Decode(FlashSetup* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

#endif
