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


/*-- PoseEstimatorMeasurement --------------------------------------------*/
typedef struct {
    SampleAttributes attributes;
    Base_Pose estimated_pose;

} PoseEstimatorMeasurement;

void PoseEstimatorMeasurement_Initialize(PoseEstimatorMeasurement* pVal);

#define i3ds_asn1_ERR_POSEESTIMATORMEASUREMENT		11486  /**/
#define i3ds_asn1_i3ds_asn1_ERR_POSEESTIMATORMEASUREMENT_ATTRIBUTES_2		11395  /**/
#define i3ds_asn1_i3ds_asn1_ERR_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE_2		11481  /**/
flag PoseEstimatorMeasurement_IsConstraintValid(const PoseEstimatorMeasurement* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_POSEESTIMATORMEASUREMENT		11487  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_POSEESTIMATORMEASUREMENT_ATTRIBUTES_2		11396  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE_2		11482  /**/
#define i3ds_asn1_PoseEstimatorMeasurement_REQUIRED_BYTES_FOR_ENCODING       158 
#define i3ds_asn1_PoseEstimatorMeasurement_REQUIRED_BITS_FOR_ENCODING        1257

flag PoseEstimatorMeasurement_Encode(const PoseEstimatorMeasurement* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_POSEESTIMATORMEASUREMENT		11488  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_POSEESTIMATORMEASUREMENT_ATTRIBUTES_2		11397  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE_2		11483  /**/
flag PoseEstimatorMeasurement_Decode(PoseEstimatorMeasurement* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- PoseEstimatorImagingMode --------------------------------------------*/
typedef struct {
    T_Boolean imaging_mode;

} PoseEstimatorImagingMode;

void PoseEstimatorImagingMode_Initialize(PoseEstimatorImagingMode* pVal);

#define i3ds_asn1_ERR_POSEESTIMATORIMAGINGMODE		11211  /**/
#define i3ds_asn1_i3ds_asn1_ERR_POSEESTIMATORIMAGINGMODE_IMAGING_MODE_2		11206  /**/
flag PoseEstimatorImagingMode_IsConstraintValid(const PoseEstimatorImagingMode* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_POSEESTIMATORIMAGINGMODE		11212  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_POSEESTIMATORIMAGINGMODE_IMAGING_MODE_2		11207  /**/
#define i3ds_asn1_PoseEstimatorImagingMode_REQUIRED_BYTES_FOR_ENCODING       1 
#define i3ds_asn1_PoseEstimatorImagingMode_REQUIRED_BITS_FOR_ENCODING        1

flag PoseEstimatorImagingMode_Encode(const PoseEstimatorImagingMode* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_POSEESTIMATORIMAGINGMODE		11213  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_POSEESTIMATORIMAGINGMODE_IMAGING_MODE_2		11208  /**/
flag PoseEstimatorImagingMode_Decode(PoseEstimatorImagingMode* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- PoseEstimatorCameraSelect --------------------------------------------*/
typedef struct {
    T_UInt8 camera_select;

} PoseEstimatorCameraSelect;

void PoseEstimatorCameraSelect_Initialize(PoseEstimatorCameraSelect* pVal);

#define i3ds_asn1_ERR_POSEESTIMATORCAMERASELECT		11230  /**/
#define i3ds_asn1_i3ds_asn1_ERR_POSEESTIMATORCAMERASELECT_CAMERA_SELECT_2		11225  /**/
flag PoseEstimatorCameraSelect_IsConstraintValid(const PoseEstimatorCameraSelect* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_POSEESTIMATORCAMERASELECT		11231  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_POSEESTIMATORCAMERASELECT_CAMERA_SELECT_2		11226  /**/
#define i3ds_asn1_PoseEstimatorCameraSelect_REQUIRED_BYTES_FOR_ENCODING       1 
#define i3ds_asn1_PoseEstimatorCameraSelect_REQUIRED_BITS_FOR_ENCODING        8

flag PoseEstimatorCameraSelect_Encode(const PoseEstimatorCameraSelect* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_POSEESTIMATORCAMERASELECT		11232  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_POSEESTIMATORCAMERASELECT_CAMERA_SELECT_2		11227  /**/
flag PoseEstimatorCameraSelect_Decode(PoseEstimatorCameraSelect* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- PoseEstimatorConfiguration --------------------------------------------*/
typedef struct {
    T_Boolean imaging_mode;
    T_UInt8 camera_select;

} PoseEstimatorConfiguration;

void PoseEstimatorConfiguration_Initialize(PoseEstimatorConfiguration* pVal);

#define i3ds_asn1_ERR_POSEESTIMATORCONFIGURATION		11261  /**/
#define i3ds_asn1_i3ds_asn1_ERR_POSEESTIMATORCONFIGURATION_IMAGING_MODE_2		11244  /**/
#define i3ds_asn1_i3ds_asn1_ERR_POSEESTIMATORCONFIGURATION_CAMERA_SELECT_2		11256  /**/
flag PoseEstimatorConfiguration_IsConstraintValid(const PoseEstimatorConfiguration* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_POSEESTIMATORCONFIGURATION		11262  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_POSEESTIMATORCONFIGURATION_IMAGING_MODE_2		11245  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_POSEESTIMATORCONFIGURATION_CAMERA_SELECT_2		11257  /**/
#define i3ds_asn1_PoseEstimatorConfiguration_REQUIRED_BYTES_FOR_ENCODING       2 
#define i3ds_asn1_PoseEstimatorConfiguration_REQUIRED_BITS_FOR_ENCODING        9

flag PoseEstimatorConfiguration_Encode(const PoseEstimatorConfiguration* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_POSEESTIMATORCONFIGURATION		11263  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_POSEESTIMATORCONFIGURATION_IMAGING_MODE_2		11246  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_POSEESTIMATORCONFIGURATION_CAMERA_SELECT_2		11258  /**/
flag PoseEstimatorConfiguration_Decode(PoseEstimatorConfiguration* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 



} // namespace i3ds_asn1
#endif
