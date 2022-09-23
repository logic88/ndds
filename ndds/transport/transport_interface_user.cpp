/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "DCPS/DdsDcps_pch.h" //Only the _pch include should start with DCPS/
#include "TransportRetainedElement.h"

#if !defined (__ACE_INLINE__)
#include "TransportRetainedElement.inl"
#endif /* __ACE_INLINE__ */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

NDDS::DCPS::TransportRetainedElement::~TransportRetainedElement()
{
  DBG_ENTRY_LVL("TransportRetainedElement", "~TransportRetainedElement", 6);
}

void
NDDS::DCPS::TransportRetainedElement::release_element(
  bool /* dropped_by_transport */
)
{
  DBG_ENTRY_LVL("TransportRetainedElement", "release_element", 6);
  delete this;
}

NDDS::DCPS::RepoId
NDDS::DCPS::TransportRetainedElement::publication_id() const
{
  DBG_ENTRY_LVL("TransportRetainedElement", "publication_id", 6);
  return publication_id_;
}

ACE_Message_Block*
NDDS::DCPS::TransportRetainedElement::duplicate_msg() const
{
  DBG_ENTRY_LVL("TransportRetainedElement", "duplicate_msg", 6);
  return msg_->duplicate();
}

const ACE_Message_Block*
NDDS::DCPS::TransportRetainedElement::msg() const
{
  DBG_ENTRY_LVL("TransportRetainedElement", "msg", 6);
  return msg_.get();
}

const ACE_Message_Block*
NDDS::DCPS::TransportRetainedElement::msg_payload() const
{
  DBG_ENTRY_LVL("TransportRetainedElement", "msg_payload", 6);
  return msg_->cont();
}

NDDS_END_VERSIONED_NAMESPACE_DECL
