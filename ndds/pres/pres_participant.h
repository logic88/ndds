/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_THREADSYNCH_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_THREADSYNCH_H

#include "dds/DCPS/dcps_export.h"
#include "ThreadSynchWorker.h"
#include "dds/DCPS/PoolAllocationBase.h"
#include "dds/DCPS/unique_ptr.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class ThreadSynchResource;

/**
 * This class is the base class for different ThreadSynch stratege, currently
 * only the thread per connection strategy is implemented and used.
 *
 * Notes for object ownership:
 * 1) Pointer to TransportSendStrategy object (as ThreadSynchWorker) directly but not
 *    reference counted. It won't have access problem during it lifetime because the
 *    TransportSendStrategy object owns this ThreadSynch object.
 * 2) The ThreadSynch object is created by the ThreadSynchResource object and it owns
 *    the ThreadSynchResource object.
 */
class NDDS_Dcps_Export ThreadSynch : public PoolAllocationBase {
public:

  virtual ~ThreadSynch();

  /// The worker must introduce himself to this ThreadSynch object.
  /// It is the worker object that "owns" this ThreadSynch object.
  /// Returns 0 for success, -1 for failure.
  int register_worker(ThreadSynchWorker& worker);

  /// Our owner, the worker_, is breaking our relationship.
  void unregister_worker();

  /// The ThreadSynchWorker would like to have its perform_work() called
  /// from the appropriate thread once the ThreadSynchResource claims
  /// that it is_ready_for_work().
  virtual void work_available() = 0;

protected:

  // This ThreadSynch object takes ownership of the resource.
  ThreadSynch(ThreadSynchResource* resource);

  int wait_on_clogged_resource();

  /// The default implementation is to do nothing here.  The
  /// subclass may override the implementation in order to do
  /// something when the worker registers.
  /// Returns 0 for success, -1 for failure.
  virtual int register_worker_i();

  /// The default implementation is to do nothing here.  The
  /// subclass may override the implementation in order to do
  /// something when the worker unregisters.
  virtual void unregister_worker_i();

  /// Access the worker implementation directly.
  WeakRcHandle<ThreadSynchWorker> worker();

private:
  WeakRcHandle<ThreadSynchWorker> worker_;
  unique_ptr<ThreadSynchResource> resource_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ThreadSynch.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_DCPS_THREADSYNCH_H */
