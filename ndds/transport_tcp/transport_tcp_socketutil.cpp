/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "Tcp_pch.h"
#include "TcpSynchResource.h"
#include "TcpConnection.h"
#include "TcpSendStrategy.h"
#include "TcpDataLink.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

NDDS::DCPS::TcpSynchResource::TcpSynchResource(
  TcpDataLink& link,
  const int& max_output_pause_period_ms)
  : ThreadSynchResource()
  , link_(link)
{
  DBG_ENTRY_LVL("TcpSynchResource","TcpSynchResource",6);

  if (max_output_pause_period_ms >= 0) {
    timeout_ = new TimeDuration(TimeDuration::from_msec(max_output_pause_period_ms));
  }
}

NDDS::DCPS::TcpSynchResource::~TcpSynchResource()
{
  DBG_ENTRY_LVL("TcpSynchResource","~TcpSynchResource",6);
}

void
NDDS::DCPS::TcpSynchResource::notify_lost_on_backpressure_timeout()
{
  DBG_ENTRY_LVL("TcpSynchResource","notify_lost_on_backpressure_timeout",6);

  TcpConnection_rch connection = link_.get_connection();
  connection->notify_lost_on_backpressure_timeout();
}

NDDS_END_VERSIONED_NAMESPACE_DECL
