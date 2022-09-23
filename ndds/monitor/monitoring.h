/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_MONITOR_PUBLISHERMONITORIMPL_H
#define NDDS_MONITOR_PUBLISHERMONITORIMPL_H

#include "monitor_export.h"
#include "dds/DCPS/MonitorFactory.h"
#include "monitorTypeSupportImpl.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class PublisherMonitorImpl : public Monitor {
public:
  PublisherMonitorImpl(PublisherImpl* pub,
                   NDDS::DCPS::PublisherReportDataWriter_ptr pub_writer);
  virtual ~PublisherMonitorImpl();
  virtual void report();

private:
  PublisherImpl* pub_;
  NDDS::DCPS::PublisherReportDataWriter_var pub_writer_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* NDDS_DCPS_PUBLISHER_MONITOR_IMPL_H */
