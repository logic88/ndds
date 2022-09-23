/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_TRANSPORTREPLACEDELEMENT_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_TRANSPORTREPLACEDELEMENT_H

#include "dds/DCPS/dcps_export.h"
#include "TransportQueueElement.h"
#include "dds/DCPS/Message_Block_Ptr.h"
#include "ace/Synch_Traits.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Dcps_Export TransportReplacedElement
  : public TransportQueueElement {
public:

  TransportReplacedElement(TransportQueueElement* orig_elem,
                           MessageBlockAllocator* mb_allocator = 0,
                           DataBlockAllocator* db_allocator = 0);
  virtual ~TransportReplacedElement();

  /// Accessor for the publisher id.
  virtual RepoId publication_id() const;

  virtual ACE_Message_Block* duplicate_msg() const;

  /// Accessor for the ACE_Message_Block
  virtual const ACE_Message_Block* msg() const;

  virtual const ACE_Message_Block* msg_payload() const;

  virtual bool owned_by_transport();

  virtual bool is_retained_replaced() const;

protected:

  virtual void release_element(bool dropped_by_transport);

private:
  /// Cached allocator for DataSampleHeader message block
  MessageBlockAllocator* mb_allocator_;
  /// Cached allocator for DataSampleHeader data block
  DataBlockAllocator* db_allocator_;

  /// The publication_id() from the original TransportQueueElement
  RepoId publisher_id_;

  /// A deep-copy of the msg() from the original TransportQueueElement.
  Message_Block_Ptr msg_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "TransportReplacedElement.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_DCPS_TRANSPORTREPLACEDELEMENT_H */
