#ifndef i3ds_asn1_ASN1SCC_ASN1CRT_ENCODING_UPER_H_
#define i3ds_asn1_ASN1SCC_ASN1CRT_ENCODING_UPER_H_

#include <i3ds_asn1/asn1crt_encoding.hpp>

namespace i3ds_asn1 {
#ifdef  __cplusplus
extern "C" {
#endif


void ObjectIdentifier_uper_encode(BitStream* pBitStrm, const Asn1ObjectIdentifier *pVal);
flag ObjectIdentifier_uper_decode(BitStream* pBitStrm, Asn1ObjectIdentifier *pVal);
void RelativeOID_uper_encode(BitStream* pBitStrm, const Asn1ObjectIdentifier *pVal);
flag RelativeOID_uper_decode(BitStream* pBitStrm, Asn1ObjectIdentifier *pVal);



#ifdef  __cplusplus
}
#endif


} // namespace i3ds_asn1
#endif