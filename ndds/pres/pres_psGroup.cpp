/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "DCPS/DdsDcps_pch.h" //Only the _pch include should start with DCPS/
#include "ThreadSynchStrategy.h"

#if !defined (__ACE_INLINE__)
#include "ThreadSynchStrategy.inl"
#endif /* __ACE_INLINE__ */

NDDS::DCPS::ThreadSynchStrategy::~ThreadSynchStrategy()
{
  DBG_ENTRY_LVL("ThreadSynchStrategy","~ThreadSynchStrategy",6);
}
