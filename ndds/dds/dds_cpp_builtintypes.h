/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_RTPS_LOGGING_H
#define NDDS_DCPS_RTPS_LOGGING_H

#include "rtps_export.h"

#include "RtpsCoreTypeSupportImpl.h"

#include <dds/Versioned_Namespace.h>

#include <dds/DCPS/GuidUtils.h>

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace RTPS {

/// Log a serialized RTPS message.
NDDS_Rtps_Export
void log_message(const char* format,
                 const DCPS::GuidPrefix_t& prefix,
                 bool send,
                 const Message& message);

NDDS_Rtps_Export
void parse_submessages(Message& message,
                       const ACE_Message_Block& mb);

} // namespace RTPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* NDDS_DCPS_RTPS_LOGGING_H */
