#ifndef NDDS_DCPS_LOGADDR_H
#define NDDS_DCPS_LOGADDR_H

#include "dcps_export.h"
#include "PoolAllocator.h"
#include "NetworkAddress.h"

#include <dds/Versioned_Namespace.h>

#include <ace/INET_Addr.h>

#include <cstddef>

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Dcps_Export LogAddr {
public:
  enum Option {Ip, Port, Host, IpPort, HostPort, IpPortHost};

  static const size_t BufSize;
  static const String ip(const ACE_INET_Addr& addr);
  static const String port(const ACE_INET_Addr& addr);
  static const String host(const ACE_INET_Addr& addr);

  explicit LogAddr(const ACE_INET_Addr& addr, Option opt = IpPort);
  explicit LogAddr(const NetworkAddress& addr, Option opt = IpPort);

  const String& str() const { return addr_; }
  const char* c_str() const { return addr_.c_str(); }

private:
  void init_addr(const ACE_INET_Addr& addr, Option opt);

  String addr_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif // NDDS_DCPS_LOGADDR_H
