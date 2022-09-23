/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_SCHEDULEOUTPUTHANDLER_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_SCHEDULEOUTPUTHANDLER_H

#include <ace/Reactor.h>
#include <ace/Event_Handler.h>
#include "dds/DCPS/PoolAllocationBase.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS { namespace DCPS {

class TransportSendStrategy;

/**
 * @class ScheduleOutputHandler
 *
 * @brief event handler used to enable and disable output processing.
 *
 * This class implements a simple notification handler that is used to
 * schedule or cancel output processing for queued data according to the
 * current mode state of the TransportSendStrategy.  If the send strategy
 * is queueing data, then the reactor is enabled to process on output
 * events.  Otherwise the output processing callbacks are cancelled.
 */
class ScheduleOutputHandler : public ACE_Event_Handler, public PoolAllocationBase {
  public:
    /// Construct with the reactor and strategy.
    ScheduleOutputHandler( TransportSendStrategy* strategy,
                           ACE_Reactor* reactor);

    /// @{ @name ACE_Event_Handler methods

    /// modify the reactor mask for the handle.
    virtual int handle_exception( ACE_HANDLE);

    /// @}

    /// Update output processing in the reactor.
    void schedule_output();

  private:
    /// Strategy sending data to be scheduled (or not).
    TransportSendStrategy* strategy_;

    /// Cache the state that we have set the reactor into.
    enum HandlerState { Disabled, Enabled };
    HandlerState state_;
};

}} // End of namespace NDDS::DCPS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ScheduleOutputHandler.inl"
#endif /* __ACE_INLINE__ */

#endif /* NDDS_SCHEDULEOUTPUTHANDER_H */
