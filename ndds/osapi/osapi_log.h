/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_NETWORKCONFIGMODIFIER_H
#define NDDS_DCPS_NETWORKCONFIGMODIFIER_H

#include "ace/config.h"

// ACE_HAS_GETIFADDRS is not set on android but is available in API >= 24
#if ((!defined (ACE_LINUX) && defined(ACE_HAS_GETIFADDRS))  || (defined(ACE_ANDROID) && !defined ACE_LACKS_IF_NAMEINDEX)) && !defined(NDDS_SAFETY_PROFILE)

#define NDDS_NETWORK_CONFIG_MODIFIER

#include "NetworkConfigMonitor.h"
#include "dcps_export.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Dcps_Export NetworkConfigModifier : public NetworkConfigMonitor {
public:
  bool open();
  bool close();
  void update_interfaces();
};
typedef RcHandle<NetworkConfigModifier> NetworkConfigModifier_rch;

} // DCPS
} // NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif // ACE_HAS_GETIFADDRS && ! NDDS_SAFETY_PROFILE

#endif // NDDS_DCPS_NETWORKCONFIGMODIFIER_H
