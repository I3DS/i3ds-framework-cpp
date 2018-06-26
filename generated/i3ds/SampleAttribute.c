/*
Code automatically generated by asn1scc tool
*/
#include <limits.h>
#include <string.h>
#include <math.h>
#include "SampleAttribute.h"

#if !defined(_MSC_VER) || _MSC_VER >= 1800
void SampleValidity_Initialize(SampleValidity* pVal)
{
    *pVal = (SampleValidity) sample_empty;
}
#endif

 
flag SampleValidity_IsConstraintValid(const SampleValidity* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = (((*pVal == sample_empty) || (*pVal == sample_valid)) || (*pVal == sample_invalid));
	*pErrCode = ret ? 0 : ERR_SampleValidity;

	return ret;
}

flag SampleValidity_Encode(const SampleValidity* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? SampleValidity_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    switch(*pVal) 
	    {
	        case sample_empty:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 0, 0, 2);
	        	break;
	        case sample_valid:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 1, 0, 2);
	        	break;
	        case sample_invalid:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 2, 0, 2);
	        	break;
	        default:
	    	    *pErrCode = 1078198273; //COVERAGE_IGNORE
	    	    ret = FALSE;            //COVERAGE_IGNORE
	    }
    }

	return ret;
}

flag SampleValidity_Decode(SampleValidity* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint enumIndex;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &enumIndex, 0, 2);
	*pErrCode = ret ? 0 : 272891905;
	if (ret) {
	    switch(enumIndex) 
	    {
	        case 0: 
	            *pVal = sample_empty;
	            break;
	        case 1: 
	            *pVal = sample_valid;
	            break;
	        case 2: 
	            *pVal = sample_invalid;
	            break;
	        default:
		        *pErrCode = 1078198274;     //COVERAGE_IGNORE
		        ret = FALSE;                //COVERAGE_IGNORE
	    }
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void T_String16_Initialize(T_String16* pVal)
{
    *pVal = (T_String16) {0,
    {
    }
};
}
#endif

 
flag T_String16_IsConstraintValid(const T_String16* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = (0 <= pVal->nCount && pVal->nCount <= 16);
	*pErrCode = ret ? 0 : ERR_T_String16;

	return ret;
}

flag T_String16_Encode(const T_String16* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? T_String16_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 0, 16);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	BitStream_AppendByte0(pBitStrm, pVal->arr[i1]);
	    }
    }

	return ret;
}

flag T_String16_Decode(T_String16* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 0, 16);
	*pErrCode = ret ? 0 : 272891906;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = BitStream_ReadByte(pBitStrm, &pVal->arr[i1]); 
		*pErrCode = ret ? 0 : 272891907;
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Attribute_value_t_Initialize(Attribute_value_t* pVal)
{
    *pVal = (Attribute_value_t) {
    .kind = boolean_value_PRESENT,
    .u = { .boolean_value = FALSE}
};
}
#endif

 
flag Attribute_value_t_IsConstraintValid(const Attribute_value_t* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	switch (pVal->kind) {
	    case boolean_value_PRESENT :
	        ret = T_Boolean_IsConstraintValid(&pVal->u.boolean_value, pErrCode);
	        break;
	    case discrete_value_PRESENT :
	        ret = T_Int64_IsConstraintValid(&pVal->u.discrete_value, pErrCode);
	        break;
	    case real_value_PRESENT :
	        ret = T_Double_IsConstraintValid(&pVal->u.real_value, pErrCode);
	        break;
	    case string_value_PRESENT :
	        ret = T_String16_IsConstraintValid(&pVal->u.string_value, pErrCode);
	        break;
	    default:
		    *pErrCode = 809762817;   //COVERAGE_IGNORE
		    ret = FALSE;                    //COVERAGE_IGNORE
	}

	return ret;
}

flag Attribute_value_t_Encode(const Attribute_value_t* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? Attribute_value_t_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    switch(pVal->kind) 
	    {
	    case boolean_value_PRESENT:
	    	BitStream_EncodeConstraintWholeNumber(pBitStrm, 0, 0, 3);
	    	ret = T_Boolean_Encode(&pVal->u.boolean_value, pBitStrm, pErrCode, FALSE);
	    	break;
	    case discrete_value_PRESENT:
	    	BitStream_EncodeConstraintWholeNumber(pBitStrm, 1, 0, 3);
	    	ret = T_Int64_Encode(&pVal->u.discrete_value, pBitStrm, pErrCode, FALSE);
	    	break;
	    case real_value_PRESENT:
	    	BitStream_EncodeConstraintWholeNumber(pBitStrm, 2, 0, 3);
	    	ret = T_Double_Encode(&pVal->u.real_value, pBitStrm, pErrCode, FALSE);
	    	break;
	    case string_value_PRESENT:
	    	BitStream_EncodeConstraintWholeNumber(pBitStrm, 3, 0, 3);
	    	ret = T_String16_Encode(&pVal->u.string_value, pBitStrm, pErrCode, FALSE);
	    	break;
	    default:
	        *pErrCode = 809762818;         //COVERAGE_IGNORE
	        ret = FALSE;                    //COVERAGE_IGNORE
	    }
    }

	return ret;
}

