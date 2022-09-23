/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "MulticastLoader.h"
#include "MulticastInst.h"

#include "dds/DCPS/transport/framework/TransportRegistry.h"
#include "dds/DCPS/transport/framework/TransportType.h"

namespace {
  const char MULTICAST_NAME[] = "multicast";
}

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class MulticastType : public TransportType {
public:
  const char* name() { return MULTICAST_NAME; }

  TransportInst_rch new_inst(const std::string& name)
  {
    return make_rch<MulticastInst>(name);
  }
};

int
MulticastLoader::init(int /*argc*/, ACE_TCHAR* /*argv*/[])
{
  static bool initialized(false);

  if (initialized) return 0;  // already initialized

  TransportRegistry* registry = TheTransportRegistry;
  if (!registry->register_type(make_rch<MulticastType>())) {
    return 0;
  }

  TransportConfig_rch cfg =
    registry->get_config(TransportRegistry::DEFAULT_CONFIG_NAME);

  TransportInst_rch default_unrel =
    registry->create_inst(TransportRegistry::DEFAULT_INST_PREFIX
                          + std::string("0410_MCAST_UNRELIABLE"),
                          MULTICAST_NAME, false);
  MulticastInst* mi = dynamic_cast<MulticastInst*>(default_unrel.in());
  if (!mi) {
    ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("(%P|%t) MulticastLoader::init:")
      ACE_TEXT(" failed to obtain MulticastInst.\n")), -1);
  }
  mi->reliable_ = false;
  cfg->sorted_insert(default_unrel);

  TransportInst_rch default_rel =
    registry->create_inst(TransportRegistry::DEFAULT_INST_PREFIX
                          + std::string("0420_MCAST_RELIABLE"), MULTICAST_NAME, false);
  cfg->sorted_insert(default_rel);

  initialized = true;

  return 0;
}

ACE_FACTORY_DEFINE(NDDS_Multicast, MulticastLoader)
ACE_STATIC_SVC_DEFINE(
  MulticastLoader,
  ACE_TEXT("NDDS_Multicast"),
  ACE_SVC_OBJ_T,
  &ACE_SVC_NAME(MulticastLoader),
  ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
  0)

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL
