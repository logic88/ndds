/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_UDP_UDPINST_H
#define NDDS_DCPS_TRANSPORT_UDP_UDPINST_H

#include "Udp_Export.h"
#include "UdpTransport.h"

#include <dds/DCPS/LogAddr.h>
#include "dds/DCPS/transport/framework/TransportInst.h"
#include "dds/DCPS/SafetyProfileStreams.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Udp_Export UdpInst : public TransportInst {
public:
  ACE_INT32 send_buffer_size_;
  ACE_INT32 rcv_buffer_size_;

  virtual int load(ACE_Configuration_Heap& cf,
                   ACE_Configuration_Section_Key& sect);

  /// Diagnostic aid.
  virtual NDDS_STRING dump_to_str() const;

  bool is_reliable() const { return false; }

  virtual size_t populate_locator(NDDS::DCPS::TransportLocator& trans_info, ConnectionInfoFlags flags) const;

  NDDS_STRING local_address_string() const { return local_address_config_str_; }
  ACE_INET_Addr local_address() const { return local_address_; }
  void local_address(const ACE_INET_Addr& addr)
  {
    local_address_ = addr;
    local_address_config_str_ = LogAddr(addr).str();
  }
  void local_address(const char* str)
  {
    local_address_config_str_ = str;
    local_address_ = choose_single_coherent_address(local_address_config_str_, false);
  }
  void local_address(u_short port_number, const char* host_name)
  {
    local_address_config_str_ = host_name;
    local_address_config_str_ += ":" + to_dds_string(port_number);
    local_address_ = choose_single_coherent_address(local_address_config_str_, false);
  }
  void local_address_set_port(u_short port_number) {
    local_address_.set_port_number(port_number);
    set_port_in_addr_string(local_address_config_str_, port_number);
  }

private:
  friend class UdpType;
  friend class UdpDataLink;
  template <typename T, typename U>
  friend RcHandle<T> NDDS::DCPS::make_rch(U const&);
  explicit UdpInst(const std::string& name);

  TransportImpl_rch new_impl();

  /// The address from which to send/receive data.
  /// The default value is: none.
  ACE_INET_Addr local_address_;
  NDDS_STRING local_address_config_str_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif  /* DCPS_UDPINST_H */
