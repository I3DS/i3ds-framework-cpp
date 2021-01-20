#ifndef i3ds_asn1_GENERATED_ASN1SCC_PatternProjector_H
#define i3ds_asn1_GENERATED_ASN1SCC_PatternProjector_H
/*
Code automatically generated by asn1scc tool
*/
#include <i3ds_asn1/asn1crt.hpp>
#include <i3ds_asn1/asn1crt_encoding.hpp>

#include <i3ds_asn1/taste-types.hpp>

namespace i3ds_asn1 {


typedef enum {
    PatternSensorMode_mode_undefined = 0,
    PatternSensorMode_mode_white = 1,
    PatternSensorMode_mode_gc_phase_pattern = 2
} PatternSensorMode;

// please use the following macros to avoid breaking code.
#define nsPatternSensorMode_mode_undefined i3ds_asn1::PatternSensorMode_mode_undefined
#define nsPatternSensorMode_mode_white i3ds_asn1::PatternSensorMode_mode_white
#define nsPatternSensorMode_mode_gc_phase_pattern i3ds_asn1::PatternSensorMode_mode_gc_phase_pattern

void PatternSensorMode_Initialize(PatternSensorMode* pVal);

#define i3ds_asn1_ERR_PATTERNSENSORMODE		3807  /**/
flag PatternSensorMode_IsConstraintValid(const PatternSensorMode* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_PATTERNSENSORMODE		3808  /**/
#define i3ds_asn1_PatternSensorMode_REQUIRED_BYTES_FOR_ENCODING       1 
#define i3ds_asn1_PatternSensorMode_REQUIRED_BITS_FOR_ENCODING        2

flag PatternSensorMode_Encode(const PatternSensorMode* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_PATTERNSENSORMODE		3809  /**/
flag PatternSensorMode_Decode(PatternSensorMode* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- PatternDescriptor --------------------------------------------*/
typedef struct {
    PatternSensorMode mode;
    T_Boolean enable;

} PatternDescriptor;

void PatternDescriptor_Initialize(PatternDescriptor* pVal);

#define i3ds_asn1_ERR_PATTERNDESCRIPTOR		3838  /**/
#define i3ds_asn1_i3ds_asn1_ERR_PATTERNDESCRIPTOR_MODE_2		3821  /**/
#define i3ds_asn1_i3ds_asn1_ERR_PATTERNDESCRIPTOR_ENABLE_2		3833  /**/
flag PatternDescriptor_IsConstraintValid(const PatternDescriptor* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_PATTERNDESCRIPTOR		3839  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_PATTERNDESCRIPTOR_MODE_2		3822  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_PATTERNDESCRIPTOR_ENABLE_2		3834  /**/
#define i3ds_asn1_PatternDescriptor_REQUIRED_BYTES_FOR_ENCODING       1 
#define i3ds_asn1_PatternDescriptor_REQUIRED_BITS_FOR_ENCODING        3

flag PatternDescriptor_Encode(const PatternDescriptor* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_PATTERNDESCRIPTOR		3840  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_PATTERNDESCRIPTOR_MODE_2		3823  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_PATTERNDESCRIPTOR_ENABLE_2		3835  /**/
flag PatternDescriptor_Decode(PatternDescriptor* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 



} // namespace i3ds_asn1
#endif
