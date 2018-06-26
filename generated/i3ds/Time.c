/*
Code automatically generated by asn1scc tool
*/
#include <limits.h>
#include <string.h>
#include <math.h>
#include "Time.h"

#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Time_Initialize(Time* pVal)
{
    *pVal = (Time) {
    .microseconds = -9223372036854775807LL,
    .usecPerSec = -2147483648LL
};
}
#endif

 
flag Time_IsConstraintValid(const Time* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = T_Int64_IsConstraintValid(&pVal->microseconds, pErrCode);
	if (ret) {
	    ret = T_Int32_IsConstraintValid(&pVal->usecPerSec, pErrCode);
	
	}

	return ret;
}

flag Time_Encode(const Time* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? Time_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode microseconds */
	    ret = T_Int64_Encode(&pVal->microseconds, pBitStrm, pErrCode, FALSE);
	    if (ret) {
	        /*Encode usecPerSec */
	        ret = T_Int32_Encode(&pVal->usecPerSec, pBitStrm, pErrCode, FALSE);
	    
	    }
    }

	return ret;
}

flag Time_Decode(Time* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	/*Decode microseconds */
	ret = T_Int64_Decode(&pVal->microseconds, pBitStrm, pErrCode);
	if (ret) {
	    /*Decode usecPerSec */
	    ret = T_Int32_Decode(&pVal->usecPerSec, pBitStrm, pErrCode);
	
	}


	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Resolution_Initialize(Resolution* pVal)
{
    *pVal = (Resolution) seconds;
}
#endif

 
flag Resolution_IsConstraintValid(const Resolution* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = (((*pVal == seconds) || (*pVal == milliseconds)) || (*pVal == microseconds));
	*pErrCode = ret ? 0 : ERR_Resolution;

	return ret;
}

flag Resolution_Encode(const Resolution* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? Resolution_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    switch(*pVal) 
	    {
	        case seconds:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 0, 0, 2);
	        	break;
	        case milliseconds:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 1, 0, 2);
	        	break;
	        case microseconds:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 2, 0, 2);
	        	break;
	        default:
	    	    *pErrCode = 1075052545; //COVERAGE_IGNORE
	    	    ret = FALSE;            //COVERAGE_IGNORE
	    }
    }

	return ret;
}

flag Resolution_Decode(Resolution* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint enumIndex;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &enumIndex, 0, 2);
	*pErrCode = ret ? 0 : 269746177;
	if (ret) {
	    switch(enumIndex) 
	    {
	        case 0: 
	            *pVal = seconds;
	            break;
	        case 1: 
	            *pVal = milliseconds;
	            break;
	        case 2: 
	            *pVal = microseconds;
	            break;
	        default:
		        *pErrCode = 1075052546;     //COVERAGE_IGNORE
		        ret = FALSE;                //COVERAGE_IGNORE
	    }
	}

	return ret;
}

