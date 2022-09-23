/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TIME_SOURCE_H
#define NDDS_DCPS_TIME_SOURCE_H

#include "TimeTypes.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class TimeSource {
public:
  virtual ~TimeSource() {}

  virtual MonotonicTimePoint monotonic_time_point_now() const {
    return MonotonicTimePoint::now();
  }

};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* NDDS_DCPS_TIME_SOURCE_H */
