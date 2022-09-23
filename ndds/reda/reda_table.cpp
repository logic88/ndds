/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "UdpSendStrategy.h"
#include "UdpDataLink.h"
#include "UdpInst.h"
#include "dds/DCPS/transport/framework/NullSynchStrategy.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

UdpSendStrategy::UdpSendStrategy(UdpDataLink* link)
  : TransportSendStrategy(0, link->impl(),
                          0,  // synch_resource
                          link->transport_priority(),
                          make_rch<NullSynchStrategy>()),
    link_(link)
{
}

ssize_t
UdpSendStrategy::send_bytes_i(const iovec iov[], int n)
{
  ACE_SOCK_Dgram& socket = this->link_->socket();
  return socket.send(iov, n, this->link_->remote_address());
}

void
UdpSendStrategy::stop_i()
{
}

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL
