/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_REACTORSYNCHSTRATEGY_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_REACTORSYNCHSTRATEGY_H

#include "dds/DCPS/dcps_export.h"
#include "ThreadSynchStrategy.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Reactor;
ACE_END_VERSIONED_NAMESPACE_DECL

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS { namespace DCPS {

class TransportSendStrategy;

/**
 * @class ReactorSynchStrategy
 *
 * @brief strategy to construct ReactorSynch implementations of ThreadSynch.
 *
 * This class is used as a factory for ReactorSynch objects that can be
 * used to scheduled queued output for processing on a reactor.  The
 * initial implementation will share the Transport reactor for all of the
 * sending and receiving processing to be performed.  If the reactor is
 * upgraded to a thread pool reactor, then this processing can be split
 * between those threads using the default leader-follower dispatching.
 *
 * The usage idiom for ThreadSynchStrategy ensures that his object will
 * have valid raw pointer values during its lifetime.
 */
class NDDS_Dcps_Export ReactorSynchStrategy : public ThreadSynchStrategy {
public:

  /// Construct with strategy, reactor, and handle to configure the
  /// ReactorSynch with.
  ReactorSynchStrategy( TransportSendStrategy* strategy,
                        ACE_Reactor* reactor);

  virtual ~ReactorSynchStrategy();

  virtual ThreadSynch* create_synch_object(
    ThreadSynchResource* synch_resource,
    long                 priority = 0,
    int                  scheduler = 0);

  private:
    /// Raw pointer to the strategy.  This is the strategy that contains
    /// the TreadSynch (which will receive this pointer) so the lifetime
    /// is assured.
    TransportSendStrategy* strategy_;

    /// Raw pointer to reactor.  This is ok since the strategy will pass
    /// the pointer on to the ReactorSynch, which is guaranteed to span
    /// the lifetime of both the strategy and the reactor.
    ACE_Reactor* reactor_;
};

}} // end namespace NDDS::DCPS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ReactorSynchStrategy.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_DCPS_REACTORSYNCHSTRATEGY_H */
