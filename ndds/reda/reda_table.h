/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_UDP_UDPSENDSTRATEGY_H
#define NDDS_DCPS_TRANSPORT_UDP_UDPSENDSTRATEGY_H

#include "Udp_Export.h"

#include "dds/DCPS/transport/framework/TransportSendStrategy.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class UdpDataLink;
class UdpInst;
typedef RcHandle<UdpDataLink> UdpDataLink_rch;

class NDDS_Udp_Export UdpSendStrategy
  : public TransportSendStrategy {
public:
  UdpSendStrategy(UdpDataLink* link);

  virtual void stop_i();

protected:
  virtual ssize_t send_bytes_i(const iovec iov[], int n);

  virtual size_t max_message_size() const
  {
    return UDP_MAX_MESSAGE_SIZE;
  }

private:
  UdpDataLink* link_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* DCPS_UDPSENDSTRATEGY_H */
