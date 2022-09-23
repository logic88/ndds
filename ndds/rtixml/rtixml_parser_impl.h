/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_RTPS_UDP_RTPSCUSTOMIZEDELEMENT_H
#define NDDS_DCPS_TRANSPORT_RTPS_UDP_RTPSCUSTOMIZEDELEMENT_H

#include "Rtps_Udp_Export.h"

#include "dds/DCPS/transport/framework/TransportCustomizedElement.h"

#include "dds/DCPS/Dynamic_Cached_Allocator_With_Overflow_T.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Rtps_Udp_Export RtpsCustomizedElement
  : public TransportCustomizedElement {

public:

  RtpsCustomizedElement(TransportQueueElement* orig,
                        Message_Block_Ptr msg);

  SequenceNumber last_fragment() const;

private:

  virtual ~RtpsCustomizedElement();

  TqePair fragment(size_t size);
  const ACE_Message_Block* msg_payload() const;

  SequenceNumber last_frag_;
};

typedef Dynamic_Cached_Allocator_With_Overflow<ACE_Thread_Mutex>
  RtpsCustomizedElementAllocator;


} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "RtpsCustomizedElement.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_RTPSCUSTOMIZEDELEMENT_H */
