/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "ShmemInst.h"
#include "ShmemLoader.h"

#include <dds/DCPS/NetworkResource.h>

#include <ace/Configuration.h>
#include <ace/OS_NS_unistd.h>

#include <iostream>
#include <sstream>

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

ShmemInst::ShmemInst(const std::string& name)
  : TransportInst("shmem", name)
  , pool_size_(16 * 1024 * 1024)
  , datalink_control_size_(4 * 1024)
  , hostname_(get_fully_qualified_hostname())
{
  std::ostringstream pool;
  pool << "NDDS-" << ACE_OS::getpid() << '-' << this->name();
  poolname_ = pool.str();

}

TransportImpl_rch
ShmemInst::new_impl()
{
  return make_rch<ShmemTransport>(ref(*this));
}

int
ShmemInst::load(ACE_Configuration_Heap& cf,
                ACE_Configuration_Section_Key& sect)
{
  TransportInst::load(cf, sect);

  std::string host_name;
  GET_CONFIG_STRING_VALUE(cf, sect, ACE_TEXT("host_name"), host_name);

  if (!host_name.empty()) {
    hostname_ = host_name;
  }

  GET_CONFIG_VALUE(cf, sect, ACE_TEXT("pool_size"), pool_size_, size_t)
  GET_CONFIG_VALUE(cf, sect, ACE_TEXT("datalink_control_size"),
                   datalink_control_size_, size_t)
  return 0;
}

NDDS_STRING
ShmemInst::dump_to_str() const
{
  std::ostringstream os;
  os << TransportInst::dump_to_str();
  os << formatNameForDump("pool_size") << pool_size_ << "\n"
     << formatNameForDump("datalink_control_size") << datalink_control_size_ << "\n"
     << formatNameForDump("pool_name") << this->poolname_ << "\n"
     << formatNameForDump("host_name") << this->hostname_
     << std::endl;
  return NDDS_STRING(os.str());
}

size_t
ShmemInst::populate_locator(NDDS::DCPS::TransportLocator& info, ConnectionInfoFlags) const
{
  info.transport_type = "shmem";

  const size_t len = hostname_.size() + 1 /* null */ + poolname_.size();
  info.data.length(static_cast<CORBA::ULong>(len));

  CORBA::Octet* buff = info.data.get_buffer();
  std::memcpy(buff, hostname_.c_str(), hostname_.size());
  buff += hostname_.size();

  *(buff++) = 0;
  std::memcpy(buff, poolname_.c_str(), poolname_.size());

  return 1;
}

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL
