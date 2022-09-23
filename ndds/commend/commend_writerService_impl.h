/*
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_SECURITY_BUILTINPLUGINS_H
#define NDDS_DCPS_SECURITY_BUILTINPLUGINS_H

#include "NDDS_Security_Export.h"

#include <dds/Versioned_Namespace.h>

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace Security {

class NDDS_Security_Export BuiltinPluginsInitializer {
public:
  BuiltinPluginsInitializer();
};

static BuiltinPluginsInitializer builtin_plugins_init;

}
}

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif
