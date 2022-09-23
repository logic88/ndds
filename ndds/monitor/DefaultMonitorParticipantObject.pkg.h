/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_MONITOR_DRMONITORIMPL_H
#define NDDS_MONITOR_DRMONITORIMPL_H

#include "monitor_export.h"
#include "dds/DCPS/MonitorFactory.h"
#include "monitorTypeSupportImpl.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class DRMonitorImpl : public Monitor {
public:
  DRMonitorImpl(DataReaderImpl* dr,
                   NDDS::DCPS::DataReaderReportDataWriter_ptr dr_writer);
  virtual ~DRMonitorImpl();
  virtual void report();

private:
  DataReaderImpl* dr_;
  NDDS::DCPS::DataReaderReportDataWriter_var dr_writer_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* NDDS_DCPS_DR_MONITOR_IMPL_H */
