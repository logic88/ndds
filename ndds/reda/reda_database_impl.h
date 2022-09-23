/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_POOLSYNCHSTRATEGY_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_POOLSYNCHSTRATEGY_H

#include "ThreadSynchStrategy.h"

#include <dds/DCPS/dcps_export.h>
#include <dds/DCPS/ConditionVariable.h>

#include <ace/Synch_Traits.h>
#include <ace/Task.h>

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Dcps_Export PoolSynchStrategy : public ACE_Task_Base,
      public ThreadSynchStrategy {
public:

  PoolSynchStrategy();
  virtual ~PoolSynchStrategy();

  virtual ThreadSynch* create_synch_object(
    ThreadSynchResource* synch_resource,
    long                 priority,
    int                  scheduler);

  virtual int open(void*);
  virtual int svc();
  virtual int close(u_long);

  void operator delete (void* ptr) { ThreadSynchStrategy::operator delete(ptr); }
private:

  typedef ACE_SYNCH_MUTEX LockType;
  typedef ACE_Guard<LockType> GuardType;
  typedef ConditionVariable<LockType> ConditionVariableType;

  LockType      lock_;
  ConditionVariableType condition_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "PoolSynchStrategy.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_DCPS_POOLSYNCHSTRATEGY_H */
