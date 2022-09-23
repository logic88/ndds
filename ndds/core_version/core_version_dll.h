/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_SECURITY_FRAMEWORK_SECURITYPLUGININST_RCH_H
#define NDDS_DCPS_SECURITY_FRAMEWORK_SECURITYPLUGININST_RCH_H

#include "dds/DCPS/RcHandle_T.h"
#include "SecurityPluginInst.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace Security {

typedef DCPS::RcHandle<SecurityPluginInst> SecurityPluginInst_rch;

} // namespace Security
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif
