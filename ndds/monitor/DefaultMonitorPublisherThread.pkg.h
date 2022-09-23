/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_MONITOR_DWMONITORIMPL_H
#define NDDS_MONITOR_DWMONITORIMPL_H

#include "monitor_export.h"
#include "dds/DCPS/MonitorFactory.h"
#include "monitorTypeSupportImpl.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class DWMonitorImpl : public Monitor {
public:
  DWMonitorImpl(DataWriterImpl* dw,
                   NDDS::DCPS::DataWriterReportDataWriter_ptr dw_writer);
  virtual ~DWMonitorImpl();
  virtual void report();

private:
  DataWriterImpl* dw_;
  NDDS::DCPS::DataWriterReportDataWriter_var dw_writer_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* NDDS_DCPS_DW_MONITOR_IMPL_H */
