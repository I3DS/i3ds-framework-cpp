#ifndef i3ds_asn1_GENERATED_ASN1SCC_StarTracker_H
#define i3ds_asn1_GENERATED_ASN1SCC_StarTracker_H
/*
Code automatically generated by asn1scc tool
*/
#include <i3ds_asn1/asn1crt.hpp>
#include <i3ds_asn1/asn1crt_encoding.hpp>

#include <i3ds_asn1/base.hpp>
#include <i3ds_asn1/SampleAttribute.hpp>

namespace i3ds_asn1 {


/*-- StarTrackerMeasurement --------------------------------------------*/
typedef struct {
    SampleAttributes attributes;
    Wrappers_Quaterniond position;

} StarTrackerMeasurement;

void StarTrackerMeasurement_Initialize(StarTrackerMeasurement* pVal);

#define i3ds_asn1_ERR_STARTRACKERMEASUREMENT		12060  /**/
#define i3ds_asn1_i3ds_asn1_ERR_STARTRACKERMEASUREMENT_ATTRIBUTES_2		12012  /**/
#define i3ds_asn1_i3ds_asn1_ERR_STARTRACKERMEASUREMENT_POSITION_2		12055  /**/
flag StarTrackerMeasurement_IsConstraintValid(const StarTrackerMeasurement* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_STARTRACKERMEASUREMENT		12061  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_STARTRACKERMEASUREMENT_ATTRIBUTES_2		12013  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_STARTRACKERMEASUREMENT_POSITION_2		12056  /**/
#define i3ds_asn1_StarTrackerMeasurement_REQUIRED_BYTES_FOR_ENCODING       118 
#define i3ds_asn1_StarTrackerMeasurement_REQUIRED_BITS_FOR_ENCODING        943

flag StarTrackerMeasurement_Encode(const StarTrackerMeasurement* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_STARTRACKERMEASUREMENT		12062  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_STARTRACKERMEASUREMENT_ATTRIBUTES_2		12014  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_STARTRACKERMEASUREMENT_POSITION_2		12057  /**/
flag StarTrackerMeasurement_Decode(StarTrackerMeasurement* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 



} // namespace i3ds_asn1
#endif
