/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_MONITOR_DWPERIODICMONITORIMPL_H
#define NDDS_MONITOR_DWPERIODICMONITORIMPL_H

#include "monitor_export.h"
#include "dds/DCPS/MonitorFactory.h"
#include "monitorTypeSupportImpl.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class DWPeriodicMonitorImpl : public Monitor {
public:
  DWPeriodicMonitorImpl(DataWriterImpl* dw,
                   NDDS::DCPS::DataWriterPeriodicReportDataWriter_ptr dw_per_writer);
  virtual ~DWPeriodicMonitorImpl();
  virtual void report();

private:
  DataWriterImpl* dw_;
  NDDS::DCPS::DataWriterPeriodicReportDataWriter_var dw_per_writer_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* NDDS_DCPS_DW_PERIODIC_MONITOR_IMPL_H */
