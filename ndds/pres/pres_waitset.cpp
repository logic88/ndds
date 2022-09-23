/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "Shmem.h"
#include "ShmemLoader.h"

#include "ace/Service_Config.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

ShmemInitializer::ShmemInitializer()
{
  ACE_Service_Config::process_directive(ace_svc_desc_ShmemLoader);

#if (NDDS_SHMEM_HAS_DLL == 0)
  ACE_Service_Config::process_directive(ACE_TEXT("static NDDS_Shmem"));
#endif  /* NDDS_SHMEM_HAS_DLL */
}

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL
