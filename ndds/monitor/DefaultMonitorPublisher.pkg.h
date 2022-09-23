/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_MONITOR_DRPERIODICMONITORIMPL_H
#define NDDS_MONITOR_DRPERIODICMONITORIMPL_H

#include "monitor_export.h"
#include "dds/DCPS/MonitorFactory.h"
#include "monitorTypeSupportImpl.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class DRPeriodicMonitorImpl : public Monitor {
public:
  DRPeriodicMonitorImpl(DataReaderImpl* dr,
                   NDDS::DCPS::DataReaderPeriodicReportDataWriter_ptr dr_per_writer);
  virtual ~DRPeriodicMonitorImpl();
  virtual void report();

private:
  DataReaderImpl* dr_;
  NDDS::DCPS::DataReaderPeriodicReportDataWriter_var dr_per_writer_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* NDDS_DCPS_DR_PERIODIC_MONITOR_IMPL_H */
