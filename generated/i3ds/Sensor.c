/*
Code automatically generated by asn1scc tool
*/
#include <limits.h>
#include <string.h>
#include <math.h>
#include "Sensor.h"

#if !defined(_MSC_VER) || _MSC_VER >= 1800
void SamplePeriod_Initialize(SamplePeriod* pVal)
{
    *pVal = (SamplePeriod) 0;
}
#endif

 
flag SamplePeriod_IsConstraintValid(const SamplePeriod* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = T_UInt32_IsConstraintValid(pVal, pErrCode);

	return ret;
}

flag SamplePeriod_Encode(const SamplePeriod* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? SamplePeriod_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    ret = T_UInt32_Encode(pVal, pBitStrm, pErrCode, FALSE);
    }

	return ret;
}

flag SamplePeriod_Decode(SamplePeriod* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	ret = T_UInt32_Decode(pVal, pBitStrm, pErrCode);

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void BatchSize_Initialize(BatchSize* pVal)
{
    *pVal = (BatchSize) 0;
}
#endif

 
flag BatchSize_IsConstraintValid(const BatchSize* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = T_UInt32_IsConstraintValid(pVal, pErrCode);

	return ret;
}

flag BatchSize_Encode(const BatchSize* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? BatchSize_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    ret = T_UInt32_Encode(pVal, pBitStrm, pErrCode, FALSE);
    }

	return ret;
}

flag BatchSize_Decode(BatchSize* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	ret = T_UInt32_Decode(pVal, pBitStrm, pErrCode);

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void BatchCount_Initialize(BatchCount* pVal)
{
    *pVal = (BatchCount) 0;
}
#endif

 
flag BatchCount_IsConstraintValid(const BatchCount* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = T_UInt32_IsConstraintValid(pVal, pErrCode);

	return ret;
}

flag BatchCount_Encode(const BatchCount* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? BatchCount_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    ret = T_UInt32_Encode(pVal, pBitStrm, pErrCode, FALSE);
    }

	return ret;
}

flag BatchCount_Decode(BatchCount* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	ret = T_UInt32_Decode(pVal, pBitStrm, pErrCode);

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void SampleCommand_Initialize(SampleCommand* pVal)
{
    *pVal = (SampleCommand) {
    .period = 0,
    .batch_size = 0,
    .batch_count = 0
};
}
#endif

 
flag SampleCommand_IsConstraintValid(const SampleCommand* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = SamplePeriod_IsConstraintValid(&pVal->period, pErrCode);
	if (ret) {
	    ret = BatchSize_IsConstraintValid(&pVal->batch_size, pErrCode);
	    if (ret) {
	        ret = BatchCount_IsConstraintValid(&pVal->batch_count, pErrCode);
	    
	    }
	}

	return ret;
}

flag SampleCommand_Encode(const SampleCommand* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? SampleCommand_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode period */
	    ret = SamplePeriod_Encode(&pVal->period, pBitStrm, pErrCode, FALSE);
	    if (ret) {
	        /*Encode batch_size */
	        ret = BatchSize_Encode(&pVal->batch_size, pBitStrm, pErrCode, FALSE);
	        if (ret) {
	            /*Encode batch_count */
	            ret = BatchCount_Encode(&pVal->batch_count, pBitStrm, pErrCode, FALSE);
	        
	        }
	    }
    }

	return ret;
}

flag SampleCommand_Decode(SampleCommand* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	/*Decode period */
	ret = SamplePeriod_Decode(&pVal->period, pBitStrm, pErrCode);
	if (ret) {
	    /*Decode batch_size */
	    ret = BatchSize_Decode(&pVal->batch_size, pBitStrm, pErrCode);
	    if (ret) {
	        /*Decode batch_count */
	        ret = BatchCount_Decode(&pVal->batch_count, pBitStrm, pErrCode);
	    
	    }
	}


	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void SensorConfiguration_Initialize(SensorConfiguration* pVal)
{
    *pVal = (SensorConfiguration) {
    .device = {0,
        {
        }
    },
    .period = 0,
    .batch_size = 0,
    .batch_count = 0
};
}
#endif

 
flag SensorConfiguration_IsConstraintValid(const SensorConfiguration* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = T_String_IsConstraintValid(&pVal->device, pErrCode);
	if (ret) {
	    ret = SamplePeriod_IsConstraintValid(&pVal->period, pErrCode);
	    if (ret) {
	        ret = BatchSize_IsConstraintValid(&pVal->batch_size, pErrCode);
	        if (ret) {
	            ret = BatchCount_IsConstraintValid(&pVal->batch_count, pErrCode);
	        
	        }
	    }
	}

	return ret;
}

flag SensorConfiguration_Encode(const SensorConfiguration* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? SensorConfiguration_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode device */
	    ret = T_String_Encode(&pVal->device, pBitStrm, pErrCode, FALSE);
	    if (ret) {
	        /*Encode period */
	        ret = SamplePeriod_Encode(&pVal->period, pBitStrm, pErrCode, FALSE);
	        if (ret) {
	            /*Encode batch_size */
	            ret = BatchSize_Encode(&pVal->batch_size, pBitStrm, pErrCode, FALSE);
	            if (ret) {
	                /*Encode batch_count */
	                ret = BatchCount_Encode(&pVal->batch_count, pBitStrm, pErrCode, FALSE);
	            
	            }
	        }
	    }
    }

	return ret;
}

