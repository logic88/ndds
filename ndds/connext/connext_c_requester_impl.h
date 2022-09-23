/*
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_SECURITY_UTILITYIMPL_H
#define NDDS_DCPS_SECURITY_UTILITYIMPL_H

#include "NDDS_Security_Export.h"
#include "Utility.h"

#include <dds/Versioned_Namespace.h>

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace Security {

class NDDS_Security_Export UtilityImpl
  : public virtual NDDS::Security::Utility {
public:
  virtual ~UtilityImpl();
  virtual void generate_random_bytes(void* ptr, size_t size);
  virtual void hmac(void* out, void const* in, size_t size, const std::string& password) const;
};

} // Security
} // NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif
