#ifndef i3ds_asn1_GENERATED_ASN1SCC_Common_H
#define i3ds_asn1_GENERATED_ASN1SCC_Common_H
/*
Code automatically generated by asn1scc tool
*/
#include <i3ds_asn1/asn1crt.hpp>
#include <i3ds_asn1/asn1crt_encoding.hpp>

#include <i3ds_asn1/taste-extended.hpp>

namespace i3ds_asn1 {


typedef T_Int64 Timepoint;


void Timepoint_Initialize(Timepoint* pVal);

#define i3ds_asn1_ERR_TIMEPOINT_2		743  /**/
flag Timepoint_IsConstraintValid(const Timepoint* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_TIMEPOINT_2		744  /**/
#define i3ds_asn1_Timepoint_REQUIRED_BYTES_FOR_ENCODING       8 
#define i3ds_asn1_Timepoint_REQUIRED_BITS_FOR_ENCODING        64

flag Timepoint_Encode(const Timepoint* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_TIMEPOINT_2		745  /**/
flag Timepoint_Decode(Timepoint* pVal, BitStream* pBitStrm, int* pErrCode);
typedef asn1SccUint NodeID;


void NodeID_Initialize(NodeID* pVal);

#define i3ds_asn1_ERR_NODEID		722  /**/
flag NodeID_IsConstraintValid(const NodeID* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_NODEID		723  /**/
#define i3ds_asn1_NodeID_REQUIRED_BYTES_FOR_ENCODING       3 
#define i3ds_asn1_NodeID_REQUIRED_BITS_FOR_ENCODING        24

flag NodeID_Encode(const NodeID* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_NODEID		724  /**/
flag NodeID_Decode(NodeID* pVal, BitStream* pBitStrm, int* pErrCode);
typedef asn1SccUint EndpointID;


void EndpointID_Initialize(EndpointID* pVal);

#define i3ds_asn1_ERR_ENDPOINTID		729  /**/
flag EndpointID_IsConstraintValid(const EndpointID* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_ENDPOINTID		730  /**/
#define i3ds_asn1_EndpointID_REQUIRED_BYTES_FOR_ENCODING       1 
#define i3ds_asn1_EndpointID_REQUIRED_BITS_FOR_ENCODING        8

flag EndpointID_Encode(const EndpointID* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_ENDPOINTID		731  /**/
flag EndpointID_Decode(EndpointID* pVal, BitStream* pBitStrm, int* pErrCode);
typedef enum {
    ResultCode_success = 0,
    ResultCode_error_node_id = 1,
    ResultCode_error_endpoint_id = 2,
    ResultCode_error_unsupported = 3,
    ResultCode_error_state = 4,
    ResultCode_error_value = 5,
    ResultCode_error_other = 6
} ResultCode;

// please use the following macros to avoid breaking code.
#define nsResultCode_success i3ds_asn1::ResultCode_success
#define nsResultCode_error_node_id i3ds_asn1::ResultCode_error_node_id
#define nsResultCode_error_endpoint_id i3ds_asn1::ResultCode_error_endpoint_id
#define nsResultCode_error_unsupported i3ds_asn1::ResultCode_error_unsupported
#define nsResultCode_error_state i3ds_asn1::ResultCode_error_state
#define nsResultCode_error_value i3ds_asn1::ResultCode_error_value
#define nsResultCode_error_other i3ds_asn1::ResultCode_error_other

void ResultCode_Initialize(ResultCode* pVal);

#define i3ds_asn1_ERR_RESULTCODE		750  /**/
flag ResultCode_IsConstraintValid(const ResultCode* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_RESULTCODE		751  /**/
#define i3ds_asn1_ResultCode_REQUIRED_BYTES_FOR_ENCODING       1 
#define i3ds_asn1_ResultCode_REQUIRED_BITS_FOR_ENCODING        3

flag ResultCode_Encode(const ResultCode* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_RESULTCODE		752  /**/
flag ResultCode_Decode(ResultCode* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- CommandResponse --------------------------------------------*/
typedef struct {
    ResultCode result;
    T_String message;

} CommandResponse;

void CommandResponse_Initialize(CommandResponse* pVal);

#define i3ds_asn1_ERR_COMMANDRESPONSE		785  /**/
#define i3ds_asn1_i3ds_asn1_ERR_COMMANDRESPONSE_RESULT_2		764  /**/
#define i3ds_asn1_i3ds_asn1_ERR_COMMANDRESPONSE_MESSAGE_2		778  /**/
flag CommandResponse_IsConstraintValid(const CommandResponse* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_COMMANDRESPONSE		786  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_COMMANDRESPONSE_RESULT_2		765  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_COMMANDRESPONSE_MESSAGE_2		779  /**/
#define i3ds_asn1_CommandResponse_REQUIRED_BYTES_FOR_ENCODING       42 
#define i3ds_asn1_CommandResponse_REQUIRED_BITS_FOR_ENCODING        329

flag CommandResponse_Encode(const CommandResponse* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_COMMANDRESPONSE		787  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_COMMANDRESPONSE_RESULT_2		766  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_COMMANDRESPONSE_MESSAGE_2		780  /**/
flag CommandResponse_Decode(CommandResponse* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 



} // namespace i3ds_asn1
#endif
