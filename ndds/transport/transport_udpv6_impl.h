/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_MULTICAST_MULTICASTRECEIVESTRATEGY_H
#define NDDS_DCPS_TRANSPORT_MULTICAST_MULTICASTRECEIVESTRATEGY_H

#include "Multicast_Export.h"

#include "dds/DCPS/RcEventHandler.h"
#include "dds/DCPS/transport/framework/TransportReceiveStrategy_T.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class MulticastDataLink;

class NDDS_Multicast_Export MulticastReceiveStrategy
  : public TransportReceiveStrategy<>,
    public RcEventHandler
{
public:
  explicit MulticastReceiveStrategy(MulticastDataLink* link);

  virtual ACE_HANDLE get_handle() const;
  virtual int handle_input(ACE_HANDLE fd);

protected:
  virtual ssize_t receive_bytes(iovec iov[],
                                int n,
                                ACE_INET_Addr& remote_address,
                                ACE_HANDLE fd,
                                bool& stop);

  virtual bool check_header(const TransportHeader& header);
  virtual bool check_header(const DataSampleHeader& header);

  virtual void deliver_sample(ReceivedDataSample& sample,
                              const ACE_INET_Addr& remote_address);

  virtual int start_i();
  virtual void stop_i();

  virtual bool reassemble(ReceivedDataSample& data);

private:
  MulticastDataLink* link_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif  /* DCPS_MULTICASTRECEIVESTRATEGY_H */
