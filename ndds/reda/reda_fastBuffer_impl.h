/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_SHMEM_SHMEMRECEIVESTRATEGY_H
#define NDDS_DCPS_TRANSPORT_SHMEM_SHMEMRECEIVESTRATEGY_H

#include "Shmem_Export.h"

#include "ace/INET_Addr.h"

#include "dds/DCPS/transport/framework/TransportReceiveStrategy_T.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class ShmemDataLink;
struct ShmemData;

class NDDS_Shmem_Export ShmemReceiveStrategy
  : public TransportReceiveStrategy<> {
public:
  explicit ShmemReceiveStrategy(ShmemDataLink* link);

  void read();

protected:
  virtual ssize_t receive_bytes(iovec iov[],
                                int n,
                                ACE_INET_Addr& remote_address,
                                ACE_HANDLE fd,
                                bool& stop);

  virtual void deliver_sample(ReceivedDataSample& sample,
                              const ACE_INET_Addr& remote_address);

  virtual int start_i();
  virtual void stop_i();

private:
  ShmemDataLink* link_;
  std::string bound_name_;
  ShmemData* current_data_;
  size_t partial_recv_remaining_;
  const char* partial_recv_ptr_;
  ACE_Thread_Mutex mutex_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif  /* NDDS_SHMEMRECEIVESTRATEGY_H */
