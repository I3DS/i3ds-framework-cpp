#ifndef i3ds_asn1_GENERATED_ASN1SCC_Camera_H
#define i3ds_asn1_GENERATED_ASN1SCC_Camera_H
/*
Code automatically generated by asn1scc tool
*/
#include <i3ds_asn1/asn1crt.hpp>
#include <i3ds_asn1/asn1crt_encoding.hpp>

#include <i3ds_asn1/Region.hpp>
#include <i3ds_asn1/taste-extended.hpp>
#include <i3ds_asn1/taste-types.hpp>
namespace i3ds_asn1 {

#ifdef  __cplusplus
extern "C" {
#endif


typedef T_Float SensorGain;


void SensorGain_Initialize(SensorGain* pVal);

#define i3ds_asn1_ERR_SENSORGAIN_2		10133  /**/
flag SensorGain_IsConstraintValid(const SensorGain* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_SENSORGAIN_2		10134  /**/
#define i3ds_asn1_SensorGain_REQUIRED_BYTES_FOR_ENCODING       13 
#define i3ds_asn1_SensorGain_REQUIRED_BITS_FOR_ENCODING        104

flag SensorGain_Encode(const SensorGain* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_SENSORGAIN_2		10135  /**/
flag SensorGain_Decode(SensorGain* pVal, BitStream* pBitStrm, int* pErrCode);
typedef T_UInt16 PatternSequence;


void PatternSequence_Initialize(PatternSequence* pVal);

#define i3ds_asn1_ERR_PATTERNSEQUENCE_2		10366  /**/
flag PatternSequence_IsConstraintValid(const PatternSequence* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_PATTERNSEQUENCE_2		10367  /**/
#define i3ds_asn1_PatternSequence_REQUIRED_BYTES_FOR_ENCODING       2 
#define i3ds_asn1_PatternSequence_REQUIRED_BITS_FOR_ENCODING        16

flag PatternSequence_Encode(const PatternSequence* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_PATTERNSEQUENCE_2		10368  /**/
flag PatternSequence_Decode(PatternSequence* pVal, BitStream* pBitStrm, int* pErrCode);
typedef T_UInt16 PatternID;


void PatternID_Initialize(PatternID* pVal);

#define i3ds_asn1_ERR_PATTERNID_2		10378  /**/
flag PatternID_IsConstraintValid(const PatternID* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_PATTERNID_2		10379  /**/
#define i3ds_asn1_PatternID_REQUIRED_BYTES_FOR_ENCODING       2 
#define i3ds_asn1_PatternID_REQUIRED_BITS_FOR_ENCODING        16

flag PatternID_Encode(const PatternID* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_PATTERNID_2		10380  /**/
flag PatternID_Decode(PatternID* pVal, BitStream* pBitStrm, int* pErrCode);
typedef T_UInt8 FlashStrength;


void FlashStrength_Initialize(FlashStrength* pVal);

#define i3ds_asn1_ERR_FLASHSTRENGTH_2		10239  /**/
flag FlashStrength_IsConstraintValid(const FlashStrength* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_FLASHSTRENGTH_2		10240  /**/
#define i3ds_asn1_FlashStrength_REQUIRED_BYTES_FOR_ENCODING       1 
#define i3ds_asn1_FlashStrength_REQUIRED_BITS_FOR_ENCODING        8

flag FlashStrength_Encode(const FlashStrength* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_FLASHSTRENGTH_2		10241  /**/
flag FlashStrength_Decode(FlashStrength* pVal, BitStream* pBitStrm, int* pErrCode);
typedef T_UInt32 ShutterTime;


void ShutterTime_Initialize(ShutterTime* pVal);

#define i3ds_asn1_ERR_SHUTTERTIME_2		10121  /**/
flag ShutterTime_IsConstraintValid(const ShutterTime* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_SHUTTERTIME_2		10122  /**/
#define i3ds_asn1_ShutterTime_REQUIRED_BYTES_FOR_ENCODING       4 
#define i3ds_asn1_ShutterTime_REQUIRED_BITS_FOR_ENCODING        32

flag ShutterTime_Encode(const ShutterTime* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_SHUTTERTIME_2		10123  /**/
flag ShutterTime_Decode(ShutterTime* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- CameraExposure --------------------------------------------*/
typedef struct {
    T_UInt32 shutter;
    T_Float gain;

} CameraExposure;

void CameraExposure_Initialize(CameraExposure* pVal);

#define i3ds_asn1_ERR_CAMERAEXPOSURE		10172  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAEXPOSURE_SHUTTER_2_2		10150  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAEXPOSURE_GAIN_2_2		10167  /**/
flag CameraExposure_IsConstraintValid(const CameraExposure* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_CAMERAEXPOSURE		10173  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAEXPOSURE_SHUTTER_2_2		10151  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAEXPOSURE_GAIN_2_2		10168  /**/
#define i3ds_asn1_CameraExposure_REQUIRED_BYTES_FOR_ENCODING       17 
#define i3ds_asn1_CameraExposure_REQUIRED_BITS_FOR_ENCODING        136

flag CameraExposure_Encode(const CameraExposure* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_CAMERAEXPOSURE		10174  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAEXPOSURE_SHUTTER_2_2		10152  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAEXPOSURE_GAIN_2_2		10169  /**/
flag CameraExposure_Decode(CameraExposure* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- CameraAutoExposure --------------------------------------------*/
typedef struct {
    T_Boolean enable;
    T_UInt32 max_shutter;
    T_Float max_gain;

} CameraAutoExposure;

void CameraAutoExposure_Initialize(CameraAutoExposure* pVal);

#define i3ds_asn1_ERR_CAMERAAUTOEXPOSURE		10225  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAAUTOEXPOSURE_ENABLE_2		10186  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAAUTOEXPOSURE_MAX_SHUTTER_2_2		10203  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAAUTOEXPOSURE_MAX_GAIN_2_2		10220  /**/
flag CameraAutoExposure_IsConstraintValid(const CameraAutoExposure* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_CAMERAAUTOEXPOSURE		10226  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAAUTOEXPOSURE_ENABLE_2		10187  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAAUTOEXPOSURE_MAX_SHUTTER_2_2		10204  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAAUTOEXPOSURE_MAX_GAIN_2_2		10221  /**/
#define i3ds_asn1_CameraAutoExposure_REQUIRED_BYTES_FOR_ENCODING       18 
#define i3ds_asn1_CameraAutoExposure_REQUIRED_BITS_FOR_ENCODING        137

flag CameraAutoExposure_Encode(const CameraAutoExposure* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_CAMERAAUTOEXPOSURE		10227  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAAUTOEXPOSURE_ENABLE_2		10188  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAAUTOEXPOSURE_MAX_SHUTTER_2_2		10205  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAAUTOEXPOSURE_MAX_GAIN_2_2		10222  /**/
flag CameraAutoExposure_Decode(CameraAutoExposure* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- CameraFlash --------------------------------------------*/
typedef struct {
    T_Boolean enable;
    T_UInt8 strength;

} CameraFlash;

void CameraFlash_Initialize(CameraFlash* pVal);

#define i3ds_asn1_ERR_CAMERAFLASH		10273  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAFLASH_ENABLE_2		10251  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAFLASH_STRENGTH_2_2		10268  /**/
flag CameraFlash_IsConstraintValid(const CameraFlash* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_CAMERAFLASH		10274  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAFLASH_ENABLE_2		10252  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAFLASH_STRENGTH_2_2		10269  /**/
#define i3ds_asn1_CameraFlash_REQUIRED_BYTES_FOR_ENCODING       2 
#define i3ds_asn1_CameraFlash_REQUIRED_BITS_FOR_ENCODING        9

flag CameraFlash_Encode(const CameraFlash* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_CAMERAFLASH		10275  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAFLASH_ENABLE_2		10253  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAFLASH_STRENGTH_2_2		10270  /**/
flag CameraFlash_Decode(CameraFlash* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- CameraRegion --------------------------------------------*/
typedef struct {
    T_Boolean enable;
    PlanarRegion region;

} CameraRegion;

void CameraRegion_Initialize(CameraRegion* pVal);

#define i3ds_asn1_ERR_CAMERAREGION		10352  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAREGION_ENABLE_2		10287  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAREGION_REGION_2		10347  /**/
flag CameraRegion_IsConstraintValid(const CameraRegion* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_CAMERAREGION		10353  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAREGION_ENABLE_2		10288  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAREGION_REGION_2		10348  /**/
#define i3ds_asn1_CameraRegion_REQUIRED_BYTES_FOR_ENCODING       9 
#define i3ds_asn1_CameraRegion_REQUIRED_BITS_FOR_ENCODING        65

flag CameraRegion_Encode(const CameraRegion* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_CAMERAREGION		10354  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAREGION_ENABLE_2		10289  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAREGION_REGION_2		10349  /**/
flag CameraRegion_Decode(CameraRegion* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- CameraPattern --------------------------------------------*/
typedef struct {
    T_Boolean enable;
    T_UInt16 pattern_sequence;

} CameraPattern;

void CameraPattern_Initialize(CameraPattern* pVal);

#define i3ds_asn1_ERR_CAMERAPATTERN		10412  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAPATTERN_ENABLE_2		10390  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAPATTERN_PATTERN_SEQUENCE_2_2		10407  /**/
flag CameraPattern_IsConstraintValid(const CameraPattern* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_CAMERAPATTERN		10413  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAPATTERN_ENABLE_2		10391  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAPATTERN_PATTERN_SEQUENCE_2_2		10408  /**/
#define i3ds_asn1_CameraPattern_REQUIRED_BYTES_FOR_ENCODING       3 
#define i3ds_asn1_CameraPattern_REQUIRED_BITS_FOR_ENCODING        17

flag CameraPattern_Encode(const CameraPattern* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_CAMERAPATTERN		10414  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAPATTERN_ENABLE_2		10392  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAPATTERN_PATTERN_SEQUENCE_2_2		10409  /**/
flag CameraPattern_Decode(CameraPattern* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- CameraConfiguration --------------------------------------------*/
typedef struct {
    T_UInt32 shutter;
    T_Float gain;
    T_Boolean auto_exposure_enabled;
    T_UInt32 max_shutter;
    T_Float max_gain;
    T_Boolean region_enabled;
    PlanarRegion region;
    T_Boolean flash_enabled;
    T_UInt8 flash_strength;
    T_Boolean pattern_enabled;
    T_UInt16 pattern_sequence;

} CameraConfiguration;

void CameraConfiguration_Initialize(CameraConfiguration* pVal);

#define i3ds_asn1_ERR_CAMERACONFIGURATION		10629  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_SHUTTER_2_2		10431  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_GAIN_2_2		10448  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_AUTO_EXPOSURE_ENABLED_2		10460  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_MAX_SHUTTER_2_2		10477  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_MAX_GAIN_2_2		10494  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_REGION_ENABLED_2		10506  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_REGION_2		10566  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_FLASH_ENABLED_2		10578  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_FLASH_STRENGTH_2_2		10595  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_PATTERN_ENABLED_2		10607  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_PATTERN_SEQUENCE_2_2		10624  /**/
flag CameraConfiguration_IsConstraintValid(const CameraConfiguration* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION		10630  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_SHUTTER_2_2		10432  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_GAIN_2_2		10449  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_AUTO_EXPOSURE_ENABLED_2		10461  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_MAX_SHUTTER_2_2		10478  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_MAX_GAIN_2_2		10495  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_REGION_ENABLED_2		10507  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_REGION_2		10567  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_FLASH_ENABLED_2		10579  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_FLASH_STRENGTH_2_2		10596  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_PATTERN_ENABLED_2		10608  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_PATTERN_SEQUENCE_2_2		10625  /**/
#define i3ds_asn1_CameraConfiguration_REQUIRED_BYTES_FOR_ENCODING       46 
#define i3ds_asn1_CameraConfiguration_REQUIRED_BITS_FOR_ENCODING        364

flag CameraConfiguration_Encode(const CameraConfiguration* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION		10631  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_SHUTTER_2_2		10433  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_GAIN_2_2		10450  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_AUTO_EXPOSURE_ENABLED_2		10462  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_MAX_SHUTTER_2_2		10479  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_MAX_GAIN_2_2		10496  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_REGION_ENABLED_2		10508  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_REGION_2		10568  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_FLASH_ENABLED_2		10580  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_FLASH_STRENGTH_2_2		10597  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_PATTERN_ENABLED_2		10609  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_PATTERN_SEQUENCE_2_2		10626  /**/
flag CameraConfiguration_Decode(CameraConfiguration* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

} // namespace i3ds_asn1
#endif
