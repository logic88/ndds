/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_RTPS_UDP_RTPSUDP_H
#define NDDS_DCPS_TRANSPORT_RTPS_UDP_RTPSUDP_H

#include "Rtps_Udp_Export.h"
#include "dds/Versioned_Namespace.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Rtps_Udp_Export RtpsUdpInitializer {
public:
  RtpsUdpInitializer();
};

static RtpsUdpInitializer rtps_udp_init;

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif  /* DCPS_UDP_H */
