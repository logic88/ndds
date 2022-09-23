/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_MULTICAST_BESTEFFORTSESSIONFACTORY_H
#define NDDS_DCPS_TRANSPORT_MULTICAST_BESTEFFORTSESSIONFACTORY_H

#include "Multicast_Export.h"

#include "MulticastSessionFactory.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Reactor;
ACE_END_VERSIONED_NAMESPACE_DECL

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Multicast_Export BestEffortSessionFactory
  : public MulticastSessionFactory {
public:
  virtual int requires_send_buffer() const;

  virtual MulticastSession_rch create(RcHandle<ReactorInterceptor> interceptor,
                                      MulticastDataLink* link,
                                      MulticastPeer remote_peer);
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif  /* DCPS_BESTEFFORTSESSIONFACTORY_H */
