#ifndef GENERATED_ASN1SCC_SampleAttribute_H
#define GENERATED_ASN1SCC_SampleAttribute_H
/*
Code automatically generated by asn1scc tool
*/
#include "Common.h"
#include "taste-extended.h"
#include "taste-types.h"
#include "asn1crt.h"

#ifdef  __cplusplus
extern "C" {
#endif


typedef enum {
    sample_empty = 0,
    sample_valid = 1,
    sample_invalid = 2
} SampleValidity;

// please use the following macros to avoid breaking code.
#define SampleValidity_sample_empty sample_empty
#define SampleValidity_sample_valid sample_valid
#define SampleValidity_sample_invalid sample_invalid

void SampleValidity_Initialize(SampleValidity* pVal);

#define ERR_SAMPLEVALIDITY		10810  /**/
flag SampleValidity_IsConstraintValid(const SampleValidity* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_SAMPLEVALIDITY		10811  /**/
#define SampleValidity_REQUIRED_BYTES_FOR_ENCODING       1 
#define SampleValidity_REQUIRED_BITS_FOR_ENCODING        2

flag SampleValidity_Encode(const SampleValidity* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_SAMPLEVALIDITY		10812  /**/
flag SampleValidity_Decode(SampleValidity* pVal, BitStream* pBitStrm, int* pErrCode);
typedef struct {
    int nCount; 
    
    byte arr[8];
} T_String8;


void T_String8_Initialize(T_String8* pVal);

#define ERR_T_STRING8		10817  /**/
flag T_String8_IsConstraintValid(const T_String8* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_T_STRING8		10818  /**/
#define T_String8_REQUIRED_BYTES_FOR_ENCODING       9 
#define T_String8_REQUIRED_BITS_FOR_ENCODING        68

flag T_String8_Encode(const T_String8* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_T_STRING8		10819  /**/
flag T_String8_Decode(T_String8* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- Attribute_value_t --------------------------------------------*/

typedef enum {
    Attribute_value_t_NONE,
    boolean_value_PRESENT,
    discrete_value_PRESENT,
    real_value_PRESENT,
    string_value_PRESENT 
} Attribute_value_t_selection;


typedef struct {
    Attribute_value_t_selection kind;
    
    union {
        T_Boolean boolean_value;
        T_Int64 discrete_value;
        T_Double real_value;
        T_String8 string_value;
    } u; 
} Attribute_value_t;

void Attribute_value_t_Initialize(Attribute_value_t* pVal);

#define ERR_ATTRIBUTE_VALUE_T		10868  /**/
#define ERR_ATTRIBUTE_VALUE_T_BOOLEAN_VALUE		10824  /**/
#define ERR_ATTRIBUTE_VALUE_T_DISCRETE_VALUE		10835  /**/
#define ERR_ATTRIBUTE_VALUE_T_REAL_VALUE		10846  /**/
#define ERR_ATTRIBUTE_VALUE_T_STRING_VALUE		10857  /**/
flag Attribute_value_t_IsConstraintValid(const Attribute_value_t* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_ATTRIBUTE_VALUE_T		10869  /**/
#define ERR_UPER_ENCODE_ATTRIBUTE_VALUE_T_BOOLEAN_VALUE_2		10831  /**/
#define ERR_UPER_ENCODE_ATTRIBUTE_VALUE_T_DISCRETE_VALUE_2		10842  /**/
#define ERR_UPER_ENCODE_ATTRIBUTE_VALUE_T_REAL_VALUE_2		10853  /**/
#define ERR_UPER_ENCODE_ATTRIBUTE_VALUE_T_STRING_VALUE_2		10864  /**/
#define Attribute_value_t_REQUIRED_BYTES_FOR_ENCODING       14 
#define Attribute_value_t_REQUIRED_BITS_FOR_ENCODING        106

flag Attribute_value_t_Encode(const Attribute_value_t* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_ATTRIBUTE_VALUE_T		10870  /**/
#define ERR_UPER_DECODE_ATTRIBUTE_VALUE_T_BOOLEAN_VALUE_2		10832  /**/
#define ERR_UPER_DECODE_ATTRIBUTE_VALUE_T_DISCRETE_VALUE_2		10843  /**/
#define ERR_UPER_DECODE_ATTRIBUTE_VALUE_T_REAL_VALUE_2		10854  /**/
#define ERR_UPER_DECODE_ATTRIBUTE_VALUE_T_STRING_VALUE_2		10865  /**/
flag Attribute_value_t_Decode(Attribute_value_t* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- Sample_attribute_t --------------------------------------------*/
typedef struct {
    T_UInt8 attribute_key;
    Attribute_value_t attribute_value;

} Sample_attribute_t;

void Sample_attribute_t_Initialize(Sample_attribute_t* pVal);

#define ERR_SAMPLE_ATTRIBUTE_T		10941  /**/
#define ERR_SAMPLE_ATTRIBUTE_T_ATTRIBUTE_KEY		10875  /**/
#define ERR_SAMPLE_ATTRIBUTE_T_ATTRIBUTE_VALUE		10930  /**/
#define ERR_SAMPLE_ATTRIBUTE_T_ATTRIBUTE_VALUE_BOOLEAN_VALUE		10886  /**/
#define ERR_SAMPLE_ATTRIBUTE_T_ATTRIBUTE_VALUE_DISCRETE_VALUE		10897  /**/
#define ERR_SAMPLE_ATTRIBUTE_T_ATTRIBUTE_VALUE_REAL_VALUE		10908  /**/
#define ERR_SAMPLE_ATTRIBUTE_T_ATTRIBUTE_VALUE_STRING_VALUE		10919  /**/
flag Sample_attribute_t_IsConstraintValid(const Sample_attribute_t* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_SAMPLE_ATTRIBUTE_T		10942  /**/
#define ERR_UPER_ENCODE_SAMPLE_ATTRIBUTE_T_ATTRIBUTE_KEY_2		10882  /**/
#define ERR_UPER_ENCODE_SAMPLE_ATTRIBUTE_T_ATTRIBUTE_VALUE_2		10937  /**/
#define Sample_attribute_t_REQUIRED_BYTES_FOR_ENCODING       15 
#define Sample_attribute_t_REQUIRED_BITS_FOR_ENCODING        114

flag Sample_attribute_t_Encode(const Sample_attribute_t* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_SAMPLE_ATTRIBUTE_T		10943  /**/
#define ERR_UPER_DECODE_SAMPLE_ATTRIBUTE_T_ATTRIBUTE_KEY_2		10883  /**/
#define ERR_UPER_DECODE_SAMPLE_ATTRIBUTE_T_ATTRIBUTE_VALUE_2		10938  /**/
flag Sample_attribute_t_Decode(Sample_attribute_t* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- SampleAttributes --------------------------------------------*/


typedef struct {
    int nCount; 
    
    Sample_attribute_t arr[4];
} SampleAttributes_attributes;
typedef struct {
    T_Int64 timestamp;
    SampleValidity validity;
    SampleAttributes_attributes attributes;

} SampleAttributes;

void SampleAttributes_attributes_Initialize(SampleAttributes_attributes* pVal);
void SampleAttributes_Initialize(SampleAttributes* pVal);

#define ERR_SAMPLEATTRIBUTES		11058  /**/
#define ERR_SAMPLEATTRIBUTES_TIMESTAMP		10948  /**/
#define ERR_SAMPLEATTRIBUTES_VALIDITY		10963  /**/
#define ERR_SAMPLEATTRIBUTES_ATTRIBUTES		11051  /**/
#define ERR_SAMPLEATTRIBUTES_ATTRIBUTES_ELM		11040  /**/
#define ERR_SAMPLEATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_KEY		10974  /**/
#define ERR_SAMPLEATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE		11029  /**/
#define ERR_SAMPLEATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_BOOLEAN_VALUE		10985  /**/
#define ERR_SAMPLEATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_DISCRETE_VALUE		10996  /**/
#define ERR_SAMPLEATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_REAL_VALUE		11007  /**/
#define ERR_SAMPLEATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_STRING_VALUE		11018  /**/
flag SampleAttributes_IsConstraintValid(const SampleAttributes* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_SAMPLEATTRIBUTES		11059  /**/
#define ERR_UPER_ENCODE_SAMPLEATTRIBUTES_TIMESTAMP_2_2		10959  /**/
#define ERR_UPER_ENCODE_SAMPLEATTRIBUTES_VALIDITY_2		10970  /**/
#define ERR_UPER_ENCODE_SAMPLEATTRIBUTES_ATTRIBUTES		11052  /**/
#define ERR_UPER_ENCODE_SAMPLEATTRIBUTES_ATTRIBUTES_ELM_2		11047  /**/
#define SampleAttributes_REQUIRED_BYTES_FOR_ENCODING       66 
#define SampleAttributes_REQUIRED_BITS_FOR_ENCODING        525

flag SampleAttributes_Encode(const SampleAttributes* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_SAMPLEATTRIBUTES		11060  /**/
#define ERR_UPER_DECODE_SAMPLEATTRIBUTES_TIMESTAMP_2_2		10960  /**/
#define ERR_UPER_DECODE_SAMPLEATTRIBUTES_VALIDITY_2		10971  /**/
#define ERR_UPER_DECODE_SAMPLEATTRIBUTES_ATTRIBUTES		11053  /**/
#define ERR_UPER_DECODE_SAMPLEATTRIBUTES_ATTRIBUTES_ELM_2		11048  /**/
flag SampleAttributes_Decode(SampleAttributes* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

#endif
