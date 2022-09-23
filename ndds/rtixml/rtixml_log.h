/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_RTPS_UDP_RTPSTRANSPORTHEADER_H
#define NDDS_DCPS_TRANSPORT_RTPS_UDP_RTPSTRANSPORTHEADER_H

#include "dds/DCPS/Definitions.h"
#include "dds/DCPS/SequenceNumber.h"
#include "dds/DCPS/RTPS/RtpsCoreC.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Message_Block;
ACE_END_VERSIONED_NAMESPACE_DECL

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

/// Adapt the TransportReceiveStrategy for RTPS's "transport" (message) Header
struct RtpsTransportHeader {

  static size_t get_max_serialized_size();

  RtpsTransportHeader();
  explicit RtpsTransportHeader(ACE_Message_Block& mb);
  RtpsTransportHeader& operator=(ACE_Message_Block& mb);

  bool valid() const;

  bool last_fragment();
  void last_fragment(bool frag);
  const SequenceNumber& sequence();

  void init(ACE_Message_Block& mb);
  void incomplete(ACE_Message_Block& mb);

  size_t length_;
  NDDS::RTPS::Header header_;
  bool valid_;
};

}
}

NDDS_END_VERSIONED_NAMESPACE_DECL

#ifdef __ACE_INLINE__
#include "RtpsTransportHeader.inl"
#endif

#endif
