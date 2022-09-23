/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_MONITOR_TRANSPORTMONITORIMPL_H
#define NDDS_MONITOR_TRANSPORTMONITORIMPL_H

#include "monitor_export.h"
#include "dds/DCPS/MonitorFactory.h"
#include "monitorTypeSupportImpl.h"
#include "ace/Recursive_Thread_Mutex.h"
#include <vector>

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class TransportMonitorImpl : public Monitor {
public:
  TransportMonitorImpl(TransportImpl* transport,
                   NDDS::DCPS::TransportReportDataWriter_ptr transport_writer);
  virtual ~TransportMonitorImpl();
  virtual void report();

private:
  NDDS::DCPS::TransportReportDataWriter_var transport_writer_;
  std::string hostname_;
  pid_t pid_;

  typedef std::vector<TransportReport> TransportReportVec;
  static ACE_Recursive_Thread_Mutex queue_lock_;
  static TransportReportVec queue_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* NDDS_DCPS_TRANSPORT_MONITOR_IMPL_H */
