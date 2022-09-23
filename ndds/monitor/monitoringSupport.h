/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_MONITOR_SUBSCRIBERMONITORIMPL_H
#define NDDS_MONITOR_SUBSCRIBERMONITORIMPL_H

#include "monitor_export.h"
#include "dds/DCPS/MonitorFactory.h"
#include "monitorTypeSupportImpl.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class SubscriberMonitorImpl : public Monitor {
public:
  SubscriberMonitorImpl(SubscriberImpl* sub,
                   NDDS::DCPS::SubscriberReportDataWriter_ptr sub_writer);
  virtual ~SubscriberMonitorImpl();
  virtual void report();

private:
  SubscriberImpl* sub_;
  NDDS::DCPS::SubscriberReportDataWriter_var sub_writer_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* NDDS_DCPS_SUBSCRIBER_MONITOR_IMPL_H */
