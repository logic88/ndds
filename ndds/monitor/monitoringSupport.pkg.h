/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_MONITOR_TOPICMONITORIMPL_H
#define NDDS_MONITOR_TOPICMONITORIMPL_H

#include "monitor_export.h"
#include "dds/DCPS/MonitorFactory.h"
#include "monitorTypeSupportImpl.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class TopicMonitorImpl : public Monitor {
public:
  TopicMonitorImpl(TopicImpl* topic,
                   NDDS::DCPS::TopicReportDataWriter_ptr topic_writer);
  virtual ~TopicMonitorImpl();
  virtual void report();

private:
  TopicImpl* topic_;
  NDDS::DCPS::TopicReportDataWriter_var topic_writer_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* NDDS_DCPS_TOPICMONITOR_IMPL_H */
