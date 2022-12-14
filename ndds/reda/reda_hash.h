/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_SHMEM_SHMEMSENDSTRATEGY_H
#define NDDS_DCPS_TRANSPORT_SHMEM_SHMEMSENDSTRATEGY_H

#include "Shmem_Export.h"

#include "dds/DCPS/transport/framework/TransportSendStrategy.h"

#include "ace/OS_NS_Thread.h"

#include <string>

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class ShmemDataLink;
class ShmemInst;
struct ShmemData;
typedef RcHandle<ShmemInst> ShmemInst_rch;

class NDDS_Shmem_Export ShmemSendStrategy
  : public TransportSendStrategy {
public:
  ShmemSendStrategy(ShmemDataLink* link);

  virtual bool start_i();
  virtual void stop_i();

protected:
  virtual ssize_t send_bytes_i(const iovec iov[], int n);

private:
  ShmemDataLink* link_;
  std::string bound_name_;
  ACE_sema_t peer_semaphore_;
  ShmemData* current_data_;
  const size_t datalink_control_size_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* NDDS_SHMEMSENDSTRATEGY_H */
