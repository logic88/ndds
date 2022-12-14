/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "DCPS/DdsDcps_pch.h" //Only the _pch include should start with DCPS/
#include "NullSynch.h"
#include "NullSynchStrategy.h"

#include "EntryExit.h"

NDDS::DCPS::NullSynchStrategy::NullSynchStrategy()
{
  DBG_ENTRY_LVL("NullSynchStrategy","NullSynchStrategy",6);
}

NDDS::DCPS::NullSynchStrategy::~NullSynchStrategy()
{
  DBG_ENTRY_LVL("NullSynchStrategy","~NullSynchStrategy",6);
}

NDDS::DCPS::ThreadSynch*
NDDS::DCPS::NullSynchStrategy::create_synch_object(
  ThreadSynchResource* synch_resource,
  long                 /* priority */,
  int                  /* scheduler */)
{
  DBG_ENTRY_LVL("NullSynchStrategy","create_synch_object",6);

  if (synch_resource != 0) {
    ACE_ERROR((LM_ERROR,
               "(%P|%t) Coding Error - NullSynchStrategy::"
               "create_synch_object() should always get a NULL pointer "
               "(ThreadSynchResource*) argument.\n"));
  }

  return new NullSynch(0);
}
