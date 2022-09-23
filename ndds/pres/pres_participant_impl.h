/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_THREADSYNCHRESOURCE_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_THREADSYNCHRESOURCE_H

#include "dds/DCPS/dcps_export.h"
#include "dds/DCPS/TimeTypes.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Dcps_Export ThreadSynchResource {
public:

  virtual ~ThreadSynchResource();

  virtual int wait_to_unclog();
  void set_handle(ACE_HANDLE handle);

protected:

  virtual void notify_lost_on_backpressure_timeout() = 0;

  ThreadSynchResource();
  ACE_HANDLE handle_;
  TimeDuration* timeout_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ThreadSynchResource.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_DCPS_THREADSYNCHRESOURCE_H */
