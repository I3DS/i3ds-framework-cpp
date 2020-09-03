#ifndef i3ds_asn1_GENERATED_ASN1SCC_Analog_H
#define i3ds_asn1_GENERATED_ASN1SCC_Analog_H
/*
Code automatically generated by asn1scc tool
*/
#include <i3ds_asn1/asn1crt.hpp>
#include <i3ds_asn1/asn1crt_encoding.hpp>

#include <i3ds_asn1/Sensor.hpp>
#include <i3ds_asn1/SampleAttribute.hpp>
#include <i3ds_asn1/taste-types.hpp>

namespace i3ds_asn1 {


typedef T_UInt8 SeriesCount;


void SeriesCount_Initialize(SeriesCount* pVal);

#define i3ds_asn1_ERR_SERIESCOUNT_2		8  /**/
flag SeriesCount_IsConstraintValid(const SeriesCount* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_SERIESCOUNT_2		9  /**/
#define i3ds_asn1_SeriesCount_REQUIRED_BYTES_FOR_ENCODING       1 
#define i3ds_asn1_SeriesCount_REQUIRED_BITS_FOR_ENCODING        8

flag SeriesCount_Encode(const SeriesCount* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_SERIESCOUNT_2		10  /**/
flag SeriesCount_Decode(SeriesCount* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- AnalogSeriesDescriptor --------------------------------------------*/
typedef struct {
    SampleAttributes attributes;
    T_UInt8 series_count;
    T_UInt32 batch_size;

} AnalogSeriesDescriptor;

void AnalogSeriesDescriptor_Initialize(AnalogSeriesDescriptor* pVal);

#define i3ds_asn1_ERR_ANALOGSERIESDESCRIPTOR		179  /**/
#define i3ds_asn1_i3ds_asn1_ERR_ANALOGSERIESDESCRIPTOR_ATTRIBUTES_2		140  /**/
#define i3ds_asn1_i3ds_asn1_ERR_ANALOGSERIESDESCRIPTOR_SERIES_COUNT_2_2		157  /**/
#define i3ds_asn1_i3ds_asn1_ERR_ANALOGSERIESDESCRIPTOR_BATCH_SIZE_2_2		174  /**/
flag AnalogSeriesDescriptor_IsConstraintValid(const AnalogSeriesDescriptor* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_ANALOGSERIESDESCRIPTOR		180  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_ANALOGSERIESDESCRIPTOR_ATTRIBUTES_2		141  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_ANALOGSERIESDESCRIPTOR_SERIES_COUNT_2_2		158  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_ANALOGSERIESDESCRIPTOR_BATCH_SIZE_2_2		175  /**/
#define i3ds_asn1_AnalogSeriesDescriptor_REQUIRED_BYTES_FOR_ENCODING       71 
#define i3ds_asn1_AnalogSeriesDescriptor_REQUIRED_BITS_FOR_ENCODING        565

flag AnalogSeriesDescriptor_Encode(const AnalogSeriesDescriptor* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_ANALOGSERIESDESCRIPTOR		181  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_ANALOGSERIESDESCRIPTOR_ATTRIBUTES_2		142  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_ANALOGSERIESDESCRIPTOR_SERIES_COUNT_2_2		159  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_ANALOGSERIESDESCRIPTOR_BATCH_SIZE_2_2		176  /**/
flag AnalogSeriesDescriptor_Decode(AnalogSeriesDescriptor* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 



} // namespace i3ds_asn1
#endif
