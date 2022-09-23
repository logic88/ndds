/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_LOGGING_H
#define NDDS_DCPS_LOGGING_H

#include "dcps_export.h"

#include "TimeTypes.h"

#include "GuidUtils.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

extern void NDDS_Dcps_Export log_progress(const char* activity,
                                             const GUID_t& local,
                                             const GUID_t& remote,
                                             const MonotonicTime_t& start_time,
                                             const GUID_t& reference = GUID_UNKNOWN);

} // namespace NDDS
} // namespace DCPS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* NDDS_DCPS_LOGGING_H */
