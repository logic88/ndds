/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_NETWORKCONFIGMONITOR_H
#define NDDS_DCPS_NETWORKCONFIGMONITOR_H

#include "dcps_export.h"

#include "InternalTopic.h"
#include "NetworkAddress.h"
#include "PoolAllocator.h"
#include "RcObject.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

struct NDDS_Dcps_Export NetworkInterfaceAddress {
  NetworkInterfaceAddress()
    : index(-1)
    , can_multicast(false)
  {}
  NetworkInterfaceAddress(int a_index,
                          const NDDS_STRING& a_name,
                          bool a_can_multicast,
                          const NetworkAddress& a_address)
    : index(a_index)
    , name(a_name)
    , can_multicast(a_can_multicast)
    , address(a_address)
  {}

  bool is_ipv4() const { return address.get_type() == AF_INET; }
  bool is_ipv6() const { return address.get_type() == AF_INET6; }
  bool exclude_from_multicast(const char* configured_interface) const;

  bool operator==(const NetworkInterfaceAddress& other) const
  {
    return index == other.index &&
      name == other.name &&
      can_multicast == other.can_multicast &&
      address == other.address;
  }

  bool operator!=(const NetworkInterfaceAddress& other) const
  {
    return !(*this == other);
  }

  bool operator<(const NetworkInterfaceAddress& other) const
  {
    if (name != other.name) {
      return name < other.name;
    }

    return address < other.address;
  }

  int index;
  NDDS_STRING name;
  bool can_multicast;
  NetworkAddress address;
};

struct NetworkInterfaceIndex {
  explicit NetworkInterfaceIndex(int index) : index_(index) {}

  bool operator()(const NetworkInterfaceAddress& nic) const
  {
    return index_ == nic.index;
  }

  const int index_;
};

struct NetworkInterfaceName {
  explicit NetworkInterfaceName(const NDDS_STRING& name) : name_(name) {}

  bool operator()(const NetworkInterfaceAddress& nic)
  {
    return name_ == nic.name;
  }

  const NDDS_STRING name_;
};

struct NetworkInterfaceAddressKeyEqual {
  explicit NetworkInterfaceAddressKeyEqual(const NetworkInterfaceAddress& nia)
    : nia_(nia)
  {}

  bool operator()(const NetworkInterfaceAddress& other)
  {
    return nia_.name == other.name && nia_.address == other.address;
  }

  const NetworkInterfaceAddress& nia_;
};

class NDDS_Dcps_Export NetworkConfigMonitor : public virtual RcObject {
public:
  typedef NDDS_LIST(NetworkInterfaceAddress) List;

  NetworkConfigMonitor();

  void connect(RcHandle<InternalTopic<NetworkInterfaceAddress> > topic);
  virtual bool open() = 0;
  virtual bool close() = 0;
  void disconnect(RcHandle<InternalTopic<NetworkInterfaceAddress> > topic);

 protected:
  void set(const List& list);
  void clear();

  void set(const NetworkInterfaceAddress& nia);
  void remove_interface(int index);
  void remove_interface(const NDDS_STRING& name);
  void remove_address(int index, const NetworkAddress& address);
  void remove_address(const NDDS_STRING& name, const NetworkAddress& address);

private:
  RcHandle<InternalDataWriter<NetworkInterfaceAddress> > writer_;

  List list_;

  mutable ACE_Thread_Mutex mutex_;
};

typedef RcHandle<NetworkConfigMonitor> NetworkConfigMonitor_rch;

} // DCPS
} // NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif // NDDS_DCPS_NETWORKCONFIGMONITOR_H
