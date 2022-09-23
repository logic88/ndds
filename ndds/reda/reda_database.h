/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_POOLSYNCH_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_POOLSYNCH_H

#include "dds/DCPS/dcps_export.h"
#include "ThreadSynch.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class PoolSynchStrategy;
class ThreadSynchResource;

class NDDS_Dcps_Export PoolSynch : public ThreadSynch {
public:

  PoolSynch(PoolSynchStrategy* strategy,
            ThreadSynchResource* synch_resource);
  virtual ~PoolSynch();

  virtual void work_available();

protected:

  virtual void unregister_worker_i();

private:
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "PoolSynch.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_DCPS_POOLSYNCH_H */
