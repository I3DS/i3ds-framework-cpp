/*
Code automatically generated by asn1scc tool
*/
#include <limits.h>
#include <string.h>
#include <math.h>
#include "Eigen.h"

#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Vector6d_Initialize(Vector6d* pVal)
{
    *pVal = (Vector6d) {    .nCount = 1,    .arr = 
    {
        0.00000000000000000000E+000        
    }
};
}
#endif

 
flag Vector6d_IsConstraintValid(const Vector6d* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 6);
	*pErrCode = ret ? 0 : ERR_Vector6d;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = T_Double_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag Vector6d_Encode(const Vector6d* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? Vector6d_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 6);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = T_Double_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag Vector6d_Decode(Vector6d* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 6);
	*pErrCode = ret ? 0 : 268435457;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = T_Double_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Vector3d_Initialize(Vector3d* pVal)
{
    *pVal = (Vector3d) {    .nCount = 1,    .arr = 
    {
        0.00000000000000000000E+000        
    }
};
}
#endif

 
flag Vector3d_IsConstraintValid(const Vector3d* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 3);
	*pErrCode = ret ? 0 : ERR_Vector3d;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = T_Double_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag Vector3d_Encode(const Vector3d* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? Vector3d_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 3);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = T_Double_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag Vector3d_Decode(Vector3d* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 3);
	*pErrCode = ret ? 0 : 268435458;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = T_Double_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Quaterniond_Initialize(Quaterniond* pVal)
{
    *pVal = (Quaterniond) {    .nCount = 1,    .arr = 
    {
        0.00000000000000000000E+000        
    }
};
}
#endif

 
flag Quaterniond_IsConstraintValid(const Quaterniond* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 4);
	*pErrCode = ret ? 0 : ERR_Quaterniond;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = T_Double_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag Quaterniond_Encode(const Quaterniond* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? Quaterniond_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 4);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = T_Double_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag Quaterniond_Decode(Quaterniond* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 4);
	*pErrCode = ret ? 0 : 268435459;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = T_Double_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void VectorXd_Initialize(VectorXd* pVal)
{
    *pVal = (VectorXd) {    .nCount = 1,    .arr = 
    {
        0.00000000000000000000E+000        
    }
};
}
#endif

 
flag VectorXd_IsConstraintValid(const VectorXd* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 100);
	*pErrCode = ret ? 0 : ERR_VectorXd;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = T_Double_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag VectorXd_Encode(const VectorXd* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? VectorXd_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 100);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = T_Double_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag VectorXd_Decode(VectorXd* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 100);
	*pErrCode = ret ? 0 : 268435460;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = T_Double_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Vector2d_Initialize(Vector2d* pVal)
{
    *pVal = (Vector2d) {    .nCount = 1,    .arr = 
    {
        0.00000000000000000000E+000        
    }
};
}
#endif

 
flag Vector2d_IsConstraintValid(const Vector2d* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 3);
	*pErrCode = ret ? 0 : ERR_Vector2d;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = T_Double_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag Vector2d_Encode(const Vector2d* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? Vector2d_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 3);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = T_Double_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag Vector2d_Decode(Vector2d* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 3);
	*pErrCode = ret ? 0 : 268435461;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = T_Double_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Vector4d_Initialize(Vector4d* pVal)
{
    *pVal = (Vector4d) {    .nCount = 1,    .arr = 
    {
        0.00000000000000000000E+000        
    }
};
}
#endif

 
flag Vector4d_IsConstraintValid(const Vector4d* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 4);
	*pErrCode = ret ? 0 : ERR_Vector4d;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = T_Double_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag Vector4d_Encode(const Vector4d* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? Vector4d_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 4);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = T_Double_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag Vector4d_Decode(Vector4d* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 4);
	*pErrCode = ret ? 0 : 268435462;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = T_Double_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void AngleAxisd_Initialize(AngleAxisd* pVal)
{
    *pVal = (AngleAxisd) {    .nCount = 1,    .arr = 
    {
        0.00000000000000000000E+000        
    }
};
}
#endif

 
flag AngleAxisd_IsConstraintValid(const AngleAxisd* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 4);
	*pErrCode = ret ? 0 : ERR_AngleAxisd;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = T_Double_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag AngleAxisd_Encode(const AngleAxisd* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? AngleAxisd_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 4);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = T_Double_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag AngleAxisd_Decode(AngleAxisd* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 4);
	*pErrCode = ret ? 0 : 268435463;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = T_Double_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Transform3d_elm_Initialize(Transform3d_elm* pVal)
{
    *pVal = (Transform3d_elm) {    .nCount = 1,    .arr = 
    {
        0.00000000000000000000E+000        
    }
};
}
#endif

 
flag Transform3d_elm_IsConstraintValid(const Transform3d_elm* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 4);
	*pErrCode = ret ? 0 : ERR_Transform3d_elm;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = T_Double_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag Transform3d_elm_Encode(const Transform3d_elm* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? Transform3d_elm_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 4);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = T_Double_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag Transform3d_elm_Decode(Transform3d_elm* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 4);
	*pErrCode = ret ? 0 : 268435464;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = T_Double_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Transform3d_Initialize(Transform3d* pVal)
{
    *pVal = (Transform3d) {    .nCount = 1,    .arr = 
    {
        {    .nCount = 1,    .arr = 
            {
                0.00000000000000000000E+000        
            }
        }        
    }
};
}
#endif

 
flag Transform3d_IsConstraintValid(const Transform3d* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 4);
	*pErrCode = ret ? 0 : ERR_Transform3d;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = Transform3d_elm_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag Transform3d_Encode(const Transform3d* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? Transform3d_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 4);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = Transform3d_elm_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag Transform3d_Decode(Transform3d* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 4);
	*pErrCode = ret ? 0 : 268435465;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = Transform3d_elm_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Matrix4d_elm_Initialize(Matrix4d_elm* pVal)
{
    *pVal = (Matrix4d_elm) {    .nCount = 1,    .arr = 
    {
        0.00000000000000000000E+000        
    }
};
}
#endif

 
flag Matrix4d_elm_IsConstraintValid(const Matrix4d_elm* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 4);
	*pErrCode = ret ? 0 : ERR_Matrix4d_elm;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = T_Double_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag Matrix4d_elm_Encode(const Matrix4d_elm* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? Matrix4d_elm_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 4);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = T_Double_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag Matrix4d_elm_Decode(Matrix4d_elm* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 4);
	*pErrCode = ret ? 0 : 268435466;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = T_Double_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Matrix4d_Initialize(Matrix4d* pVal)
{
    *pVal = (Matrix4d) {    .nCount = 1,    .arr = 
    {
        {    .nCount = 1,    .arr = 
            {
                0.00000000000000000000E+000        
            }
        }        
    }
};
}
#endif

 
flag Matrix4d_IsConstraintValid(const Matrix4d* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 4);
	*pErrCode = ret ? 0 : ERR_Matrix4d;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = Matrix4d_elm_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag Matrix4d_Encode(const Matrix4d* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? Matrix4d_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 4);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = Matrix4d_elm_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag Matrix4d_Decode(Matrix4d* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 4);
	*pErrCode = ret ? 0 : 268435467;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = Matrix4d_elm_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Matrix2d_elm_Initialize(Matrix2d_elm* pVal)
{
    *pVal = (Matrix2d_elm) {    .nCount = 1,    .arr = 
    {
        0.00000000000000000000E+000        
    }
};
}
#endif

 
flag Matrix2d_elm_IsConstraintValid(const Matrix2d_elm* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 2);
	*pErrCode = ret ? 0 : ERR_Matrix2d_elm;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = T_Double_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag Matrix2d_elm_Encode(const Matrix2d_elm* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? Matrix2d_elm_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 2);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = T_Double_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag Matrix2d_elm_Decode(Matrix2d_elm* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 2);
	*pErrCode = ret ? 0 : 268435468;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = T_Double_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Matrix2d_Initialize(Matrix2d* pVal)
{
    *pVal = (Matrix2d) {    .nCount = 1,    .arr = 
    {
        {    .nCount = 1,    .arr = 
            {
                0.00000000000000000000E+000        
            }
        }        
    }
};
}
#endif

 
flag Matrix2d_IsConstraintValid(const Matrix2d* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 2);
	*pErrCode = ret ? 0 : ERR_Matrix2d;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = Matrix2d_elm_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag Matrix2d_Encode(const Matrix2d* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? Matrix2d_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 2);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = Matrix2d_elm_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag Matrix2d_Decode(Matrix2d* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 2);
	*pErrCode = ret ? 0 : 268435469;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = Matrix2d_elm_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Isometry3d_elm_Initialize(Isometry3d_elm* pVal)
{
    *pVal = (Isometry3d_elm) {    .nCount = 1,    .arr = 
    {
        0.00000000000000000000E+000        
    }
};
}
#endif

 
flag Isometry3d_elm_IsConstraintValid(const Isometry3d_elm* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 4);
	*pErrCode = ret ? 0 : ERR_Isometry3d_elm;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = T_Double_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag Isometry3d_elm_Encode(const Isometry3d_elm* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? Isometry3d_elm_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 4);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = T_Double_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag Isometry3d_elm_Decode(Isometry3d_elm* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 4);
	*pErrCode = ret ? 0 : 268435470;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = T_Double_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Isometry3d_Initialize(Isometry3d* pVal)
{
    *pVal = (Isometry3d) {    .nCount = 1,    .arr = 
    {
        {    .nCount = 1,    .arr = 
            {
                0.00000000000000000000E+000        
            }
        }        
    }
};
}
#endif

 
flag Isometry3d_IsConstraintValid(const Isometry3d* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 4);
	*pErrCode = ret ? 0 : ERR_Isometry3d;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = Isometry3d_elm_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag Isometry3d_Encode(const Isometry3d* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? Isometry3d_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 4);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = Isometry3d_elm_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag Isometry3d_Decode(Isometry3d* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 4);
	*pErrCode = ret ? 0 : 268435471;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = Isometry3d_elm_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void MatrixXd_elm_Initialize(MatrixXd_elm* pVal)
{
    *pVal = (MatrixXd_elm) {    .nCount = 1,    .arr = 
    {
        0.00000000000000000000E+000        
    }
};
}
#endif

 
flag MatrixXd_elm_IsConstraintValid(const MatrixXd_elm* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 20);
	*pErrCode = ret ? 0 : ERR_MatrixXd_elm;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = T_Double_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag MatrixXd_elm_Encode(const MatrixXd_elm* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? MatrixXd_elm_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 20);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = T_Double_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag MatrixXd_elm_Decode(MatrixXd_elm* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 20);
	*pErrCode = ret ? 0 : 268435472;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = T_Double_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void MatrixXd_Initialize(MatrixXd* pVal)
{
    *pVal = (MatrixXd) {    .nCount = 1,    .arr = 
    {
        {    .nCount = 1,    .arr = 
            {
                0.00000000000000000000E+000        
            }
        }        
    }
};
}
#endif

 
flag MatrixXd_IsConstraintValid(const MatrixXd* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 20);
	*pErrCode = ret ? 0 : ERR_MatrixXd;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = MatrixXd_elm_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag MatrixXd_Encode(const MatrixXd* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? MatrixXd_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 20);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = MatrixXd_elm_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag MatrixXd_Decode(MatrixXd* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 20);
	*pErrCode = ret ? 0 : 268435473;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = MatrixXd_elm_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Matrix3d_elm_Initialize(Matrix3d_elm* pVal)
{
    *pVal = (Matrix3d_elm) {    .nCount = 1,    .arr = 
    {
        0.00000000000000000000E+000        
    }
};
}
#endif

 
flag Matrix3d_elm_IsConstraintValid(const Matrix3d_elm* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 3);
	*pErrCode = ret ? 0 : ERR_Matrix3d_elm;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = T_Double_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag Matrix3d_elm_Encode(const Matrix3d_elm* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? Matrix3d_elm_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 3);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = T_Double_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag Matrix3d_elm_Decode(Matrix3d_elm* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 3);
	*pErrCode = ret ? 0 : 268435474;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = T_Double_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Matrix3d_Initialize(Matrix3d* pVal)
{
    *pVal = (Matrix3d) {    .nCount = 1,    .arr = 
    {
        {    .nCount = 1,    .arr = 
            {
                0.00000000000000000000E+000        
            }
        }        
    }
};
}
#endif

 
flag Matrix3d_IsConstraintValid(const Matrix3d* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 3);
	*pErrCode = ret ? 0 : ERR_Matrix3d;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = Matrix3d_elm_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag Matrix3d_Encode(const Matrix3d* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? Matrix3d_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 3);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = Matrix3d_elm_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag Matrix3d_Decode(Matrix3d* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 3);
	*pErrCode = ret ? 0 : 268435475;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = Matrix3d_elm_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Matrix6d_elm_Initialize(Matrix6d_elm* pVal)
{
    *pVal = (Matrix6d_elm) {    .nCount = 1,    .arr = 
    {
        0.00000000000000000000E+000        
    }
};
}
#endif

 
flag Matrix6d_elm_IsConstraintValid(const Matrix6d_elm* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 6);
	*pErrCode = ret ? 0 : ERR_Matrix6d_elm;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = T_Double_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag Matrix6d_elm_Encode(const Matrix6d_elm* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? Matrix6d_elm_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 6);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = T_Double_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag Matrix6d_elm_Decode(Matrix6d_elm* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 6);
	*pErrCode = ret ? 0 : 268435476;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = T_Double_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Matrix6d_Initialize(Matrix6d* pVal)
{
    *pVal = (Matrix6d) {    .nCount = 1,    .arr = 
    {
        {    .nCount = 1,    .arr = 
            {
                0.00000000000000000000E+000        
            }
        }        
    }
};
}
#endif

 
flag Matrix6d_IsConstraintValid(const Matrix6d* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 6);
	*pErrCode = ret ? 0 : ERR_Matrix6d;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = Matrix6d_elm_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag Matrix6d_Encode(const Matrix6d* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? Matrix6d_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 6);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = Matrix6d_elm_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag Matrix6d_Decode(Matrix6d* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 6);
	*pErrCode = ret ? 0 : 268435477;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = Matrix6d_elm_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Affine3d_elm_Initialize(Affine3d_elm* pVal)
{
    *pVal = (Affine3d_elm) {    .nCount = 1,    .arr = 
    {
        0.00000000000000000000E+000        
    }
};
}
#endif

 
flag Affine3d_elm_IsConstraintValid(const Affine3d_elm* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 4);
	*pErrCode = ret ? 0 : ERR_Affine3d_elm;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = T_Double_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag Affine3d_elm_Encode(const Affine3d_elm* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? Affine3d_elm_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 4);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = T_Double_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag Affine3d_elm_Decode(Affine3d_elm* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 4);
	*pErrCode = ret ? 0 : 268435478;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = T_Double_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void Affine3d_Initialize(Affine3d* pVal)
{
    *pVal = (Affine3d) {    .nCount = 1,    .arr = 
    {
        {    .nCount = 1,    .arr = 
            {
                0.00000000000000000000E+000        
            }
        }        
    }
};
}
#endif

 
flag Affine3d_IsConstraintValid(const Affine3d* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 4);
	*pErrCode = ret ? 0 : ERR_Affine3d;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = Affine3d_elm_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag Affine3d_Encode(const Affine3d* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? Affine3d_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 4);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = Affine3d_elm_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag Affine3d_Decode(Affine3d* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 4);
	*pErrCode = ret ? 0 : 268435479;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = Affine3d_elm_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}
