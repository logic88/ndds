/**
 * \file
 * See https://opendds.readthedocs.io/en/master/internal/dev_guidelines.html#time
 * (or docs/internal/dev_guidelines.rst) for background and reasoning for these
 * types.
 */

#ifndef NDDS_DCPS_TIMETYPES_H
#define NDDS_DCPS_TIMETYPES_H

#include "TimeDuration.h"
#include "TimePoint_T.h"

#include <ace/Monotonic_Time_Policy.h>
#include <ace/Time_Policy.h>

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

/**
 * ACE_Time_Policy that NDDS uses to define the system clock for external
 * interactions.
 */
///@{
typedef ACE_System_Time_Policy SystemClock;
typedef TimePoint_T<SystemClock> SystemTimePoint;
///@}

/**
 * ACE_Time_Policy that NDDS uses for internal timing.
 *
 * ACE_Monotonic_Time_Policy protects NDDS from being effected by changes to
 * the system clock to a certain degree.
 */
///@{
#if defined(ACE_HAS_MONOTONIC_TIME_POLICY) && defined(ACE_HAS_MONOTONIC_CONDITIONS)
#  define NDDS_USES_MONOTONIC_TIME
#endif

#ifdef NDDS_USES_MONOTONIC_TIME
typedef ACE_Monotonic_Time_Policy MonotonicClock;
#else
typedef SystemClock MonotonicClock;
#endif
typedef TimePoint_T<MonotonicClock> MonotonicTimePoint;
///@}

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif
