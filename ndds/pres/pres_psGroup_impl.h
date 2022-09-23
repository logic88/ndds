/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_THREADSYNCHWORKER_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_THREADSYNCHWORKER_H

#include "dds/DCPS/dcps_export.h"
#include "dds/DCPS/RcObject.h"
#include "dds/DCPS/RcHandle_T.h"
#include "ace/Synch_Traits.h"
#include <cstddef>

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Dcps_Export ThreadSynchWorker
  : public RcObject {
public:

  virtual ~ThreadSynchWorker();

  enum WorkOutcome {
    WORK_OUTCOME_MORE_TO_DO,
    WORK_OUTCOME_NO_MORE_TO_DO,
    WORK_OUTCOME_CLOGGED_RESOURCE,
    WORK_OUTCOME_BROKEN_RESOURCE
  };

  virtual WorkOutcome perform_work() = 0;

  /// Indicate that queued data is available to be sent.
  virtual void schedule_output();

  /// DataLink reference value for diagnostics.
  std::size_t id() const;

  virtual ACE_HANDLE get_handle()=0;

protected:

  ThreadSynchWorker( std::size_t id = 0);

private:
  std::size_t id_;
};

typedef RcHandle<ThreadSynchWorker> ThreadSynchWorker_rch;

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ThreadSynchWorker.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_DCPS_THREADSYNCHWORKER_H */
