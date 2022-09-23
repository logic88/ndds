/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_TCP_TCPACCEPTOR_H
#define NDDS_DCPS_TRANSPORT_TCP_TCPACCEPTOR_H

#include "TcpTransport_rch.h"
#include "TcpConnection.h"
#include "ace/Acceptor.h"
#include "ace/SOCK_Acceptor.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class TcpAcceptor : public ACE_Acceptor<TcpConnection, ACE_SOCK_ACCEPTOR> {
public:

  TcpAcceptor(RcHandle<TcpTransport> transport);
  virtual ~TcpAcceptor();

  // Returns a RcHandle which should be checked before use
  RcHandle<TcpTransport> transport();

  // This causes the Acceptor to drop its reference to the TcpTransport
  void transport_shutdown();

private:

  WeakRcHandle<TcpTransport> transport_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif  /* NDDS_TCPACCEPTOR_H */
