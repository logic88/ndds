/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_JOB_QUEUE_H
#define NDDS_DCPS_JOB_QUEUE_H

#include "RcEventHandler.h"
#include "PoolAllocator.h"
#include "dcps_export.h"

#include <ace/Reactor.h>
#include <ace/Thread_Mutex.h>
#include <ace/Reverse_Lock_T.h>

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Dcps_Export JobQueue : public virtual RcEventHandler {
public:
  class Job : public virtual RcObject {
  public:
    virtual ~Job() { }
    virtual void execute() = 0;
  };
  typedef RcHandle<Job> JobPtr;

  explicit JobQueue(ACE_Reactor* reactor);

  void enqueue(JobPtr job)
  {
    ACE_GUARD(ACE_Thread_Mutex, guard, mutex_);
    const bool empty = job_queue_.empty();
    job_queue_.push_back(job);
    if (empty) {
      guard.release();
      reactor()->notify(this);
    }
  }

private:
  ACE_Thread_Mutex mutex_;
  typedef NDDS_VECTOR(JobPtr) Queue;
  Queue job_queue_;

  int handle_exception(ACE_HANDLE /*fd*/);
};

typedef RcHandle<JobQueue> JobQueue_rch;
typedef WeakRcHandle<JobQueue> JobQueue_wrch;

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* NDDS_DCPS_JOB_QUEUE_H  */
