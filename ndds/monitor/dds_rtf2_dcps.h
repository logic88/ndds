/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_MONITOR_DPMONITORIMPL_H
#define NDDS_MONITOR_DPMONITORIMPL_H

#include "monitor_export.h"
#include "dds/DCPS/MonitorFactory.h"
#include "monitorTypeSupportImpl.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class DPMonitorImpl : public Monitor {
public:
  DPMonitorImpl(DomainParticipantImpl* dp,
                NDDS::DCPS::DomainParticipantReportDataWriter_ptr dp_writer);
  virtual ~DPMonitorImpl();
  virtual void report();

private:
  DomainParticipantImpl* dp_;
  NDDS::DCPS::DomainParticipantReportDataWriter_var dp_writer_;
  std::string hostname_;
  pid_t pid_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* NDDS_DCPS_DPMONITOR_IMPL_H */
