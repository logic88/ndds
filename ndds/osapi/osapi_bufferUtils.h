/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_MESSAGETRACKER_H
#define NDDS_DCPS_MESSAGETRACKER_H

#include "dcps_export.h"
#include "PoolAllocator.h"
#include "TimeTypes.h"
#include "ConditionVariable.h"

#include <ace/Thread_Mutex.h>

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

  /**
   * A simple message tracker to use to wait until all messages have been
   * accounted for being continuing processing.
   */
  class NDDS_Dcps_Export MessageTracker {
  public:
    MessageTracker(const NDDS_STRING& msg_src);

    /**
     * Indicate that a message has been to the transport layer.
     */
    void message_sent();

    /**
     * Indicate that a message has been delivered by the transport layer.
     */
    void message_delivered();

    /**
     * Indicate that a message has been dropped by the transport layer.
     */
    void message_dropped();

    /**
     * Answer if there are any messages that have not been accounted for.
     */
    bool pending_messages();

    /**
     * Block until all messages have been accounted for or timeouts out based
     * on PendingTimeout.
     */
    void wait_messages_pending(const char* caller);

    /**
     * Block until all messages have been accounted for or the deadline supplied
     * has passed. Blocks indefinitely if deadline is zero.
     */
    void wait_messages_pending(const char* caller, const MonotonicTimePoint& deadline);

    /**
     * For testing.
     */
    int dropped_count();

  private:
    const NDDS_STRING msg_src_;         // Source of tracked messages
    int                  dropped_count_;
    int                  delivered_count_; // Messages transmitted by transport layer
    int                  sent_count_;      // Messages sent to transport layer

    ACE_Thread_Mutex lock_;

    /// All messages have been transported condition variable.
    typedef ConditionVariable<ACE_Thread_Mutex> ConditionVariableType;
    ConditionVariableType done_condition_;
  };

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif
