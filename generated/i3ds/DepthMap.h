#ifndef GENERATED_ASN1SCC_DepthMap_H
#define GENERATED_ASN1SCC_DepthMap_H
/*
Code automatically generated by asn1scc tool
*/
#include "taste-extended.h"
#include "taste-types.h"
#include "SampleAttribute.h"
#include "Region.h"
#include "asn1crt.h"

#ifdef  __cplusplus
extern "C" {
#endif


typedef enum {
    depth_f = 0
} Depth_format_t;

// please use the following macros to avoid breaking code.
#define Depth_format_t_depth_f depth_f

void Depth_format_t_Initialize(Depth_format_t* pVal);

#define ERR_DEPTH_FORMAT_T		1057  /**/
flag Depth_format_t_IsConstraintValid(const Depth_format_t* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_DEPTH_FORMAT_T		1058  /**/
#define Depth_format_t_REQUIRED_BYTES_FOR_ENCODING       0 
#define Depth_format_t_REQUIRED_BITS_FOR_ENCODING        0

flag Depth_format_t_Encode(const Depth_format_t* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_DEPTH_FORMAT_T		1059  /**/
flag Depth_format_t_Decode(Depth_format_t* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- DepthMapDescriptor --------------------------------------------*/
typedef struct {
    SampleAttributes attributes;
    Depth_format_t depth_format;
    T_UInt8 depth_size;
    T_UInt16 width;
    T_UInt16 height;

} DepthMapDescriptor;

void DepthMapDescriptor_Initialize(DepthMapDescriptor* pVal);

#define ERR_DEPTHMAPDESCRIPTOR		1229  /**/
#define ERR_DEPTHMAPDESCRIPTOR_ATTRIBUTES		1174  /**/
#define ERR_DEPTHMAPDESCRIPTOR_ATTRIBUTES_TIMESTAMP		1064  /**/
#define ERR_DEPTHMAPDESCRIPTOR_ATTRIBUTES_VALIDITY		1079  /**/
#define ERR_DEPTHMAPDESCRIPTOR_ATTRIBUTES_ATTRIBUTES		1167  /**/
#define ERR_DEPTHMAPDESCRIPTOR_ATTRIBUTES_ATTRIBUTES_ELM		1156  /**/
#define ERR_DEPTHMAPDESCRIPTOR_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_KEY		1090  /**/
#define ERR_DEPTHMAPDESCRIPTOR_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE		1145  /**/
#define ERR_DEPTHMAPDESCRIPTOR_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_BOOLEAN_VALUE		1101  /**/
#define ERR_DEPTHMAPDESCRIPTOR_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_DISCRETE_VALUE		1112  /**/
#define ERR_DEPTHMAPDESCRIPTOR_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_REAL_VALUE		1123  /**/
#define ERR_DEPTHMAPDESCRIPTOR_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_STRING_VALUE		1134  /**/
#define ERR_DEPTHMAPDESCRIPTOR_DEPTH_FORMAT		1185  /**/
#define ERR_DEPTHMAPDESCRIPTOR_DEPTH_SIZE		1196  /**/
#define ERR_DEPTHMAPDESCRIPTOR_WIDTH		1207  /**/
#define ERR_DEPTHMAPDESCRIPTOR_HEIGHT		1218  /**/
flag DepthMapDescriptor_IsConstraintValid(const DepthMapDescriptor* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_DEPTHMAPDESCRIPTOR		1230  /**/
#define ERR_UPER_ENCODE_DEPTHMAPDESCRIPTOR_ATTRIBUTES_2		1181  /**/
#define ERR_UPER_ENCODE_DEPTHMAPDESCRIPTOR_DEPTH_FORMAT_2		1192  /**/
#define ERR_UPER_ENCODE_DEPTHMAPDESCRIPTOR_DEPTH_SIZE_2		1203  /**/
#define ERR_UPER_ENCODE_DEPTHMAPDESCRIPTOR_WIDTH_2		1214  /**/
#define ERR_UPER_ENCODE_DEPTHMAPDESCRIPTOR_HEIGHT_2		1225  /**/
#define DepthMapDescriptor_REQUIRED_BYTES_FOR_ENCODING       71 
#define DepthMapDescriptor_REQUIRED_BITS_FOR_ENCODING        565

flag DepthMapDescriptor_Encode(const DepthMapDescriptor* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_DEPTHMAPDESCRIPTOR		1231  /**/
#define ERR_UPER_DECODE_DEPTHMAPDESCRIPTOR_ATTRIBUTES_2		1182  /**/
#define ERR_UPER_DECODE_DEPTHMAPDESCRIPTOR_DEPTH_FORMAT_2		1193  /**/
#define ERR_UPER_DECODE_DEPTHMAPDESCRIPTOR_DEPTH_SIZE_2		1204  /**/
#define ERR_UPER_DECODE_DEPTHMAPDESCRIPTOR_WIDTH_2		1215  /**/
#define ERR_UPER_DECODE_DEPTHMAPDESCRIPTOR_HEIGHT_2		1226  /**/
flag DepthMapDescriptor_Decode(DepthMapDescriptor* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

#endif
