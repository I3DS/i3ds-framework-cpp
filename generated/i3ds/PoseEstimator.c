/*
Code automatically generated by asn1scc tool
*/
#include <limits.h>
#include <string.h>
#include <math.h>
#include "PoseEstimator.h"



void PoseEstimatorMeasurement_Initialize(PoseEstimatorMeasurement* pVal)
{


	/*set attributes */
	SampleAttributes_Initialize((&(pVal->attributes)));
	/*set estimated_pose */
	Base_Pose_Initialize((&(pVal->estimated_pose)));
}

flag PoseEstimatorMeasurement_IsConstraintValid(const PoseEstimatorMeasurement* pVal, int* pErrCode)
{
    flag ret = TRUE;
    int i1;
	
    ret = (((((pVal->attributes.validity == sample_empty)) || ((pVal->attributes.validity == sample_valid)))) || ((pVal->attributes.validity == sample_invalid)));
    *pErrCode = ret ? 0 :  ERR_POSEESTIMATORMEASUREMENT_ATTRIBUTES_VALIDITY; 
    if (ret) {
        ret = (pVal->attributes.attributes.nCount <= 4);
        *pErrCode = ret ? 0 :  ERR_POSEESTIMATORMEASUREMENT_ATTRIBUTES_ATTRIBUTES; 
        if (ret) {
            for(i1 = 0; ret && i1 < pVal->attributes.attributes.nCount; i1++) 
            {
            	ret = (pVal->attributes.attributes.arr[i1].attribute_key <= 255UL);
            	*pErrCode = ret ? 0 :  ERR_POSEESTIMATORMEASUREMENT_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_KEY; 
            	if (ret) {
            	    if (pVal->attributes.attributes.arr[i1].attribute_value.kind == real_value_PRESENT) {
            	    	ret = ((-1.79769313486231570000E+308 <= pVal->attributes.attributes.arr[i1].attribute_value.u.real_value) && (pVal->attributes.attributes.arr[i1].attribute_value.u.real_value <= 1.79769313486231570000E+308));
            	    	*pErrCode = ret ? 0 :  ERR_POSEESTIMATORMEASUREMENT_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_REAL_VALUE; 
            	    }
            	    if (ret) {
            	        if (pVal->attributes.attributes.arr[i1].attribute_value.kind == string_value_PRESENT) {
            	        	ret = (pVal->attributes.attributes.arr[i1].attribute_value.u.string_value.nCount <= 8);
            	        	*pErrCode = ret ? 0 :  ERR_POSEESTIMATORMEASUREMENT_ATTRIBUTES_ATTRIBUTES_ELM_ATTRIBUTE_VALUE_STRING_VALUE; 
            	        }
            	    }
            	}
            }
        }
    }
    if (ret) {
        ret = ((1 <= pVal->estimated_pose.position.data.nCount) && (pVal->estimated_pose.position.data.nCount <= 3));
        *pErrCode = ret ? 0 :  ERR_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE_POSITION_DATA; 
        if (ret) {
            for(i1 = 0; ret && i1 < pVal->estimated_pose.position.data.nCount; i1++) 
            {
            	ret = ((-1.79769313486231570000E+308 <= pVal->estimated_pose.position.data.arr[i1]) && (pVal->estimated_pose.position.data.arr[i1] <= 1.79769313486231570000E+308));
            	*pErrCode = ret ? 0 :  ERR_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE_POSITION_DATA_ELM; 
            }
        }
        if (ret) {
            ret = ((1 <= pVal->estimated_pose.orientation.im.nCount) && (pVal->estimated_pose.orientation.im.nCount <= 3));
            *pErrCode = ret ? 0 :  ERR_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE_ORIENTATION_IM; 
            if (ret) {
                for(i1 = 0; ret && i1 < pVal->estimated_pose.orientation.im.nCount; i1++) 
                {
                	ret = ((-1.79769313486231570000E+308 <= pVal->estimated_pose.orientation.im.arr[i1]) && (pVal->estimated_pose.orientation.im.arr[i1] <= 1.79769313486231570000E+308));
                	*pErrCode = ret ? 0 :  ERR_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE_ORIENTATION_IM_ELM; 
                }
            }
            if (ret) {
                ret = ((-1.79769313486231570000E+308 <= pVal->estimated_pose.orientation.re) && (pVal->estimated_pose.orientation.re <= 1.79769313486231570000E+308));
                *pErrCode = ret ? 0 :  ERR_POSEESTIMATORMEASUREMENT_ESTIMATED_POSE_ORIENTATION_RE; 
            }
        }
    }

	return ret;
}

