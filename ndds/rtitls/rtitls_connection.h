/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_BUILDCHAINVISITOR_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_BUILDCHAINVISITOR_H

#include "dds/DCPS/dcps_export.h"
#include "BasicQueueVisitor_T.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Message_Block;
ACE_END_VERSIONED_NAMESPACE_DECL

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class TransportQueueElement;

class NDDS_Dcps_Export BuildChainVisitor : public BasicQueueVisitor<TransportQueueElement> {
public:

  BuildChainVisitor();
  virtual ~BuildChainVisitor();

  virtual int visit_element(TransportQueueElement* element);

  /// Accessor to extract the chain, leaving the head_ and tail_
  /// set to 0 as a result.
  ACE_Message_Block* chain();

private:

  ACE_Message_Block* head_;
  ACE_Message_Block* tail_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "BuildChainVisitor.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_DCPS_BUILDCHAINVISTOR_H */
