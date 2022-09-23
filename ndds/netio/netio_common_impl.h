/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_INSTANCEHANDLE_H
#define NDDS_DCPS_INSTANCEHANDLE_H

#ifdef ACE_HAS_CPP11
#  include <atomic>
#else
#  include <ace/Atomic_Op_T.h>
#  include <ace/Thread_Mutex.h>
#endif /* ACE_HAS_CPP11 */

#include "dds/DdsDcpsInfrastructureC.h"

#include "dcps_export.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

const DDS::InstanceHandle_t HANDLE_UNKNOWN(0);

class NDDS_Dcps_Export InstanceHandleGenerator {
public:
  explicit InstanceHandleGenerator(long begin = HANDLE_UNKNOWN);

  ~InstanceHandleGenerator();

  DDS::InstanceHandle_t next();

private:
#ifdef ACE_HAS_CPP11
  std::atomic<int32_t> sequence_;
#else
  ACE_Atomic_Op<ACE_Thread_Mutex, long> sequence_;
#endif
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* DCPS_INSTANCEHANDLE_H */
