/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "DCPS/DdsDcps_pch.h" //Only the _pch include should start with DCPS/
#include "ThreadSynchWorker.h"

#if !defined (__ACE_INLINE__)
#include "ThreadSynchWorker.inl"
#endif /* __ACE_INLINE__ */

NDDS::DCPS::ThreadSynchWorker::~ThreadSynchWorker()
{
  DBG_ENTRY_LVL("ThreadSynchWorker","~ThreadSynchWorker",6);
}
