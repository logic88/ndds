/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_TCP_TCPLOADER_H
#define NDDS_DCPS_TRANSPORT_TCP_TCPLOADER_H
#include /**/ "ace/pre.h"

#include "Tcp_export.h"

#include "ace/Service_Object.h"
#include "ace/Service_Config.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "dds/Versioned_Namespace.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Tcp_Export TcpLoader : public ACE_Service_Object {
public:

  TcpLoader();

  virtual ~TcpLoader();

  /// Initialize the loader hooks.
  virtual int init(int argc, ACE_TCHAR* argv[]);
};

ACE_STATIC_SVC_DECLARE_EXPORT(NDDS_Tcp, TcpLoader)
ACE_FACTORY_DECLARE(NDDS_Tcp, TcpLoader)

}
}

NDDS_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* TCP_LOADER_H */
