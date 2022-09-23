/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "UdpLoader.h"
#include "UdpInst.h"

#include "dds/DCPS/transport/framework/TransportRegistry.h"
#include "dds/DCPS/transport/framework/TransportType.h"

namespace {
  const char UDP_NAME[] = "udp";
}

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class UdpType : public TransportType {
public:
  const char* name() { return UDP_NAME; }

  TransportInst_rch new_inst(const std::string& name)
  {
    return make_rch<UdpInst>(name);
  }
};

int
UdpLoader::init(int /*argc*/, ACE_TCHAR* /*argv*/[])
{
  static bool initialized(false);

  if (initialized) return 0;  // already initialized

  TransportRegistry* registry = TheTransportRegistry;
  if (!registry->register_type(make_rch<UdpType>())) {
    return 0;
  }

  TransportInst_rch default_inst =
    registry->create_inst(TransportRegistry::DEFAULT_INST_PREFIX +
                          std::string("0300_UDP"), UDP_NAME, false);
  registry->get_config(TransportRegistry::DEFAULT_CONFIG_NAME)
    ->sorted_insert(default_inst);

  initialized = true;

  return 0;
}

ACE_FACTORY_DEFINE(NDDS_Udp, UdpLoader);
ACE_STATIC_SVC_DEFINE(
  UdpLoader,
  ACE_TEXT("NDDS_Udp"),
  ACE_SVC_OBJ_T,
  &ACE_SVC_NAME(UdpLoader),
  ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
  0)

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL