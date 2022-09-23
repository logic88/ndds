/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "DCPS/DdsDcps_pch.h" //Only the _pch include should start with DCPS/
#include "PerConnectionSynchStrategy.h"
#include "PerConnectionSynch.h"

#if !defined (__ACE_INLINE__)
#include "PerConnectionSynchStrategy.inl"
#endif /* __ACE_INLINE__ */

NDDS::DCPS::PerConnectionSynchStrategy::~PerConnectionSynchStrategy()
{
  DBG_ENTRY_LVL("PerConnectionSynchStrategy","~PerConnectionSynchStrategy",6);
}

NDDS::DCPS::ThreadSynch*
NDDS::DCPS::PerConnectionSynchStrategy::create_synch_object(
  ThreadSynchResource* synch_resource,
  long                 priority,
  int                  scheduler)
{
  DBG_ENTRY_LVL("PerConnectionSynchStrategy","create_synch_object",6);
  return new PerConnectionSynch(synch_resource, priority, scheduler);
}
