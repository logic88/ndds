/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_LINUXNETWORKCONFIGMONITOR_H
#define NDDS_DCPS_LINUXNETWORKCONFIGMONITOR_H

#include "ace/config.h"

#if (defined(ACE_LINUX) || defined(ACE_ANDROID)) && !defined(NDDS_SAFETY_PROFILE)

#define NDDS_LINUX_NETWORK_CONFIG_MONITOR

#include "NetworkConfigMonitor.h"
#include "RcEventHandler.h"
#include "ReactorInterceptor.h"
#include "dcps_export.h"

#include <ace/SOCK_Netlink.h>

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Dcps_Export LinuxNetworkConfigMonitor
  : public virtual RcEventHandler
  , public virtual NetworkConfigMonitor {
public:
  explicit LinuxNetworkConfigMonitor(ReactorInterceptor_rch interceptor);
  bool open();
  bool close();

private:
  class RegisterHandler : public ReactorInterceptor::Command {
  public:
    RegisterHandler(LinuxNetworkConfigMonitor* lncm)
      : lncm_(lncm)
    {}

  private:
    void execute()
    {
      if (reactor()->register_handler(lncm_, READ_MASK) != 0) {
        ACE_ERROR((LM_ERROR, ACE_TEXT("(%P|%t) ERROR: LinuxNetworkConfigMonitor::open: could not register for input: %m\n")));
      }
    }

    LinuxNetworkConfigMonitor* lncm_;
  };

  class RemoveHandler : public ReactorInterceptor::Command {
  public:
    RemoveHandler(LinuxNetworkConfigMonitor* lncm)
      : lncm_(lncm)
    {}

    void execute()
    {
      reactor()->remove_handler(lncm_, READ_MASK);
    }

    LinuxNetworkConfigMonitor* lncm_;
  };

  ACE_HANDLE get_handle() const;
  int handle_input(ACE_HANDLE);
  void read_messages();
  void process_message(const nlmsghdr* header);

  ACE_SOCK_Netlink socket_;
  ReactorInterceptor_wrch interceptor_;

  struct NetworkInterface {
    NDDS_STRING name;
    bool can_multicast;

    NetworkInterface() {}
    NetworkInterface(const NDDS_STRING& a_name,
                     bool a_can_multicast)
    : name(a_name)
    , can_multicast(a_can_multicast)
    {}
  };

  typedef NDDS_MAP(int, NetworkInterface) NetworkInterfaceMap;
  NetworkInterfaceMap network_interface_map_;
};

} // DCPS
} // NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif // ACE_LINUX || ACE_ANDROID

#endif // NDDS_DCPS_LINUXNETWORKCONFIGPUBLISHER_H
