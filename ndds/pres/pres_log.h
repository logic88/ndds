/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_THREADPERCONREMOVEVISITOR_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_THREADPERCONREMOVEVISITOR_H

#include "dds/DCPS/dcps_export.h"
#include "BasicQueueVisitor_T.h"
#include "TransportDefs.h"
#include "ThreadPerConnectionSendTask.h"
#include "ace/Message_Block.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Dcps_Export ThreadPerConRemoveVisitor
  : public BasicQueueVisitor<SendRequest> {
public:

  /// In order to construct a QueueRemoveVisitor, it must be
  /// provided with the DataSampleElement* (used as an
  /// identifier) that should be removed from the BasicQueue<T>
  /// (the one this visitor will visit when it is passed-in
  /// to a BasicQueue<T>::accept_remove_visitor() invocation).
  explicit ThreadPerConRemoveVisitor(const ACE_Message_Block* sample);

  virtual ~ThreadPerConRemoveVisitor();

  /// The BasicQueue<T>::accept_remove_visitor() method will call
  /// this visit_element_remove() method for each element in the queue.
  virtual int visit_element_remove(SendRequest*           element,
                                   int&                   remove);

  /// True if the visitor found and removed the sample.
  RemoveResult status() const;

private:

  /// The sample that needs to be removed.
  const ACE_Message_Block* sample_;

  /// Holds the status of our visit.
  RemoveResult status_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ThreadPerConRemoveVisitor.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_DCPS_THREADPERCONREMOVEVISITOR_H */
