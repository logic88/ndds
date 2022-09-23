/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_TCP_TCPRECEIVESTRATEGY_H
#define NDDS_DCPS_TRANSPORT_TCP_TCPRECEIVESTRATEGY_H

#include "TcpConnection_rch.h"
#include "TcpDataLink_rch.h"
#include "dds/DCPS/transport/framework/TransportReceiveStrategy_T.h"
#include "dds/DCPS/ReactorTask_rch.h"
#include "dds/DCPS/RcEventHandler.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class TcpConnection;

class TcpReceiveStrategy
  : public TransportReceiveStrategy<>,
    public RcEventHandler
{
public:

  TcpReceiveStrategy(TcpDataLink& link,
                     const ReactorTask_rch& task);

  virtual ~TcpReceiveStrategy();

  int reset(TcpConnection* old_connection, TcpConnection* new_connection);

  ACE_Reactor* get_reactor();

  bool gracefully_disconnected();

protected:

  virtual ssize_t receive_bytes(iovec iov[],
                                int   n,
                                ACE_INET_Addr& remote_address,
                                ACE_HANDLE fd,
                                bool& stop);

  virtual void deliver_sample(ReceivedDataSample& sample,
                              const ACE_INET_Addr& remote_address);

  virtual int start_i();
  virtual void stop_i();

  // Delegate to the connection object to re-establishment
  // the connection.
  virtual void relink(bool do_suspend = true);

private:

  TcpDataLink& link_;
  ReactorTask_rch reactor_task_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "TcpReceiveStrategy.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_TCPRECEIVESTRATEGY_H */
