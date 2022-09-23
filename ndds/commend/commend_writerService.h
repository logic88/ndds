/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_SECURITY_BUILTINPLUGINLOADER_H
#define NDDS_DCPS_SECURITY_BUILTINPLUGINLOADER_H

#include "NDDS_Security_Export.h"

#include <dds/Versioned_Namespace.h>

#include <ace/Global_Macros.h>
#include <ace/Service_Config.h>
#include <ace/Service_Object.h>

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace Security {

class BuiltInSecurityPluginInst;

class NDDS_Security_Export BuiltInPluginLoader : public ACE_Service_Object
{
public:
  virtual int init(int argc, ACE_TCHAR* argv[]);
};

ACE_STATIC_SVC_DECLARE_EXPORT(NDDS_Security, BuiltInPluginLoader)
ACE_FACTORY_DECLARE(NDDS_Security, BuiltInPluginLoader)

} // namespace Security
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif  /* NDDS_SEC_BUILTIN_PLUGIN_LOADER_H */
