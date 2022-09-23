/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_NULLSYNCH_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_NULLSYNCH_H

#include "dds/DCPS/dcps_export.h"
#include "ThreadSynch.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Dcps_Export NullSynch : public ThreadSynch {
public:

  NullSynch(ThreadSynchResource* resource);
  virtual ~NullSynch();

  virtual void work_available();
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "NullSynch.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_DCPS_NULLSYNCH_H */
