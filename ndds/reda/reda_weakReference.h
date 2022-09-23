/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_RTPS_UDP_RTPSUDPLOADER_H
#define NDDS_DCPS_TRANSPORT_RTPS_UDP_RTPSUDPLOADER_H

#include "Rtps_Udp_Export.h"

#include "ace/Global_Macros.h"
#include "ace/Service_Config.h"
#include "ace/Service_Object.h"
#include "dds/Versioned_Namespace.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Rtps_Udp_Export RtpsUdpLoader
  : public ACE_Service_Object {
public:
  virtual int init(int argc, ACE_TCHAR* argv[]);

  static void load();
};

ACE_STATIC_SVC_DECLARE_EXPORT(NDDS_Rtps_Udp, RtpsUdpLoader)
ACE_FACTORY_DECLARE(NDDS_Rtps_Udp, RtpsUdpLoader)

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif  /* DCPS_RTPSUDPLOADER_H */
