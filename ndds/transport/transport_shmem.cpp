/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "BestEffortSessionFactory.h"
#include "BestEffortSession.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

int
BestEffortSessionFactory::requires_send_buffer() const
{
  return 0;
}

MulticastSession_rch
BestEffortSessionFactory::create(RcHandle<ReactorInterceptor> interceptor,
                                 MulticastDataLink* link,
                                 MulticastPeer remote_peer)
{
  return make_rch<BestEffortSession>(interceptor, link, remote_peer);
}

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL
