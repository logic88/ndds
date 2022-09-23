/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "Multicast.h"
#include "MulticastLoader.h"

#include "ace/Service_Config.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

MulticastInitializer::MulticastInitializer()
{
  ACE_Service_Config::process_directive(ace_svc_desc_MulticastLoader);

#if (NDDS_MULTICAST_HAS_DLL == 0)
  ACE_Service_Config::process_directive(ACE_TEXT("static NDDS_Multicast"));
#endif  /* NDDS_MULTICAST_HAS_DLL */
}

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL
