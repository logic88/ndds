/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "DCPS/DdsDcps_pch.h" //Only the _pch include should start with DCPS/
#include "BuildChainVisitor.h"
#include "TransportQueueElement.h"

#if !defined (__ACE_INLINE__)
#include "BuildChainVisitor.inl"
#endif /* __ACE_INLINE__ */

NDDS::DCPS::BuildChainVisitor::~BuildChainVisitor()
{
  DBG_ENTRY_LVL("BuildChainVisitor", "~BuildChainVisitor", 6);
}

int
NDDS::DCPS::BuildChainVisitor::visit_element(TransportQueueElement* element)
{
  DBG_ENTRY_LVL("BuildChainVisitor", "visit_element", 6);

  if (head_ == 0) {
    // This is the first element that we have visited.
    head_ = element->msg()->duplicate();
    tail_ = head_;

    while (tail_->cont() != 0) {
      tail_ = tail_->cont();
    }

  } else {
    // This is not the first element that we have visited.
    tail_->cont(element->msg()->duplicate());

    while (tail_->cont() != 0) {
      tail_ = tail_->cont();
    }
  }

  // Visit entire queue.
  return 1;
}