flag Attribute_value_t_Decode(Attribute_value_t* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nChoiceIndex;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nChoiceIndex, 0, 3);
	*pErrCode = ret ? 0 : 272891908;
	if (ret) {
	    switch(nChoiceIndex) 
	    {
	    case 0:
	    	pVal->kind = boolean_value_PRESENT;
	    	ret = T_Boolean_Decode(&pVal->u.boolean_value, pBitStrm, pErrCode);
	    	break;
	    case 1:
	    	pVal->kind = discrete_value_PRESENT;
	    	ret = T_Int64_Decode(&pVal->u.discrete_value, pBitStrm, pErrCode);
	    	break;
	    case 2:
	    	pVal->kind = real_value_PRESENT;
	    	ret = T_Double_Decode(&pVal->u.real_value, pBitStrm, pErrCode);
	    	break;
	    case 3:
	    	pVal->kind = string_value_PRESENT;
	    	ret = T_String16_Decode(&pVal->u.string_value, pBitStrm, pErrCode);
	    	break;
	    default:
	        *pErrCode = 809762819;     //COVERAGE_IGNORE
	        ret = FALSE;                //COVERAGE_IGNORE
	    }
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Sample_attribute_t_Initialize(Sample_attribute_t* pVal)
{
    *pVal = (Sample_attribute_t) {
    .attribute_key = 0,
    .attribute_value = {
        .kind = boolean_value_PRESENT,
        .u = { .boolean_value = FALSE}
    }
};
}
#endif

 
flag Sample_attribute_t_IsConstraintValid(const Sample_attribute_t* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = T_UInt8_IsConstraintValid(&pVal->attribute_key, pErrCode);
	if (ret) {
	    ret = Attribute_value_t_IsConstraintValid(&pVal->attribute_value, pErrCode);
	
	}

	return ret;
}

flag Sample_attribute_t_Encode(const Sample_attribute_t* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? Sample_attribute_t_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode attribute_key */
	    ret = T_UInt8_Encode(&pVal->attribute_key, pBitStrm, pErrCode, FALSE);
	    if (ret) {
	        /*Encode attribute_value */
	        ret = Attribute_value_t_Encode(&pVal->attribute_value, pBitStrm, pErrCode, FALSE);
	    
	    }
    }

	return ret;
}

flag Sample_attribute_t_Decode(Sample_attribute_t* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	/*Decode attribute_key */
	ret = T_UInt8_Decode(&pVal->attribute_key, pBitStrm, pErrCode);
	if (ret) {
	    /*Decode attribute_value */
	    ret = Attribute_value_t_Decode(&pVal->attribute_value, pBitStrm, pErrCode);
	
	}


	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void SampleAttributes_attributes_Initialize(SampleAttributes_attributes* pVal)
{
    *pVal = (SampleAttributes_attributes) {    .nCount = 0,    .arr = 
    {
        
    }
};
}
#endif

 
flag SampleAttributes_attributes_IsConstraintValid(const SampleAttributes_attributes* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (0 <= pVal->nCount && pVal->nCount <= 5);
	*pErrCode = ret ? 0 : ERR_SampleAttributes_attributes;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = Sample_attribute_t_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag SampleAttributes_attributes_Encode(const SampleAttributes_attributes* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? SampleAttributes_attributes_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 0, 5);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = Sample_attribute_t_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag SampleAttributes_attributes_Decode(SampleAttributes_attributes* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 0, 5);
	*pErrCode = ret ? 0 : 272891909;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = Sample_attribute_t_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void SampleAttributes_Initialize(SampleAttributes* pVal)
{
    *pVal = (SampleAttributes) {
    .timestamp = {
        .microseconds = -9223372036854775807LL,
        .usecPerSec = -2147483648LL
    },
    .validity = sample_empty,
    .attributes = {    .nCount = 0,    .arr = 
        {
            
        }
    }
};
}
#endif

 
flag SampleAttributes_IsConstraintValid(const SampleAttributes* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = Time_IsConstraintValid(&pVal->timestamp, pErrCode);
	if (ret) {
	    ret = SampleValidity_IsConstraintValid(&pVal->validity, pErrCode);
	    if (ret) {
	        ret = SampleAttributes_attributes_IsConstraintValid(&pVal->attributes, pErrCode);
	    
	    }
	}

	return ret;
}

flag SampleAttributes_Encode(const SampleAttributes* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? SampleAttributes_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode timestamp */
	    ret = Time_Encode(&pVal->timestamp, pBitStrm, pErrCode, FALSE);
	    if (ret) {
	        /*Encode validity */
	        ret = SampleValidity_Encode(&pVal->validity, pBitStrm, pErrCode, FALSE);
	        if (ret) {
	            /*Encode attributes */
	            ret = SampleAttributes_attributes_Encode(&pVal->attributes, pBitStrm, pErrCode, FALSE);
	        
	        }
	    }
    }

	return ret;
}

flag SampleAttributes_Decode(SampleAttributes* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	/*Decode timestamp */
	ret = Time_Decode(&pVal->timestamp, pBitStrm, pErrCode);
	if (ret) {
	    /*Decode validity */
	    ret = SampleValidity_Decode(&pVal->validity, pBitStrm, pErrCode);
	    if (ret) {
	        /*Decode attributes */
	        ret = SampleAttributes_attributes_Decode(&pVal->attributes, pBitStrm, pErrCode);
	    
	    }
	}


	return ret;
}

