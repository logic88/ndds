/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_TCP_TCPSYNCHRESOURCE_H
#define NDDS_DCPS_TRANSPORT_TCP_TCPSYNCHRESOURCE_H

#include "TcpConnection_rch.h"
#include "TcpConnection.h"
#include "dds/DCPS/transport/framework/ThreadSynchResource.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class TcpDataLink;

class TcpSynchResource : public ThreadSynchResource {
public:

  TcpSynchResource(TcpDataLink& link,
                   const int& max_output_pause_period_ms);
  virtual ~TcpSynchResource();

  virtual void notify_lost_on_backpressure_timeout();

private:

  TcpDataLink& link_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif  /* NDDS_TCPSYNCHRESOURCE_H */
