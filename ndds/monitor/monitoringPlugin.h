/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_MONITOR_SPMONITORIMPL_H
#define NDDS_MONITOR_SPMONITORIMPL_H

#include "monitor_export.h"
#include "dds/DCPS/MonitorFactory.h"
#include "monitorTypeSupportImpl.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class MonitorFactoryImpl;

class SPMonitorImpl : public Monitor {
public:
  SPMonitorImpl(MonitorFactoryImpl* monitor_factory,
                Service_Participant* sp);
  virtual ~SPMonitorImpl();
  virtual void report();

private:
  MonitorFactoryImpl* monitor_factory_;
  NDDS::DCPS::ServiceParticipantReportDataWriter_var sp_writer_;
  std::string hostname_;
  pid_t pid_;
};


} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* NDDS_DCPS_SPMONITOR_IMPL_H */
