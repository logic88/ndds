/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_UDP_UDPLOADER_H
#define NDDS_DCPS_TRANSPORT_UDP_UDPLOADER_H

#include "Udp_Export.h"

#include "ace/Global_Macros.h"
#include "ace/Service_Config.h"
#include "ace/Service_Object.h"
#include "dds/Versioned_Namespace.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Udp_Export UdpLoader
  : public ACE_Service_Object {
public:
  virtual int init(int argc, ACE_TCHAR* argv[]);
};

ACE_STATIC_SVC_DECLARE_EXPORT(NDDS_Udp, UdpLoader)
ACE_FACTORY_DECLARE(NDDS_Udp, UdpLoader)

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif  /* DCPS_UDPLOADER_H */
