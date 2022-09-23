/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_PERCONNECTIONSYNCH_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_PERCONNECTIONSYNCH_H

#include "ThreadSynch.h"

#include <dds/DCPS/ConditionVariable.h>

#include <ace/Synch_Traits.h>
#include <ace/Task.h>

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class PerConnectionSynch : public ACE_Task_Base,
      public ThreadSynch {
public:

  PerConnectionSynch(ThreadSynchResource* synch_resource, long priority, int scheduler);
  virtual ~PerConnectionSynch();

  virtual void work_available();

  virtual int open(void*);
  virtual int svc();
  virtual int close(u_long);

  NDDS_POOL_ALLOCATION_FWD

protected:

  virtual int register_worker_i();
  virtual void unregister_worker_i();

private:

  typedef ACE_SYNCH_MUTEX LockType;
  typedef ACE_Guard<LockType> GuardType;
  typedef ConditionVariable<LockType> ConditionVariableType;

  LockType lock_;
  ConditionVariableType condition_;
  int work_available_;
  int shutdown_;
  long dds_priority_;
  long scheduler_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "PerConnectionSynch.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_DCPS_THREADSYNCH_H */
