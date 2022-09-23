/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_QUEUEREMOVEVISITOR_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_QUEUEREMOVEVISITOR_H

#include "dds/DCPS/dcps_export.h"
#include "dds/DCPS/GuidUtils.h"
#include "BasicQueueVisitor_T.h"
#include "TransportDefs.h"
#include "TransportQueueElement.h"

#include "ace/Message_Block.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class TransportQueueElement;

class NDDS_Dcps_Export QueueRemoveVisitor
  : public BasicQueueVisitor<TransportQueueElement> {
public:

  explicit QueueRemoveVisitor(const TransportQueueElement::MatchCriteria& mc, bool remove_all = false);

  virtual ~QueueRemoveVisitor();

  /// The BasicQueue<T>::accept_remove_visitor() method will call
  /// this visit_element_remove() method for each element in the queue.
  virtual int visit_element_remove(TransportQueueElement* element,
                                   int&                   remove);

  /// Accessor for the status.  Called after this visitor object has
  /// been passed to BasicQueue<T>::accept_remove_visitor().
  RemoveResult status() const;

  int removed_bytes() const;

private:

  /// Criteria object describing the Queue Element that needs to be removed.
  const TransportQueueElement::MatchCriteria& mc_;

  /// Holds the status of our visit.
  RemoveResult status_;

  size_t removed_bytes_;

  bool remove_all_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "QueueRemoveVisitor.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_DCPS_QUEUEREMOVEVISITOR_H */
