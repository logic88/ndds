/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_SHMEM_SHMEMINST_H
#define NDDS_DCPS_TRANSPORT_SHMEM_SHMEMINST_H

#include "Shmem_Export.h"
#include "ShmemTransport.h"

#include "dds/DCPS/transport/framework/TransportInst.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Shmem_Export ShmemInst : public TransportInst {
public:

  virtual int load(ACE_Configuration_Heap& cf,
                   ACE_Configuration_Section_Key& sect);

  virtual NDDS_STRING dump_to_str() const;

  /// Size (in bytes) of the single shared-memory pool allocated by this
  /// transport instance.  Defaults to 16 megabytes.
  size_t pool_size_;

  /// Size (in bytes) of the control area allocated for each data link.
  /// This allocation comes out of the shared-memory pool defined by pool_size_.
  /// Defaults to 4 kilobytes.
  size_t datalink_control_size_;

  bool is_reliable() const { return true; }

  virtual size_t populate_locator(NDDS::DCPS::TransportLocator& trans_info, ConnectionInfoFlags flags) const;

  const std::string& hostname() const { return hostname_; }
  const std::string& poolname() const { return poolname_; }

private:
  friend class ShmemType;
  template <typename T, typename U>
  friend RcHandle<T> NDDS::DCPS::make_rch(U const&);
  explicit ShmemInst(const std::string& name);

  TransportImpl_rch new_impl();
  std::string hostname_;
  std::string poolname_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif  /* NDDS_SHMEMINST_H */
