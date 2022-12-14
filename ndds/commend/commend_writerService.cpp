/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "BuiltInPluginLoader.h"

#include "BuiltInSecurityPluginInst.h"
#include "framework/SecurityConfig.h"
#include "framework/SecurityRegistry.h"

#include <dds/DCPS/RcHandle_T.h>

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace Security {

int
BuiltInPluginLoader::init(int /*argc*/, ACE_TCHAR* /*argv*/[])
{
  const NDDS_STRING PLUGIN_NAME("BuiltIn");
  SecurityPluginInst_rch plugin = TheSecurityRegistry->get_plugin_inst(
    PLUGIN_NAME, false /* don't attempt to load the plugin */);
  if (!plugin) {
    plugin = DCPS::make_rch<BuiltInSecurityPluginInst>();
    TheSecurityRegistry->register_plugin(PLUGIN_NAME, plugin);
  }

  SecurityConfig_rch default_config =
    TheSecurityRegistry->create_config(SecurityRegistry::DEFAULT_CONFIG_NAME,
                                       plugin);

  if (TheSecurityRegistry->has_no_configs()) {
    TheSecurityRegistry->default_config(default_config);
  }

  TheSecurityRegistry->builtin_config(default_config);

  return 0;
}

ACE_FACTORY_DEFINE(NDDS_Security, BuiltInPluginLoader);
ACE_STATIC_SVC_DEFINE(
  BuiltInPluginLoader,
  ACE_TEXT("NDDS_Security"),
  ACE_SVC_OBJ_T,
  &ACE_SVC_NAME(BuiltInPluginLoader),
  ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
  0)

} // namespace Security
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL
