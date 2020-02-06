#ifndef i3ds_asn1_GENERATED_ASN1SCC_PoseEstimator_H
#define i3ds_asn1_GENERATED_ASN1SCC_PoseEstimator_H
/*
Code automatically generated by asn1scc tool
*/
#include <i3ds_asn1/asn1crt.hpp>
#include <i3ds_asn1/asn1crt_encoding.hpp>

#include <i3ds_asn1/base.hpp>
#include <i3ds_asn1/SampleAttribute.hpp>
#include <i3ds_asn1/taste-types.hpp>
namespace i3ds_asn1 {

#ifdef  __cplusplus
extern "C" {
#endif


/*-- PoseEstimatorMeasurement --------------------------------------------*/
typedef struct {
    SampleAttributes attributes;
    Base_Pose estimated_pose;

} PoseEstimatorMeasurement;

void PoseEstimatorMeasurement_Initialize(PoseEstimatorMeasurement* pVal);

#define i3ds_asn1_ERR_POSEESTIMATORMEASUREMENT		11335  /**/
#define i3ds_asn1_i3ds_asn1_ERR_POSEESTIMATORMEASUREMENT_ATTRIBUTES_2		11244  /**/
#define i3ds_asn1_i3ds_asn1_ERR_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE_2		11330  /**/
flag PoseEstimatorMeasurement_IsConstraintValid(const PoseEstimatorMeasurement* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_POSEESTIMATORMEASUREMENT		11336  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_POSEESTIMATORMEASUREMENT_ATTRIBUTES_2		11245  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE_2		11331  /**/
#define i3ds_asn1_PoseEstimatorMeasurement_REQUIRED_BYTES_FOR_ENCODING       158 
#define i3ds_asn1_PoseEstimatorMeasurement_REQUIRED_BITS_FOR_ENCODING        1257

flag PoseEstimatorMeasurement_Encode(const PoseEstimatorMeasurement* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_POSEESTIMATORMEASUREMENT		11337  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_POSEESTIMATORMEASUREMENT_ATTRIBUTES_2		11246  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE_2		11332  /**/
flag PoseEstimatorMeasurement_Decode(PoseEstimatorMeasurement* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- PoseEstimatorImagingMode --------------------------------------------*/
typedef struct {
    T_Boolean imaging_mode;

} PoseEstimatorImagingMode;

void PoseEstimatorImagingMode_Initialize(PoseEstimatorImagingMode* pVal);

#define i3ds_asn1_ERR_POSEESTIMATORIMAGINGMODE		11060  /**/
#define i3ds_asn1_i3ds_asn1_ERR_POSEESTIMATORIMAGINGMODE_IMAGING_MODE_2		11055  /**/
flag PoseEstimatorImagingMode_IsConstraintValid(const PoseEstimatorImagingMode* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_POSEESTIMATORIMAGINGMODE		11061  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_POSEESTIMATORIMAGINGMODE_IMAGING_MODE_2		11056  /**/
#define i3ds_asn1_PoseEstimatorImagingMode_REQUIRED_BYTES_FOR_ENCODING       1 
#define i3ds_asn1_PoseEstimatorImagingMode_REQUIRED_BITS_FOR_ENCODING        1

flag PoseEstimatorImagingMode_Encode(const PoseEstimatorImagingMode* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_POSEESTIMATORIMAGINGMODE		11062  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_POSEESTIMATORIMAGINGMODE_IMAGING_MODE_2		11057  /**/
flag PoseEstimatorImagingMode_Decode(PoseEstimatorImagingMode* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- PoseEstimatorCameraSelect --------------------------------------------*/
typedef struct {
    T_UInt8 camera_select;

} PoseEstimatorCameraSelect;

void PoseEstimatorCameraSelect_Initialize(PoseEstimatorCameraSelect* pVal);

#define i3ds_asn1_ERR_POSEESTIMATORCAMERASELECT		11079  /**/
#define i3ds_asn1_i3ds_asn1_ERR_POSEESTIMATORCAMERASELECT_CAMERA_SELECT_2		11074  /**/
flag PoseEstimatorCameraSelect_IsConstraintValid(const PoseEstimatorCameraSelect* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_POSEESTIMATORCAMERASELECT		11080  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_POSEESTIMATORCAMERASELECT_CAMERA_SELECT_2		11075  /**/
#define i3ds_asn1_PoseEstimatorCameraSelect_REQUIRED_BYTES_FOR_ENCODING       1 
#define i3ds_asn1_PoseEstimatorCameraSelect_REQUIRED_BITS_FOR_ENCODING        8

flag PoseEstimatorCameraSelect_Encode(const PoseEstimatorCameraSelect* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_POSEESTIMATORCAMERASELECT		11081  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_POSEESTIMATORCAMERASELECT_CAMERA_SELECT_2		11076  /**/
flag PoseEstimatorCameraSelect_Decode(PoseEstimatorCameraSelect* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- PoseEstimatorConfiguration --------------------------------------------*/
typedef struct {
    T_Boolean imaging_mode;
    T_UInt8 camera_select;

} PoseEstimatorConfiguration;

void PoseEstimatorConfiguration_Initialize(PoseEstimatorConfiguration* pVal);

#define i3ds_asn1_ERR_POSEESTIMATORCONFIGURATION		11110  /**/
#define i3ds_asn1_i3ds_asn1_ERR_POSEESTIMATORCONFIGURATION_IMAGING_MODE_2		11093  /**/
#define i3ds_asn1_i3ds_asn1_ERR_POSEESTIMATORCONFIGURATION_CAMERA_SELECT_2		11105  /**/
flag PoseEstimatorConfiguration_IsConstraintValid(const PoseEstimatorConfiguration* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_POSEESTIMATORCONFIGURATION		11111  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_POSEESTIMATORCONFIGURATION_IMAGING_MODE_2		11094  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_POSEESTIMATORCONFIGURATION_CAMERA_SELECT_2		11106  /**/
#define i3ds_asn1_PoseEstimatorConfiguration_REQUIRED_BYTES_FOR_ENCODING       2 
#define i3ds_asn1_PoseEstimatorConfiguration_REQUIRED_BITS_FOR_ENCODING        9

flag PoseEstimatorConfiguration_Encode(const PoseEstimatorConfiguration* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_POSEESTIMATORCONFIGURATION		11112  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_POSEESTIMATORCONFIGURATION_IMAGING_MODE_2		11095  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_POSEESTIMATORCONFIGURATION_CAMERA_SELECT_2		11107  /**/
flag PoseEstimatorConfiguration_Decode(PoseEstimatorConfiguration* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

} // namespace i3ds_asn1
#endif
