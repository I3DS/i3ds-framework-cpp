/*
Code automatically generated by asn1scc tool
*/
#include <limits.h>
#include <string.h>
#include <math.h>
#include "Analog.h"

#if !defined(_MSC_VER) || _MSC_VER >= 1800
void SeriesCount_Initialize(SeriesCount* pVal)
{
    *pVal = (SeriesCount) 0;
}
#endif

 
flag SeriesCount_IsConstraintValid(const SeriesCount* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = T_UInt8_IsConstraintValid(pVal, pErrCode);

	return ret;
}

flag SeriesCount_Encode(const SeriesCount* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? SeriesCount_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    ret = T_UInt8_Encode(pVal, pBitStrm, pErrCode, FALSE);
    }

	return ret;
}

flag SeriesCount_Decode(SeriesCount* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	ret = T_UInt8_Decode(pVal, pBitStrm, pErrCode);

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void AnalogMeasurement10K_samples_Initialize(AnalogMeasurement10K_samples* pVal)
{
    *pVal = (AnalogMeasurement10K_samples) {    .nCount = 0,    .arr = 
    {
        
    }
};
}
#endif

 
flag AnalogMeasurement10K_samples_IsConstraintValid(const AnalogMeasurement10K_samples* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (0 <= pVal->nCount && pVal->nCount <= 10000);
	*pErrCode = ret ? 0 : ERR_AnalogMeasurement10K_samples;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = T_Float_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag AnalogMeasurement10K_samples_Encode(const AnalogMeasurement10K_samples* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? AnalogMeasurement10K_samples_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 0, 10000);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = T_Float_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag AnalogMeasurement10K_samples_Decode(AnalogMeasurement10K_samples* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 0, 10000);
	*pErrCode = ret ? 0 : 270008321;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = T_Float_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void AnalogMeasurement10K_Initialize(AnalogMeasurement10K* pVal)
{
    *pVal = (AnalogMeasurement10K) {
    .attributes = {
        .timestamp = {
            .microseconds = -9223372036854775807LL,
            .usecPerSec = -2147483648LL
        },
        .validity = sample_empty,
        .attributes = {    .nCount = 0,    .arr = 
            {
                
            }
        }
    },
    .samples = {    .nCount = 0,    .arr = 
        {
            
        }
    },
    .series = 0,
    .batch_size = 0
};
}
#endif

 
flag AnalogMeasurement10K_IsConstraintValid(const AnalogMeasurement10K* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = SampleAttributes_IsConstraintValid(&pVal->attributes, pErrCode);
	if (ret) {
	    ret = AnalogMeasurement10K_samples_IsConstraintValid(&pVal->samples, pErrCode);
	    if (ret) {
	        ret = SeriesCount_IsConstraintValid(&pVal->series, pErrCode);
	        if (ret) {
	            ret = BatchSize_IsConstraintValid(&pVal->batch_size, pErrCode);
	        
	        }
	    }
	}

	return ret;
}

flag AnalogMeasurement10K_Encode(const AnalogMeasurement10K* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? AnalogMeasurement10K_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode attributes */
	    ret = SampleAttributes_Encode(&pVal->attributes, pBitStrm, pErrCode, FALSE);
	    if (ret) {
	        /*Encode samples */
	        ret = AnalogMeasurement10K_samples_Encode(&pVal->samples, pBitStrm, pErrCode, FALSE);
	        if (ret) {
	            /*Encode series */
	            ret = SeriesCount_Encode(&pVal->series, pBitStrm, pErrCode, FALSE);
	            if (ret) {
	                /*Encode batch_size */
	                ret = BatchSize_Encode(&pVal->batch_size, pBitStrm, pErrCode, FALSE);
	            
	            }
	        }
	    }
    }

	return ret;
}

flag AnalogMeasurement10K_Decode(AnalogMeasurement10K* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	/*Decode attributes */
	ret = SampleAttributes_Decode(&pVal->attributes, pBitStrm, pErrCode);
	if (ret) {
	    /*Decode samples */
	    ret = AnalogMeasurement10K_samples_Decode(&pVal->samples, pBitStrm, pErrCode);
	    if (ret) {
	        /*Decode series */
	        ret = SeriesCount_Decode(&pVal->series, pBitStrm, pErrCode);
	        if (ret) {
	            /*Decode batch_size */
	            ret = BatchSize_Decode(&pVal->batch_size, pBitStrm, pErrCode);
	        
	        }
	    }
	}


	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void AnalogMeasurement3K_samples_Initialize(AnalogMeasurement3K_samples* pVal)
{
    *pVal = (AnalogMeasurement3K_samples) {    .nCount = 0,    .arr = 
    {
        
    }
};
}
#endif

 
flag AnalogMeasurement3K_samples_IsConstraintValid(const AnalogMeasurement3K_samples* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (0 <= pVal->nCount && pVal->nCount <= 3000);
	*pErrCode = ret ? 0 : ERR_AnalogMeasurement3K_samples;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = T_Float_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag AnalogMeasurement3K_samples_Encode(const AnalogMeasurement3K_samples* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? AnalogMeasurement3K_samples_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 0, 3000);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = T_Float_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag AnalogMeasurement3K_samples_Decode(AnalogMeasurement3K_samples* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 0, 3000);
	*pErrCode = ret ? 0 : 270008322;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = T_Float_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void AnalogMeasurement3K_Initialize(AnalogMeasurement3K* pVal)
{
    *pVal = (AnalogMeasurement3K) {
    .attributes = {
        .timestamp = {
            .microseconds = -9223372036854775807LL,
            .usecPerSec = -2147483648LL
        },
        .validity = sample_empty,
        .attributes = {    .nCount = 0,    .arr = 
            {
                
            }
        }
    },
    .samples = {    .nCount = 0,    .arr = 
        {
            
        }
    },
    .series = 0,
    .batch_size = 0
};
}
#endif

 
flag AnalogMeasurement3K_IsConstraintValid(const AnalogMeasurement3K* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = SampleAttributes_IsConstraintValid(&pVal->attributes, pErrCode);
	if (ret) {
	    ret = AnalogMeasurement3K_samples_IsConstraintValid(&pVal->samples, pErrCode);
	    if (ret) {
	        ret = SeriesCount_IsConstraintValid(&pVal->series, pErrCode);
	        if (ret) {
	            ret = BatchSize_IsConstraintValid(&pVal->batch_size, pErrCode);
	        
	        }
	    }
	}

	return ret;
}

flag AnalogMeasurement3K_Encode(const AnalogMeasurement3K* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? AnalogMeasurement3K_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode attributes */
	    ret = SampleAttributes_Encode(&pVal->attributes, pBitStrm, pErrCode, FALSE);
	    if (ret) {
	        /*Encode samples */
	        ret = AnalogMeasurement3K_samples_Encode(&pVal->samples, pBitStrm, pErrCode, FALSE);
	        if (ret) {
	            /*Encode series */
	            ret = SeriesCount_Encode(&pVal->series, pBitStrm, pErrCode, FALSE);
	            if (ret) {
	                /*Encode batch_size */
	                ret = BatchSize_Encode(&pVal->batch_size, pBitStrm, pErrCode, FALSE);
	            
	            }
	        }
	    }
    }

	return ret;
}

flag AnalogMeasurement3K_Decode(AnalogMeasurement3K* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	/*Decode attributes */
	ret = SampleAttributes_Decode(&pVal->attributes, pBitStrm, pErrCode);
	if (ret) {
	    /*Decode samples */
	    ret = AnalogMeasurement3K_samples_Decode(&pVal->samples, pBitStrm, pErrCode);
	    if (ret) {
	        /*Decode series */
	        ret = SeriesCount_Decode(&pVal->series, pBitStrm, pErrCode);
	        if (ret) {
	            /*Decode batch_size */
	            ret = BatchSize_Decode(&pVal->batch_size, pBitStrm, pErrCode);
	        
	        }
	    }
	}


	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void AnalogMeasurement1K_samples_Initialize(AnalogMeasurement1K_samples* pVal)
{
    *pVal = (AnalogMeasurement1K_samples) {    .nCount = 0,    .arr = 
    {
        
    }
};
}
#endif

 
flag AnalogMeasurement1K_samples_IsConstraintValid(const AnalogMeasurement1K_samples* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (0 <= pVal->nCount && pVal->nCount <= 1000);
	*pErrCode = ret ? 0 : ERR_AnalogMeasurement1K_samples;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = T_Float_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag AnalogMeasurement1K_samples_Encode(const AnalogMeasurement1K_samples* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? AnalogMeasurement1K_samples_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 0, 1000);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = T_Float_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag AnalogMeasurement1K_samples_Decode(AnalogMeasurement1K_samples* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 0, 1000);
	*pErrCode = ret ? 0 : 270008323;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = T_Float_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void AnalogMeasurement1K_Initialize(AnalogMeasurement1K* pVal)
{
    *pVal = (AnalogMeasurement1K) {
    .attributes = {
        .timestamp = {
            .microseconds = -9223372036854775807LL,
            .usecPerSec = -2147483648LL
        },
        .validity = sample_empty,
        .attributes = {    .nCount = 0,    .arr = 
            {
                
            }
        }
    },
    .samples = {    .nCount = 0,    .arr = 
        {
            
        }
    },
    .series = 0,
    .batch_size = 0
};
}
#endif

 
flag AnalogMeasurement1K_IsConstraintValid(const AnalogMeasurement1K* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = SampleAttributes_IsConstraintValid(&pVal->attributes, pErrCode);
	if (ret) {
	    ret = AnalogMeasurement1K_samples_IsConstraintValid(&pVal->samples, pErrCode);
	    if (ret) {
	        ret = SeriesCount_IsConstraintValid(&pVal->series, pErrCode);
	        if (ret) {
	            ret = BatchSize_IsConstraintValid(&pVal->batch_size, pErrCode);
	        
	        }
	    }
	}

	return ret;
}

flag AnalogMeasurement1K_Encode(const AnalogMeasurement1K* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? AnalogMeasurement1K_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode attributes */
	    ret = SampleAttributes_Encode(&pVal->attributes, pBitStrm, pErrCode, FALSE);
	    if (ret) {
	        /*Encode samples */
	        ret = AnalogMeasurement1K_samples_Encode(&pVal->samples, pBitStrm, pErrCode, FALSE);
	        if (ret) {
	            /*Encode series */
	            ret = SeriesCount_Encode(&pVal->series, pBitStrm, pErrCode, FALSE);
	            if (ret) {
	                /*Encode batch_size */
	                ret = BatchSize_Encode(&pVal->batch_size, pBitStrm, pErrCode, FALSE);
	            
	            }
	        }
	    }
    }

	return ret;
}

flag AnalogMeasurement1K_Decode(AnalogMeasurement1K* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	/*Decode attributes */
	ret = SampleAttributes_Decode(&pVal->attributes, pBitStrm, pErrCode);
	if (ret) {
	    /*Decode samples */
	    ret = AnalogMeasurement1K_samples_Decode(&pVal->samples, pBitStrm, pErrCode);
	    if (ret) {
	        /*Decode series */
	        ret = SeriesCount_Decode(&pVal->series, pBitStrm, pErrCode);
	        if (ret) {
	            /*Decode batch_size */
	            ret = BatchSize_Decode(&pVal->batch_size, pBitStrm, pErrCode);
	        
	        }
	    }
	}


	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void AnalogMeasurement300_samples_Initialize(AnalogMeasurement300_samples* pVal)
{
    *pVal = (AnalogMeasurement300_samples) {    .nCount = 0,    .arr = 
    {
        
    }
};
}
#endif

 
flag AnalogMeasurement300_samples_IsConstraintValid(const AnalogMeasurement300_samples* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (0 <= pVal->nCount && pVal->nCount <= 300);
	*pErrCode = ret ? 0 : ERR_AnalogMeasurement300_samples;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = T_Float_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag AnalogMeasurement300_samples_Encode(const AnalogMeasurement300_samples* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? AnalogMeasurement300_samples_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 0, 300);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = T_Float_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag AnalogMeasurement300_samples_Decode(AnalogMeasurement300_samples* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 0, 300);
	*pErrCode = ret ? 0 : 270008324;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = T_Float_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void AnalogMeasurement300_Initialize(AnalogMeasurement300* pVal)
{
    *pVal = (AnalogMeasurement300) {
    .attributes = {
        .timestamp = {
            .microseconds = -9223372036854775807LL,
            .usecPerSec = -2147483648LL
        },
        .validity = sample_empty,
        .attributes = {    .nCount = 0,    .arr = 
            {
                
            }
        }
    },
    .samples = {    .nCount = 0,    .arr = 
        {
            
        }
    },
    .series = 0,
    .batch_size = 0
};
}
#endif

 
flag AnalogMeasurement300_IsConstraintValid(const AnalogMeasurement300* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = SampleAttributes_IsConstraintValid(&pVal->attributes, pErrCode);
	if (ret) {
	    ret = AnalogMeasurement300_samples_IsConstraintValid(&pVal->samples, pErrCode);
	    if (ret) {
	        ret = SeriesCount_IsConstraintValid(&pVal->series, pErrCode);
	        if (ret) {
	            ret = BatchSize_IsConstraintValid(&pVal->batch_size, pErrCode);
	        
	        }
	    }
	}

	return ret;
}

flag AnalogMeasurement300_Encode(const AnalogMeasurement300* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? AnalogMeasurement300_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode attributes */
	    ret = SampleAttributes_Encode(&pVal->attributes, pBitStrm, pErrCode, FALSE);
	    if (ret) {
	        /*Encode samples */
	        ret = AnalogMeasurement300_samples_Encode(&pVal->samples, pBitStrm, pErrCode, FALSE);
	        if (ret) {
	            /*Encode series */
	            ret = SeriesCount_Encode(&pVal->series, pBitStrm, pErrCode, FALSE);
	            if (ret) {
	                /*Encode batch_size */
	                ret = BatchSize_Encode(&pVal->batch_size, pBitStrm, pErrCode, FALSE);
	            
	            }
	        }
	    }
    }

	return ret;
}

flag AnalogMeasurement300_Decode(AnalogMeasurement300* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	/*Decode attributes */
	ret = SampleAttributes_Decode(&pVal->attributes, pBitStrm, pErrCode);
	if (ret) {
	    /*Decode samples */
	    ret = AnalogMeasurement300_samples_Decode(&pVal->samples, pBitStrm, pErrCode);
	    if (ret) {
	        /*Decode series */
	        ret = SeriesCount_Decode(&pVal->series, pBitStrm, pErrCode);
	        if (ret) {
	            /*Decode batch_size */
	            ret = BatchSize_Decode(&pVal->batch_size, pBitStrm, pErrCode);
	        
	        }
	    }
	}


	return ret;
}

