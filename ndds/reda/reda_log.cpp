/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "Tcp_pch.h"
#include "Tcp.h"
#include "TcpLoader.h"
#include "tao/debug.h"
#include "ace/Dynamic_Service.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

Tcp_Initializer::Tcp_Initializer()
{
  ACE_Service_Config::process_directive(ace_svc_desc_TcpLoader);

#if NDDS_TCP_HAS_DLL == 0
  ACE_Service_Config::process_directive(ACE_TEXT("static NDDS_Tcp"));
#endif
}

}
}

NDDS_END_VERSIONED_NAMESPACE_DECL
