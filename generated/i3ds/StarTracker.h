#ifndef GENERATED_ASN1SCC_StarTracker_H
#define GENERATED_ASN1SCC_StarTracker_H
/*
Code automatically generated by asn1scc tool
*/
#include "Eigen.h"
#include "SampleAttribute.h"
#include "asn1crt.h"

#ifdef  __cplusplus
extern "C" {
#endif


/*-- StarTrackerMeasurement --------------------------------------------*/
typedef struct {
    SampleAttributes attributes;
    Quaterniond position;

} StarTrackerMeasurement;

void StarTrackerMeasurement_Initialize(StarTrackerMeasurement* pVal);

#define ERR_STARTRACKERMEASUREMENT		3078  /**/
#define ERR_STARTRACKERMEASUREMENT_ATTRIBUTES		3045  /**/
#define ERR_STARTRACKERMEASUREMENT_ATTRIBUTES_TIMESTAMP		2935  /**/
#define ERR_STARTRACKERMEASUREMENT_ATTRIBUTES_VALIDITY		2950  /**/
#define ERR_STARTRACKERMEASUREMENT_ATTRIBUTES_ATTRIBUTES		3038  /**/
#define ERR_STARTRACKERMEASUREMENT_ATTRIBUTES_ATTRIBUTES_ELM		3027  /**/
#define ERR_STARTRACKERMEASUREMENT_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_KEY		2961  /**/
#define ERR_STARTRACKERMEASUREMENT_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE		3016  /**/
#define ERR_STARTRACKERMEASUREMENT_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_BOOLEAN_VALUE		2972  /**/
#define ERR_STARTRACKERMEASUREMENT_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_DISCRETE_VALUE		2983  /**/
#define ERR_STARTRACKERMEASUREMENT_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_REAL_VALUE		2994  /**/
#define ERR_STARTRACKERMEASUREMENT_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_STRING_VALUE		3005  /**/
#define ERR_STARTRACKERMEASUREMENT_POSITION		3067  /**/
#define ERR_STARTRACKERMEASUREMENT_POSITION_ELM		3056  /**/
flag StarTrackerMeasurement_IsConstraintValid(const StarTrackerMeasurement* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_STARTRACKERMEASUREMENT		3079  /**/
#define ERR_UPER_ENCODE_STARTRACKERMEASUREMENT_ATTRIBUTES_2		3052  /**/
#define ERR_UPER_ENCODE_STARTRACKERMEASUREMENT_POSITION_2		3074  /**/
#define StarTrackerMeasurement_REQUIRED_BYTES_FOR_ENCODING       118 
#define StarTrackerMeasurement_REQUIRED_BITS_FOR_ENCODING        943

flag StarTrackerMeasurement_Encode(const StarTrackerMeasurement* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_STARTRACKERMEASUREMENT		3080  /**/
#define ERR_UPER_DECODE_STARTRACKERMEASUREMENT_ATTRIBUTES_2		3053  /**/
#define ERR_UPER_DECODE_STARTRACKERMEASUREMENT_POSITION_2		3075  /**/
flag StarTrackerMeasurement_Decode(StarTrackerMeasurement* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

#endif
