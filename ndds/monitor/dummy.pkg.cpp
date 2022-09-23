/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "DWPeriodicMonitorImpl.h"
#include "monitorC.h"
#include "monitorTypeSupportImpl.h"
#include "dds/DCPS/DataWriterImpl.h"
#include <dds/DdsDcpsInfrastructureC.h>

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

DWPeriodicMonitorImpl::DWPeriodicMonitorImpl(DataWriterImpl* dw,
              NDDS::DCPS::DataWriterPeriodicReportDataWriter_ptr dw_per_writer)
  : dw_(dw),
    dw_per_writer_(DataWriterPeriodicReportDataWriter::_duplicate(dw_per_writer))
{
}

DWPeriodicMonitorImpl::~DWPeriodicMonitorImpl()
{
}

void
DWPeriodicMonitorImpl::report() {
  if (!CORBA::is_nil(this->dw_per_writer_.in())) {
    DataWriterPeriodicReport report;
    report.dw_id   = dw_->get_repo_id();
    //report.data_dropped_count = dw_->
    //report.data_delivered_count  = dw_->
    //report.control_dropped_count  = dw_->
    //report.control_delivered_count  = dw_->
    //report.associations  = dw_->
    this->dw_per_writer_->write(report, DDS::HANDLE_NIL);
  }
}


} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL
