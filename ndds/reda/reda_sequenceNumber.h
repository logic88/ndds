/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_UDP_UDP_H
#define NDDS_DCPS_TRANSPORT_UDP_UDP_H

#include "Udp_Export.h"
#include "dds/Versioned_Namespace.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Udp_Export UdpInitializer {
public:
  UdpInitializer();
};

static UdpInitializer udp_init;

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif  /* DCPS_UDP_H */
