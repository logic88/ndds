/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "Tcp_pch.h"

#include "TcpLoader.h"
#include "TcpInst.h"
#include "dds/DCPS/transport/framework/TransportRegistry.h"
#include "dds/DCPS/transport/framework/TransportType.h"
#include "dds/DCPS/transport/framework/EntryExit.h"

#include "tao/debug.h"
#include "ace/OS_NS_strings.h"

namespace {
  const char TCP_NAME[] = "tcp";
}

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

TcpLoader::TcpLoader()
{
  DBG_ENTRY_LVL("TcpLoader", "TcpLoader", 6);
}

TcpLoader::~TcpLoader()
{
  DBG_ENTRY_LVL("TcpLoader", "~TcpLoader", 6);
}

class TcpType : public TransportType {
public:
  const char* name() { return TCP_NAME; }

  TransportInst_rch new_inst(const std::string& name)
  {
    return make_rch<TcpInst>(name);
  }
};

int
TcpLoader::init(int, ACE_TCHAR*[])
{
  DBG_ENTRY_LVL("TcpLoader", "init", 6);

  static bool initialized = false;

  // Only allow initialization once.
  if (initialized)
    return 0;

  TransportRegistry* registry = TheTransportRegistry;
  if (!registry->register_type(make_rch<TcpType>())) {
    return 0;
  }

  TransportInst_rch default_inst =
    registry->create_inst(TransportRegistry::DEFAULT_INST_PREFIX +
                          std::string("0500_TCP"), TCP_NAME, false);
  registry->get_config(TransportRegistry::DEFAULT_CONFIG_NAME)
    ->sorted_insert(default_inst);

  initialized = true;
  return 0;
}

/////////////////////////////////////////////////////////////////////

ACE_FACTORY_DEFINE(NDDS_Tcp, TcpLoader)
ACE_STATIC_SVC_DEFINE(TcpLoader,
                      ACE_TEXT("NDDS_Tcp"),
                      ACE_SVC_OBJ_T,
                      &ACE_SVC_NAME(TcpLoader),
                      ACE_Service_Type::DELETE_THIS
                      | ACE_Service_Type::DELETE_OBJ,
                      0)
}
}

NDDS_END_VERSIONED_NAMESPACE_DECL
