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


typedef T_Float SensorGain;


void SensorGain_Initialize(SensorGain* pVal);

#define i3ds_asn1_ERR_SENSORGAIN_2		10452  /**/
flag SensorGain_IsConstraintValid(const SensorGain* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_SENSORGAIN_2		10453  /**/
#define i3ds_asn1_SensorGain_REQUIRED_BYTES_FOR_ENCODING       13 
#define i3ds_asn1_SensorGain_REQUIRED_BITS_FOR_ENCODING        104

flag SensorGain_Encode(const SensorGain* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_SENSORGAIN_2		10454  /**/
flag SensorGain_Decode(SensorGain* pVal, BitStream* pBitStrm, int* pErrCode);
typedef T_UInt16 PatternSequence;


void PatternSequence_Initialize(PatternSequence* pVal);

#define i3ds_asn1_ERR_PATTERNSEQUENCE_2		10685  /**/
flag PatternSequence_IsConstraintValid(const PatternSequence* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_PATTERNSEQUENCE_2		10686  /**/
#define i3ds_asn1_PatternSequence_REQUIRED_BYTES_FOR_ENCODING       2 
#define i3ds_asn1_PatternSequence_REQUIRED_BITS_FOR_ENCODING        16

flag PatternSequence_Encode(const PatternSequence* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_PATTERNSEQUENCE_2		10687  /**/
flag PatternSequence_Decode(PatternSequence* pVal, BitStream* pBitStrm, int* pErrCode);
typedef T_UInt16 PatternID;


void PatternID_Initialize(PatternID* pVal);

#define i3ds_asn1_ERR_PATTERNID_2		10697  /**/
flag PatternID_IsConstraintValid(const PatternID* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_PATTERNID_2		10698  /**/
#define i3ds_asn1_PatternID_REQUIRED_BYTES_FOR_ENCODING       2 
#define i3ds_asn1_PatternID_REQUIRED_BITS_FOR_ENCODING        16

flag PatternID_Encode(const PatternID* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_PATTERNID_2		10699  /**/
flag PatternID_Decode(PatternID* pVal, BitStream* pBitStrm, int* pErrCode);
typedef T_UInt8 FlashStrength;


void FlashStrength_Initialize(FlashStrength* pVal);

#define i3ds_asn1_ERR_FLASHSTRENGTH_2		10558  /**/
flag FlashStrength_IsConstraintValid(const FlashStrength* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_FLASHSTRENGTH_2		10559  /**/
#define i3ds_asn1_FlashStrength_REQUIRED_BYTES_FOR_ENCODING       1 
#define i3ds_asn1_FlashStrength_REQUIRED_BITS_FOR_ENCODING        8

flag FlashStrength_Encode(const FlashStrength* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_FLASHSTRENGTH_2		10560  /**/
flag FlashStrength_Decode(FlashStrength* pVal, BitStream* pBitStrm, int* pErrCode);
typedef T_UInt32 ShutterTime;


void ShutterTime_Initialize(ShutterTime* pVal);

#define i3ds_asn1_ERR_SHUTTERTIME_2		10440  /**/
flag ShutterTime_IsConstraintValid(const ShutterTime* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_SHUTTERTIME_2		10441  /**/
#define i3ds_asn1_ShutterTime_REQUIRED_BYTES_FOR_ENCODING       4 
#define i3ds_asn1_ShutterTime_REQUIRED_BITS_FOR_ENCODING        32

flag ShutterTime_Encode(const ShutterTime* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_SHUTTERTIME_2		10442  /**/
flag ShutterTime_Decode(ShutterTime* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- CameraExposure --------------------------------------------*/
typedef struct {
    T_UInt32 shutter;
    T_Float gain;

} CameraExposure;

void CameraExposure_Initialize(CameraExposure* pVal);

#define i3ds_asn1_ERR_CAMERAEXPOSURE		10491  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAEXPOSURE_SHUTTER_2_2		10469  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAEXPOSURE_GAIN_2_2		10486  /**/
flag CameraExposure_IsConstraintValid(const CameraExposure* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_CAMERAEXPOSURE		10492  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAEXPOSURE_SHUTTER_2_2		10470  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAEXPOSURE_GAIN_2_2		10487  /**/
#define i3ds_asn1_CameraExposure_REQUIRED_BYTES_FOR_ENCODING       17 
#define i3ds_asn1_CameraExposure_REQUIRED_BITS_FOR_ENCODING        136

flag CameraExposure_Encode(const CameraExposure* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_CAMERAEXPOSURE		10493  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAEXPOSURE_SHUTTER_2_2		10471  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAEXPOSURE_GAIN_2_2		10488  /**/
flag CameraExposure_Decode(CameraExposure* pVal, BitStream* pBitStrm, int* pErrCode);
typedef T_UInt32 ImageSequence;


void ImageSequence_Initialize(ImageSequence* pVal);

#define i3ds_asn1_ERR_IMAGESEQUENCE_2		10745  /**/
flag ImageSequence_IsConstraintValid(const ImageSequence* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_IMAGESEQUENCE_2		10746  /**/
#define i3ds_asn1_ImageSequence_REQUIRED_BYTES_FOR_ENCODING       4 
#define i3ds_asn1_ImageSequence_REQUIRED_BITS_FOR_ENCODING        32

flag ImageSequence_Encode(const ImageSequence* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_IMAGESEQUENCE_2		10747  /**/
flag ImageSequence_Decode(ImageSequence* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- CameraAutoExposure --------------------------------------------*/
typedef struct {
    T_Boolean enable;
    T_UInt32 max_shutter;
    T_Float max_gain;

} CameraAutoExposure;

void CameraAutoExposure_Initialize(CameraAutoExposure* pVal);

#define i3ds_asn1_ERR_CAMERAAUTOEXPOSURE		10544  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAAUTOEXPOSURE_ENABLE_2		10505  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAAUTOEXPOSURE_MAX_SHUTTER_2_2		10522  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAAUTOEXPOSURE_MAX_GAIN_2_2		10539  /**/
flag CameraAutoExposure_IsConstraintValid(const CameraAutoExposure* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_CAMERAAUTOEXPOSURE		10545  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAAUTOEXPOSURE_ENABLE_2		10506  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAAUTOEXPOSURE_MAX_SHUTTER_2_2		10523  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAAUTOEXPOSURE_MAX_GAIN_2_2		10540  /**/
#define i3ds_asn1_CameraAutoExposure_REQUIRED_BYTES_FOR_ENCODING       18 
#define i3ds_asn1_CameraAutoExposure_REQUIRED_BITS_FOR_ENCODING        137

flag CameraAutoExposure_Encode(const CameraAutoExposure* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_CAMERAAUTOEXPOSURE		10546  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAAUTOEXPOSURE_ENABLE_2		10507  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAAUTOEXPOSURE_MAX_SHUTTER_2_2		10524  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAAUTOEXPOSURE_MAX_GAIN_2_2		10541  /**/
flag CameraAutoExposure_Decode(CameraAutoExposure* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- CameraFlash --------------------------------------------*/
typedef struct {
    T_Boolean enable;
    T_UInt8 strength;

} CameraFlash;

void CameraFlash_Initialize(CameraFlash* pVal);

#define i3ds_asn1_ERR_CAMERAFLASH		10592  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAFLASH_ENABLE_2		10570  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAFLASH_STRENGTH_2_2		10587  /**/
flag CameraFlash_IsConstraintValid(const CameraFlash* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_CAMERAFLASH		10593  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAFLASH_ENABLE_2		10571  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAFLASH_STRENGTH_2_2		10588  /**/
#define i3ds_asn1_CameraFlash_REQUIRED_BYTES_FOR_ENCODING       2 
#define i3ds_asn1_CameraFlash_REQUIRED_BITS_FOR_ENCODING        9

flag CameraFlash_Encode(const CameraFlash* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_CAMERAFLASH		10594  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAFLASH_ENABLE_2		10572  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAFLASH_STRENGTH_2_2		10589  /**/
flag CameraFlash_Decode(CameraFlash* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- CameraRegion --------------------------------------------*/
typedef struct {
    T_Boolean enable;
    PlanarRegion region;

} CameraRegion;

void CameraRegion_Initialize(CameraRegion* pVal);

#define i3ds_asn1_ERR_CAMERAREGION		10671  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAREGION_ENABLE_2		10606  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAREGION_REGION_2		10666  /**/
flag CameraRegion_IsConstraintValid(const CameraRegion* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_CAMERAREGION		10672  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAREGION_ENABLE_2		10607  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAREGION_REGION_2		10667  /**/
#define i3ds_asn1_CameraRegion_REQUIRED_BYTES_FOR_ENCODING       9 
#define i3ds_asn1_CameraRegion_REQUIRED_BITS_FOR_ENCODING        65

flag CameraRegion_Encode(const CameraRegion* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_CAMERAREGION		10673  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAREGION_ENABLE_2		10608  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAREGION_REGION_2		10668  /**/
flag CameraRegion_Decode(CameraRegion* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- CameraPattern --------------------------------------------*/
typedef struct {
    T_Boolean enable;
    T_UInt16 pattern_sequence;

} CameraPattern;

void CameraPattern_Initialize(CameraPattern* pVal);

#define i3ds_asn1_ERR_CAMERAPATTERN		10731  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAPATTERN_ENABLE_2		10709  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAPATTERN_PATTERN_SEQUENCE_2_2		10726  /**/
flag CameraPattern_IsConstraintValid(const CameraPattern* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_CAMERAPATTERN		10732  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAPATTERN_ENABLE_2		10710  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAPATTERN_PATTERN_SEQUENCE_2_2		10727  /**/
#define i3ds_asn1_CameraPattern_REQUIRED_BYTES_FOR_ENCODING       3 
#define i3ds_asn1_CameraPattern_REQUIRED_BITS_FOR_ENCODING        17

flag CameraPattern_Encode(const CameraPattern* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_CAMERAPATTERN		10733  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAPATTERN_ENABLE_2		10711  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAPATTERN_PATTERN_SEQUENCE_2_2		10728  /**/
flag CameraPattern_Decode(CameraPattern* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- CameraImgSequence --------------------------------------------*/
typedef struct {
    T_Boolean enable;
    T_UInt32 image_sequence;

} CameraImgSequence;

void CameraImgSequence_Initialize(CameraImgSequence* pVal);

#define i3ds_asn1_ERR_CAMERAIMGSEQUENCE		10779  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAIMGSEQUENCE_ENABLE_2		10757  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERAIMGSEQUENCE_IMAGE_SEQUENCE_2_2		10774  /**/
flag CameraImgSequence_IsConstraintValid(const CameraImgSequence* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_CAMERAIMGSEQUENCE		10780  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAIMGSEQUENCE_ENABLE_2		10758  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERAIMGSEQUENCE_IMAGE_SEQUENCE_2_2		10775  /**/
#define i3ds_asn1_CameraImgSequence_REQUIRED_BYTES_FOR_ENCODING       5 
#define i3ds_asn1_CameraImgSequence_REQUIRED_BITS_FOR_ENCODING        33

flag CameraImgSequence_Encode(const CameraImgSequence* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_CAMERAIMGSEQUENCE		10781  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAIMGSEQUENCE_ENABLE_2		10759  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERAIMGSEQUENCE_IMAGE_SEQUENCE_2_2		10776  /**/
flag CameraImgSequence_Decode(CameraImgSequence* pVal, BitStream* pBitStrm, int* pErrCode);
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
    T_Boolean image_sequence_enabled;
    T_UInt32 image_sequence;
    T_UInt32 image_max_sequence;

} CameraConfiguration;

void CameraConfiguration_Initialize(CameraConfiguration* pVal);

#define i3ds_asn1_ERR_CAMERACONFIGURATION		11042  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_SHUTTER_2_2		10798  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_GAIN_2_2		10815  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_AUTO_EXPOSURE_ENABLED_2		10827  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_MAX_SHUTTER_2_2		10844  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_MAX_GAIN_2_2		10861  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_REGION_ENABLED_2		10873  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_REGION_2		10933  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_FLASH_ENABLED_2		10945  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_FLASH_STRENGTH_2_2		10962  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_PATTERN_ENABLED_2		10974  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_PATTERN_SEQUENCE_2_2		10991  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_IMAGE_SEQUENCE_ENABLED_2		11003  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_IMAGE_SEQUENCE_2_2		11020  /**/
#define i3ds_asn1_i3ds_asn1_ERR_CAMERACONFIGURATION_IMAGE_MAX_SEQUENCE_2_2		11037  /**/
flag CameraConfiguration_IsConstraintValid(const CameraConfiguration* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION		11043  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_SHUTTER_2_2		10799  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_GAIN_2_2		10816  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_AUTO_EXPOSURE_ENABLED_2		10828  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_MAX_SHUTTER_2_2		10845  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_MAX_GAIN_2_2		10862  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_REGION_ENABLED_2		10874  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_REGION_2		10934  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_FLASH_ENABLED_2		10946  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_FLASH_STRENGTH_2_2		10963  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_PATTERN_ENABLED_2		10975  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_PATTERN_SEQUENCE_2_2		10992  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_IMAGE_SEQUENCE_ENABLED_2		11004  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_IMAGE_SEQUENCE_2_2		11021  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_CAMERACONFIGURATION_IMAGE_MAX_SEQUENCE_2_2		11038  /**/
#define i3ds_asn1_CameraConfiguration_REQUIRED_BYTES_FOR_ENCODING       54 
#define i3ds_asn1_CameraConfiguration_REQUIRED_BITS_FOR_ENCODING        429

flag CameraConfiguration_Encode(const CameraConfiguration* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION		11044  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_SHUTTER_2_2		10800  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_GAIN_2_2		10817  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_AUTO_EXPOSURE_ENABLED_2		10829  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_MAX_SHUTTER_2_2		10846  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_MAX_GAIN_2_2		10863  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_REGION_ENABLED_2		10875  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_REGION_2		10935  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_FLASH_ENABLED_2		10947  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_FLASH_STRENGTH_2_2		10964  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_PATTERN_ENABLED_2		10976  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_PATTERN_SEQUENCE_2_2		10993  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_IMAGE_SEQUENCE_ENABLED_2		11005  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_IMAGE_SEQUENCE_2_2		11022  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_CAMERACONFIGURATION_IMAGE_MAX_SEQUENCE_2_2		11039  /**/
flag CameraConfiguration_Decode(CameraConfiguration* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 



} // namespace i3ds_asn1
#endif
