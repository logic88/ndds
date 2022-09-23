/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "DRPeriodicMonitorImpl.h"
#include "monitorC.h"
#include "monitorTypeSupportImpl.h"
#include "dds/DCPS/DataReaderImpl.h"
#include <dds/DdsDcpsInfrastructureC.h>

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {


DRPeriodicMonitorImpl::DRPeriodicMonitorImpl(DataReaderImpl* dr,
              NDDS::DCPS::DataReaderPeriodicReportDataWriter_ptr dr_per_writer)
  : dr_(dr),
    dr_per_writer_(DataReaderPeriodicReportDataWriter::_duplicate(dr_per_writer))
{
}

DRPeriodicMonitorImpl::~DRPeriodicMonitorImpl()
{
}

void
DRPeriodicMonitorImpl::report() {
  if (!CORBA::is_nil(this->dr_per_writer_.in())) {
    DataReaderPeriodicReport report;
    report.dr_id   = dr_->get_repo_id();
    //report.associations = dr_->
    this->dr_per_writer_->write(report, DDS::HANDLE_NIL);
  }
}


} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL
