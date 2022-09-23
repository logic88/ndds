/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "RtpsUdp.h"
#include "RtpsUdpLoader.h"

#include "ace/Service_Config.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

RtpsUdpInitializer::RtpsUdpInitializer()
{
  ACE_Service_Config::process_directive(ace_svc_desc_RtpsUdpLoader);

#if (NDDS_RTPS_UDP_HAS_DLL == 0)
  ACE_Service_Config::process_directive(ACE_TEXT("static NDDS_Rtps_Udp"));
#endif  /* NDDS_RTPS_UDP_HAS_DLL */
}

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL
