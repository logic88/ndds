/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_REMOVEALLVISITOR_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_REMOVEALLVISITOR_H

#include "dds/DCPS/dcps_export.h"
#include "BasicQueueVisitor_T.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class TransportQueueElement;

class NDDS_Dcps_Export RemoveAllVisitor : public BasicQueueVisitor<TransportQueueElement> {
public:

  RemoveAllVisitor();

  virtual ~RemoveAllVisitor();

  /// The BasicQueue<T>::accept_remove_visitor() method will call
  /// this visit_element_remove() method for each element in the queue.
  virtual int visit_element_remove(TransportQueueElement* element,
                                   int&                   remove);

  /// Accessor for the status.  Called after this visitor object has
  /// been passed to BasicQueue<T>::accept_remove_visitor().
  int status() const;

  int removed_bytes() const;

private:

  /// Holds the status of our visit.
  int status_;

  size_t removed_bytes_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "RemoveAllVisitor.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_DCPS_REMOVEALLVISITOR_H */
