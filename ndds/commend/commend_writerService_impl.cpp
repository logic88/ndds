/*
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "BuiltInPlugins.h"

#include "BuiltInPluginLoader.h"

#include <ace/Service_Config.h>

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace Security {

BuiltinPluginsInitializer::BuiltinPluginsInitializer()
{
  ACE_Service_Config::process_directive(ace_svc_desc_BuiltInPluginLoader);

#if (NDDS_SECURITY_HAS_DLL == 0)
  ACE_Service_Config::process_directive(ACE_TEXT("static NDDS_Security"));
#endif

  NDDS::Security::BuiltInPluginLoader().init(0, 0);
}

}
}

NDDS_END_VERSIONED_NAMESPACE_DECL
