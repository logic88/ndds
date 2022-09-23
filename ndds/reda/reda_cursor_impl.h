/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_PERCONNECTIONSYNCHSTRATEGY_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_PERCONNECTIONSYNCHSTRATEGY_H

#include "dds/DCPS/dcps_export.h"
#include "ThreadSynchStrategy.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Dcps_Export PerConnectionSynchStrategy : public ThreadSynchStrategy {
public:

  PerConnectionSynchStrategy();
  virtual ~PerConnectionSynchStrategy();

  virtual ThreadSynch* create_synch_object(
    ThreadSynchResource* synch_resource,
    long                 priority,
    int                  scheduler);
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "PerConnectionSynchStrategy.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_DCPS_PERCONNECTIONSYNCHSTRATEGY_H */
