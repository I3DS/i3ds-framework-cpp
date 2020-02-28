#ifndef i3ds_asn1_GENERATED_ASN1SCC_Frame_H
#define i3ds_asn1_GENERATED_ASN1SCC_Frame_H
/*
Code automatically generated by asn1scc tool
*/
#include <i3ds_asn1/asn1crt.hpp>
#include <i3ds_asn1/asn1crt_encoding.hpp>

#include <i3ds_asn1/Region.hpp>
#include <i3ds_asn1/taste-types.hpp>
#include <i3ds_asn1/SampleAttribute.hpp>
#include <i3ds_asn1/taste-extended.hpp>

namespace i3ds_asn1 {


typedef enum {
    mode_undefined = 0,
    mode_mono = 1,
    mode_rgb = 2,
    mode_bgr = 3,
    mode_uyvy = 4,
    mode_rgba = 5,
    mode_bayer_rggb = 6,
    mode_bayer_grbg = 7,
    mode_bayer_bggr = 8,
    mode_bayer_gbrg = 9,
    mode_pjpg = 10,
    mode_jpeg = 11,
    mode_png = 12,
    mode_tiff = 13
} Frame_mode_t;

// please use the following macros to avoid breaking code.
#define i3ds_asn1_Frame_mode_t_mode_undefined mode_undefined
#define i3ds_asn1_Frame_mode_t_mode_mono mode_mono
#define i3ds_asn1_Frame_mode_t_mode_rgb mode_rgb
#define i3ds_asn1_Frame_mode_t_mode_bgr mode_bgr
#define i3ds_asn1_Frame_mode_t_mode_uyvy mode_uyvy
#define i3ds_asn1_i3ds_asn1_Frame_mode_t_mode_rgba mode_rgba
#define i3ds_asn1_Frame_mode_t_mode_bayer_rggb mode_bayer_rggb
#define i3ds_asn1_Frame_mode_t_mode_bayer_grbg mode_bayer_grbg
#define i3ds_asn1_Frame_mode_t_mode_bayer_bggr mode_bayer_bggr
#define i3ds_asn1_Frame_mode_t_mode_bayer_gbrg mode_bayer_gbrg
#define i3ds_asn1_Frame_mode_t_mode_pjpg mode_pjpg
#define i3ds_asn1_Frame_mode_t_mode_jpeg mode_jpeg
#define i3ds_asn1_Frame_mode_t_mode_png mode_png
#define i3ds_asn1_Frame_mode_t_mode_tiff mode_tiff

void Frame_mode_t_Initialize(Frame_mode_t* pVal);

#define i3ds_asn1_ERR_FRAME_MODE_T		10636  /**/
flag Frame_mode_t_IsConstraintValid(const Frame_mode_t* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_FRAME_MODE_T		10637  /**/
#define i3ds_asn1_Frame_mode_t_REQUIRED_BYTES_FOR_ENCODING       1 
#define i3ds_asn1_Frame_mode_t_REQUIRED_BITS_FOR_ENCODING        4

flag Frame_mode_t_Encode(const Frame_mode_t* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_FRAME_MODE_T		10638  /**/
flag Frame_mode_t_Decode(Frame_mode_t* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- FrameDescriptor --------------------------------------------*/
typedef struct {
    SampleAttributes attributes;
    Frame_mode_t frame_mode;
    T_UInt8 data_depth;
    T_UInt8 pixel_size;
    PlanarRegion region;
    T_UInt8 image_count;

} FrameDescriptor;

void FrameDescriptor_Initialize(FrameDescriptor* pVal);

#define i3ds_asn1_ERR_FRAMEDESCRIPTOR		10883  /**/
#define i3ds_asn1_i3ds_asn1_ERR_FRAMEDESCRIPTOR_ATTRIBUTES_2		10770  /**/
#define i3ds_asn1_i3ds_asn1_ERR_FRAMEDESCRIPTOR_FRAME_MODE_2		10782  /**/
#define i3ds_asn1_i3ds_asn1_ERR_FRAMEDESCRIPTOR_DATA_DEPTH_2		10794  /**/
#define i3ds_asn1_i3ds_asn1_ERR_FRAMEDESCRIPTOR_PIXEL_SIZE_2		10806  /**/
#define i3ds_asn1_i3ds_asn1_ERR_FRAMEDESCRIPTOR_REGION_2		10866  /**/
#define i3ds_asn1_i3ds_asn1_ERR_FRAMEDESCRIPTOR_IMAGE_COUNT_2		10878  /**/
flag FrameDescriptor_IsConstraintValid(const FrameDescriptor* pVal, int* pErrCode);

#define i3ds_asn1_ERR_UPER_ENCODE_FRAMEDESCRIPTOR		10884  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_FRAMEDESCRIPTOR_ATTRIBUTES_2		10771  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_FRAMEDESCRIPTOR_FRAME_MODE_2		10783  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_FRAMEDESCRIPTOR_DATA_DEPTH_2		10795  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_FRAMEDESCRIPTOR_PIXEL_SIZE_2		10807  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_FRAMEDESCRIPTOR_REGION_2		10867  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_ENCODE_FRAMEDESCRIPTOR_IMAGE_COUNT_2		10879  /**/
#define i3ds_asn1_FrameDescriptor_REQUIRED_BYTES_FOR_ENCODING       78 
#define i3ds_asn1_FrameDescriptor_REQUIRED_BITS_FOR_ENCODING        617

flag FrameDescriptor_Encode(const FrameDescriptor* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define i3ds_asn1_ERR_UPER_DECODE_FRAMEDESCRIPTOR		10885  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_FRAMEDESCRIPTOR_ATTRIBUTES_2		10772  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_FRAMEDESCRIPTOR_FRAME_MODE_2		10784  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_FRAMEDESCRIPTOR_DATA_DEPTH_2		10796  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_FRAMEDESCRIPTOR_PIXEL_SIZE_2		10808  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_FRAMEDESCRIPTOR_REGION_2		10868  /**/
#define i3ds_asn1_i3ds_asn1_ERR_UPER_DECODE_FRAMEDESCRIPTOR_IMAGE_COUNT_2		10880  /**/
flag FrameDescriptor_Decode(FrameDescriptor* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 



} // namespace i3ds_asn1
#endif