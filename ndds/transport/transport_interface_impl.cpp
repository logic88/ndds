/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "DCPS/DdsDcps_pch.h" //Only the _pch include should start with DCPS/
#include "TransportReplacedElement.h"

#if !defined (__ACE_INLINE__)
#include "TransportReplacedElement.inl"
#endif /* __ACE_INLINE__ */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

NDDS::DCPS::TransportReplacedElement::~TransportReplacedElement()
{
  DBG_ENTRY_LVL("TransportReplacedElement", "~TransportReplacedElement", 6);
}

void
NDDS::DCPS::TransportReplacedElement::release_element(bool dropped_by_transport)
{
  ACE_UNUSED_ARG(dropped_by_transport);
  DBG_ENTRY_LVL("TransportReplacedElement", "release_element", 6);


  delete this;
}

NDDS_END_VERSIONED_NAMESPACE_DECL
