/*
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_MULTICAST_MANAGER_H
#define NDDS_DCPS_MULTICAST_MANAGER_H

#include "dcps_export.h"

#include "NetworkConfigMonitor.h"

#include <ace/SOCK_Dgram_Mcast.h>

#ifndef ACE_LACKS_PRAGMA_ONCE
#  pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Dcps_Export MulticastManager {
public:
  /// Returns true if at least one group was joined.
  bool process(InternalDataReader<NetworkInterfaceAddress>::SampleSequence& samples,
               InternalSampleInfoSequence& infos,
               const NDDS_STRING& multicast_interface,
               ACE_Reactor* reactor,
               ACE_Event_Handler* event_handler,
               const NetworkAddress& multicast_group_address,
               ACE_SOCK_Dgram_Mcast& multicast_socket
               #ifdef ACE_HAS_IPV6
               , const NetworkAddress& ipv6_multicast_group_address,
               ACE_SOCK_Dgram_Mcast& ipv6_multicast_socket
               #endif
               );
private:
  NDDS_SET(NDDS_STRING) joined_interfaces_;
#ifdef ACE_HAS_IPV6
  NDDS_SET(NDDS_STRING) ipv6_joined_interfaces_;
#endif
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif // NDDS_DCPS_MULTICAST_MANAGER_H
