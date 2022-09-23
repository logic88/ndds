/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_TCP_TCP_H
#define NDDS_DCPS_TRANSPORT_TCP_TCP_H

#include /**/ "ace/pre.h"

#include "Tcp_export.h"
#include "ace/Service_Object.h"
#include "ace/Service_Config.h"
#include "dds/Versioned_Namespace.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Tcp_Export Tcp_Initializer {
public:
  // Constructor.
  Tcp_Initializer();
};

static Tcp_Initializer tcp_initializer;

}
}

NDDS_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* NDDS_TCP_H */