flag PoseEstimatorMeasurement_Encode(const PoseEstimatorMeasurement* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	ret = bCheckConstraints ? PoseEstimatorMeasurement_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode attributes */
	    ret = SampleAttributes_Encode((&(pVal->attributes)), pBitStrm, pErrCode, FALSE);
	    if (ret) {
	        /*Encode estimated_pose */
	        ret = Base_Pose_Encode((&(pVal->estimated_pose)), pBitStrm, pErrCode, FALSE);
	    }
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag PoseEstimatorMeasurement_Decode(PoseEstimatorMeasurement* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	/*Decode attributes */
	ret = SampleAttributes_Decode((&(pVal->attributes)), pBitStrm, pErrCode);
	if (ret) {
	    /*Decode estimated_pose */
	    ret = Base_Pose_Decode((&(pVal->estimated_pose)), pBitStrm, pErrCode);
	}

	return ret  && PoseEstimatorMeasurement_IsConstraintValid(pVal, pErrCode);
}



void PoseEstimatorImagingMode_Initialize(PoseEstimatorImagingMode* pVal)
{


	/*set imaging_mode */
	T_Boolean_Initialize((&(pVal->imaging_mode)));
}

flag PoseEstimatorImagingMode_IsConstraintValid(const PoseEstimatorImagingMode* pVal, int* pErrCode)
{
    flag ret = TRUE;
	
    ret = TRUE;
    *pErrCode = 0;

	return ret;
}

flag PoseEstimatorImagingMode_Encode(const PoseEstimatorImagingMode* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	ret = bCheckConstraints ? PoseEstimatorImagingMode_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode imaging_mode */
	    ret = T_Boolean_Encode((&(pVal->imaging_mode)), pBitStrm, pErrCode, FALSE);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag PoseEstimatorImagingMode_Decode(PoseEstimatorImagingMode* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	/*Decode imaging_mode */
	ret = T_Boolean_Decode((&(pVal->imaging_mode)), pBitStrm, pErrCode);

	return ret  && PoseEstimatorImagingMode_IsConstraintValid(pVal, pErrCode);
}



void PoseEstimatorCameraSelect_Initialize(PoseEstimatorCameraSelect* pVal)
{


	/*set camera_select */
	T_UInt8_Initialize((&(pVal->camera_select)));
}

flag PoseEstimatorCameraSelect_IsConstraintValid(const PoseEstimatorCameraSelect* pVal, int* pErrCode)
{
    flag ret = TRUE;
	
    ret = (pVal->camera_select <= 255UL);
    *pErrCode = ret ? 0 :  ERR_POSEESTIMATORCAMERASELECT_CAMERA_SELECT; 

	return ret;
}

flag PoseEstimatorCameraSelect_Encode(const PoseEstimatorCameraSelect* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	ret = bCheckConstraints ? PoseEstimatorCameraSelect_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode camera_select */
	    ret = T_UInt8_Encode((&(pVal->camera_select)), pBitStrm, pErrCode, FALSE);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag PoseEstimatorCameraSelect_Decode(PoseEstimatorCameraSelect* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	/*Decode camera_select */
	ret = T_UInt8_Decode((&(pVal->camera_select)), pBitStrm, pErrCode);

	return ret  && PoseEstimatorCameraSelect_IsConstraintValid(pVal, pErrCode);
}



void PoseEstimatorConfiguration_Initialize(PoseEstimatorConfiguration* pVal)
{


	/*set imaging_mode */
	T_Boolean_Initialize((&(pVal->imaging_mode)));
	/*set camera_select */
	T_UInt8_Initialize((&(pVal->camera_select)));
}

flag PoseEstimatorConfiguration_IsConstraintValid(const PoseEstimatorConfiguration* pVal, int* pErrCode)
{
    flag ret = TRUE;
	
    ret = (pVal->camera_select <= 255UL);
    *pErrCode = ret ? 0 :  ERR_POSEESTIMATORCONFIGURATION_CAMERA_SELECT; 

	return ret;
}

flag PoseEstimatorConfiguration_Encode(const PoseEstimatorConfiguration* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	ret = bCheckConstraints ? PoseEstimatorConfiguration_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode imaging_mode */
	    ret = T_Boolean_Encode((&(pVal->imaging_mode)), pBitStrm, pErrCode, FALSE);
	    if (ret) {
	        /*Encode camera_select */
	        ret = T_UInt8_Encode((&(pVal->camera_select)), pBitStrm, pErrCode, FALSE);
	    }
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag PoseEstimatorConfiguration_Decode(PoseEstimatorConfiguration* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	/*Decode imaging_mode */
	ret = T_Boolean_Decode((&(pVal->imaging_mode)), pBitStrm, pErrCode);
	if (ret) {
	    /*Decode camera_select */
	    ret = T_UInt8_Decode((&(pVal->camera_select)), pBitStrm, pErrCode);
	}

	return ret  && PoseEstimatorConfiguration_IsConstraintValid(pVal, pErrCode);
}

