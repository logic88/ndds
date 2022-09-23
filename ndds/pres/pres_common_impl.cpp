/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "DCPS/DdsDcps_pch.h" //Only the _pch include should start with DCPS/
#include "ReactorSynchStrategy.h"
#include "ReactorSynch.h"

#if !defined (__ACE_INLINE__)
#include "ReactorSynchStrategy.inl"
#endif /* __ACE_INLINE__ */

NDDS::DCPS::ReactorSynchStrategy::~ReactorSynchStrategy()
{
  DBG_ENTRY_LVL("ReactorSynchStrategy","~ReactorSynchStrategy",6);
}

NDDS::DCPS::ThreadSynch*
NDDS::DCPS::ReactorSynchStrategy::create_synch_object(
  ThreadSynchResource* synch_resource, long, int)
{
  DBG_ENTRY_LVL("ReactorSynchStrategy","create_synch_object",6);
  return new ReactorSynch(
               synch_resource, strategy_, reactor_);
}
