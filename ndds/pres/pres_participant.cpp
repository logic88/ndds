/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "DCPS/DdsDcps_pch.h" //Only the _pch include should start with DCPS/
#include "ThreadSynch.h"

#if !defined (__ACE_INLINE__)
#include "ThreadSynch.inl"
#endif /* __ACE_INLINE__ */

NDDS::DCPS::ThreadSynch::~ThreadSynch()
{
  DBG_ENTRY_LVL("ThreadSynch","~ThreadSynch",6);
}

int
NDDS::DCPS::ThreadSynch::register_worker_i()
{
  DBG_ENTRY_LVL("ThreadSynch","register_worker_i",6);
  // Default implementation is to do nothing here.  Subclass may override.
  return 0;
}

void
NDDS::DCPS::ThreadSynch::unregister_worker_i()
{
  DBG_ENTRY_LVL("ThreadSynch","unregister_worker_i",6);
  // Default implementation is to do nothing here.  Subclass may override.
}