flag SensorConfiguration_Decode(SensorConfiguration* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	/*Decode device */
	ret = T_String_Decode(&pVal->device, pBitStrm, pErrCode);
	if (ret) {
	    /*Decode period */
	    ret = SamplePeriod_Decode(&pVal->period, pBitStrm, pErrCode);
	    if (ret) {
	        /*Decode batch_size */
	        ret = BatchSize_Decode(&pVal->batch_size, pBitStrm, pErrCode);
	        if (ret) {
	            /*Decode batch_count */
	            ret = BatchCount_Decode(&pVal->batch_count, pBitStrm, pErrCode);
	        
	        }
	    }
	}


	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void SensorState_Initialize(SensorState* pVal)
{
    *pVal = (SensorState) inactive;
}
#endif

 
flag SensorState_IsConstraintValid(const SensorState* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = ((((*pVal == inactive) || (*pVal == standby)) || (*pVal == operational)) || (*pVal == failure));
	*pErrCode = ret ? 0 : ERR_SensorState;

	return ret;
}

flag SensorState_Encode(const SensorState* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? SensorState_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    switch(*pVal) 
	    {
	        case inactive:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 0, 0, 3);
	        	break;
	        case standby:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 1, 0, 3);
	        	break;
	        case operational:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 2, 0, 3);
	        	break;
	        case failure:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 3, 0, 3);
	        	break;
	        default:
	    	    *pErrCode = 1076625409; //COVERAGE_IGNORE
	    	    ret = FALSE;            //COVERAGE_IGNORE
	    }
    }

	return ret;
}

flag SensorState_Decode(SensorState* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint enumIndex;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &enumIndex, 0, 3);
	*pErrCode = ret ? 0 : 271319041;
	if (ret) {
	    switch(enumIndex) 
	    {
	        case 0: 
	            *pVal = inactive;
	            break;
	        case 1: 
	            *pVal = standby;
	            break;
	        case 2: 
	            *pVal = operational;
	            break;
	        case 3: 
	            *pVal = failure;
	            break;
	        default:
		        *pErrCode = 1076625410;     //COVERAGE_IGNORE
		        ret = FALSE;                //COVERAGE_IGNORE
	    }
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void SensorStatus_Initialize(SensorStatus* pVal)
{
    *pVal = (SensorStatus) {
    .state = inactive,
    .temperature = {
        .kelvin = 0.00000000000000000000E+000
    }
};
}
#endif

 
flag SensorStatus_IsConstraintValid(const SensorStatus* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = SensorState_IsConstraintValid(&pVal->state, pErrCode);
	if (ret) {
	    ret = Temperature_IsConstraintValid(&pVal->temperature, pErrCode);
	
	}

	return ret;
}

flag SensorStatus_Encode(const SensorStatus* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? SensorStatus_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode state */
	    ret = SensorState_Encode(&pVal->state, pBitStrm, pErrCode, FALSE);
	    if (ret) {
	        /*Encode temperature */
	        ret = Temperature_Encode(&pVal->temperature, pBitStrm, pErrCode, FALSE);
	    
	    }
    }

	return ret;
}

flag SensorStatus_Decode(SensorStatus* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	/*Decode state */
	ret = SensorState_Decode(&pVal->state, pBitStrm, pErrCode);
	if (ret) {
	    /*Decode temperature */
	    ret = Temperature_Decode(&pVal->temperature, pBitStrm, pErrCode);
	
	}


	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void StateCommand_Initialize(StateCommand* pVal)
{
    *pVal = (StateCommand) activate;
}
#endif

 
flag StateCommand_IsConstraintValid(const StateCommand* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = ((((*pVal == activate) || (*pVal == start)) || (*pVal == stop)) || (*pVal == deactivate));
	*pErrCode = ret ? 0 : ERR_StateCommand;

	return ret;
}

flag StateCommand_Encode(const StateCommand* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? StateCommand_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    switch(*pVal) 
	    {
	        case activate:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 0, 0, 3);
	        	break;
	        case start:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 1, 0, 3);
	        	break;
	        case stop:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 2, 0, 3);
	        	break;
	        case deactivate:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 3, 0, 3);
	        	break;
	        default:
	    	    *pErrCode = 1076625411; //COVERAGE_IGNORE
	    	    ret = FALSE;            //COVERAGE_IGNORE
	    }
    }

	return ret;
}

flag StateCommand_Decode(StateCommand* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint enumIndex;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &enumIndex, 0, 3);
	*pErrCode = ret ? 0 : 271319042;
	if (ret) {
	    switch(enumIndex) 
	    {
	        case 0: 
	            *pVal = activate;
	            break;
	        case 1: 
	            *pVal = start;
	            break;
	        case 2: 
	            *pVal = stop;
	            break;
	        case 3: 
	            *pVal = deactivate;
	            break;
	        default:
		        *pErrCode = 1076625412;     //COVERAGE_IGNORE
		        ret = FALSE;                //COVERAGE_IGNORE
	    }
	}

	return ret;
}
