/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "RtpsTransportHeader.h"

#include "dds/DCPS/Serializer.h"
#include "dds/DCPS/RTPS/BaseMessageTypes.h"
#include "dds/DCPS/RTPS/RtpsCoreTypeSupportImpl.h"

#ifndef __ACE_INLINE__
#include "RtpsTransportHeader.inl"
#endif

namespace {
  const NDDS::DCPS::SequenceNumber dummy;
}

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

void
RtpsTransportHeader::init(ACE_Message_Block& mb)
{
  // Byte order doesn't matter for RTPS::Header, since it's
  // exclusively structs/arrays of octet.
  Serializer ser(&mb, Encoding::KIND_XCDR1);
  valid_ = (ser >> header_);

  if (valid_) {

    // length_ started as the total number of bytes in the datagram's payload.
    // When we return to the TransportReceiveStrategy it must be the number
    // of bytes remaining after processing this RTPS::Header.
    length_ -= get_max_serialized_size();

    // RTPS spec v2.1 section 8.3.6.3
    valid_ = std::equal(header_.prefix, header_.prefix + sizeof(header_.prefix),
                        RTPS::PROTOCOL_RTPS);
    valid_ &= (header_.version.major == NDDS::RTPS::PROTOCOLVERSION.major);
  }
}

const SequenceNumber&
RtpsTransportHeader::sequence()
{
  return dummy;
}

}
}

NDDS_END_VERSIONED_NAMESPACE_DECL
