/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_COPYCHAINVISITOR_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_COPYCHAINVISITOR_H

#include "dds/DCPS/dcps_export.h"
#include "BasicQueue_T.h"
#include "TransportRetainedElement.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Message_Block;
ACE_END_VERSIONED_NAMESPACE_DECL

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class TransportQueueElement;

class NDDS_Dcps_Export CopyChainVisitor : public BasicQueueVisitor<TransportQueueElement> {
public:

  CopyChainVisitor(
    BasicQueue<TransportQueueElement>& target,
    MessageBlockAllocator*             mb_allocator,
    DataBlockAllocator*                db_allocator,
    bool duplicate = false
  );

  virtual ~CopyChainVisitor();

  virtual int visit_element(TransportQueueElement* element);

  /// Access the status.
  int status() const;

private:
  /// Target queue to fill with copied elements.
  BasicQueue<TransportQueueElement>& target_;

  /// Allocator to create copied elements.
  MessageBlockAllocator* mb_allocator_;
  DataBlockAllocator* db_allocator_;

  /// Status of visitation.
  int status_;
  bool duplicate_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "CopyChainVisitor.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_DCPS_COPYCHAINVISTOR_H */
