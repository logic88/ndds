/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_RECEIVELISTENERSETMAP_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_RECEIVELISTENERSETMAP_H

#include "dds/DCPS/dcps_export.h"
#include "ReceiveListenerSet.h"
#include "ReceiveListenerSet_rch.h"
#include "dds/DCPS/Definitions.h"
#include "dds/DCPS/PoolAllocator.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class ReceivedDataSample;

class NDDS_Dcps_Export ReceiveListenerSetMap {
public:

  typedef NDDS_MAP_CMP(RepoId, ReceiveListenerSet_rch, GUID_tKeyLessThan) MapType;

  ReceiveListenerSetMap();
  virtual ~ReceiveListenerSetMap();

  int insert(RepoId                              publisher_id,
             RepoId                              subscriber_id,
             const TransportReceiveListener_wrch& receive_listener);

  ReceiveListenerSet_rch find(RepoId publisher_id) const;

  int remove(RepoId publisher_id, RepoId subscriber_id);

  /// This method is called when the (remote) subscriber is being
  /// released.  This method will return a 0 if the subscriber_id is
  /// successfully disassociated with the publisher_id *and* there
  /// are still other subscribers associated with the publisher_id.
  /// This method will return 1 if, after the disassociation, the
  /// publisher_id is no longer associated with any subscribers (which
  /// also means it's element was removed from our map_).
  int release_subscriber(RepoId publisher_id, RepoId subscriber_id);

  ReceiveListenerSet_rch remove_set(RepoId publisher_id);

  ssize_t size() const;

  /// Give access to the underlying map for iteration purposes.
  MapType& map();
  const MapType& map() const;

  void operator= (const ReceiveListenerSetMap& rh);

  void clear();

private:

  ReceiveListenerSet_rch find_or_create(RepoId publisher_id);

  MapType map_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ReceiveListenerSetMap.inl"
#endif /* __ACE_INLINE__ */

#endif /* NDDS_DCPS_RECEIVELISTENERSETMAP_H */
