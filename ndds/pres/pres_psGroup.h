/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_THREADSYNCHSTRATEGY_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_THREADSYNCHSTRATEGY_H

#include "dds/DCPS/dcps_export.h"
#include "dds/DCPS/RcObject.h"
#include "ace/Synch_Traits.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class ThreadSynch;
class ThreadSynchResource;

//MJM: Some class documentation here would be extremely helpful.
class NDDS_Dcps_Export ThreadSynchStrategy
  : public RcObject
{
public:

  virtual ~ThreadSynchStrategy();

  virtual ThreadSynch* create_synch_object(
    ThreadSynchResource* synch_resource,
    long                 priority,
    int                  scheduler) = 0;

protected:

  ThreadSynchStrategy();
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ThreadSynchStrategy.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_DCPS_THREADSYNCHSTRATEGY_H */
