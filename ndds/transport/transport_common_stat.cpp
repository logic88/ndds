/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "DCPS/DdsDcps_pch.h" //Only the _pch include should start with DCPS/
#include "TransportReceiveListener.h"
#include "EntryExit.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

NDDS::DCPS::TransportReceiveListener::TransportReceiveListener()
{
  DBG_ENTRY_LVL("TransportReceiveListener","TransportReceiveListener",6);
}

NDDS::DCPS::TransportReceiveListener::~TransportReceiveListener()
{
  DBG_ENTRY_LVL("TransportReceiveListener","~TransportReceiveListener",6);
}

NDDS_END_VERSIONED_NAMESPACE_DECL
