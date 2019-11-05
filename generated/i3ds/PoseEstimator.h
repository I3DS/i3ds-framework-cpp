#ifndef GENERATED_ASN1SCC_PoseEstimator_H
#define GENERATED_ASN1SCC_PoseEstimator_H
/*
Code automatically generated by asn1scc tool
*/
#include "base.h"
#include "SampleAttribute.h"
#include "asn1crt.h"

#ifdef  __cplusplus
extern "C" {
#endif


/*-- PoseEstimatorMeasurement --------------------------------------------*/
typedef struct {
    SampleAttributes attributes;
    Base_Pose estimated_pose;

} PoseEstimatorMeasurement;

void PoseEstimatorMeasurement_Initialize(PoseEstimatorMeasurement* pVal);

#define ERR_POSEESTIMATORMEASUREMENT		10490  /**/
#define ERR_POSEESTIMATORMEASUREMENT_ATTRIBUTES		10399  /**/
#define ERR_POSEESTIMATORMEASUREMENT_ATTRIBUTES_TIMESTAMP		10289  /**/
#define ERR_POSEESTIMATORMEASUREMENT_ATTRIBUTES_VALIDITY		10304  /**/
#define ERR_POSEESTIMATORMEASUREMENT_ATTRIBUTES_ATTRIBUTES		10392  /**/
#define ERR_POSEESTIMATORMEASUREMENT_ATTRIBUTES_ATTRIBUTES_ELM		10381  /**/
#define ERR_POSEESTIMATORMEASUREMENT_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_KEY		10315  /**/
#define ERR_POSEESTIMATORMEASUREMENT_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE		10370  /**/
#define ERR_POSEESTIMATORMEASUREMENT_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_BOOLEAN_VALUE		10326  /**/
#define ERR_POSEESTIMATORMEASUREMENT_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_DISCRETE_VALUE		10337  /**/
#define ERR_POSEESTIMATORMEASUREMENT_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_REAL_VALUE		10348  /**/
#define ERR_POSEESTIMATORMEASUREMENT_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_STRING_VALUE		10359  /**/
#define ERR_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE		10479  /**/
#define ERR_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE_POSITION		10428  /**/
#define ERR_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE_POSITION_DATA		10421  /**/
#define ERR_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE_POSITION_DATA_ELM		10410  /**/
#define ERR_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE_ORIENTATION		10468  /**/
#define ERR_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE_ORIENTATION_IM		10450  /**/
#define ERR_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE_ORIENTATION_IM_ELM		10439  /**/
#define ERR_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE_ORIENTATION_RE		10457  /**/
flag PoseEstimatorMeasurement_IsConstraintValid(const PoseEstimatorMeasurement* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_POSEESTIMATORMEASUREMENT		10491  /**/
#define ERR_UPER_ENCODE_POSEESTIMATORMEASUREMENT_ATTRIBUTES_2		10406  /**/
#define ERR_UPER_ENCODE_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE_2		10486  /**/
#define PoseEstimatorMeasurement_REQUIRED_BYTES_FOR_ENCODING       158 
#define PoseEstimatorMeasurement_REQUIRED_BITS_FOR_ENCODING        1257

flag PoseEstimatorMeasurement_Encode(const PoseEstimatorMeasurement* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_POSEESTIMATORMEASUREMENT		10492  /**/
#define ERR_UPER_DECODE_POSEESTIMATORMEASUREMENT_ATTRIBUTES_2		10407  /**/
#define ERR_UPER_DECODE_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE_2		10487  /**/
flag PoseEstimatorMeasurement_Decode(PoseEstimatorMeasurement* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

#endif