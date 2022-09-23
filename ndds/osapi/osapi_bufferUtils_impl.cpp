/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "DCPS/DdsDcps_pch.h" //Only the _pch include should start with DCPS/
#include "MonitorFactory.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

MonitorFactory::MonitorFactory()
{
}

MonitorFactory::~MonitorFactory()
{
}

NDDS::DCPS::Monitor*
MonitorFactory::create_sp_monitor(Service_Participant*)
{
  return 0;
}

NDDS::DCPS::Monitor*
MonitorFactory::create_dp_monitor(DomainParticipantImpl*)
{
  return 0;
}

NDDS::DCPS::Monitor*
MonitorFactory::create_topic_monitor(TopicImpl*)
{
  return 0;
}

NDDS::DCPS::Monitor*
MonitorFactory::create_publisher_monitor(PublisherImpl*)
{
  return 0;
}

NDDS::DCPS::Monitor*
MonitorFactory::create_subscriber_monitor(SubscriberImpl*)
{
  return 0;
}

NDDS::DCPS::Monitor*
MonitorFactory::create_data_writer_monitor(DataWriterImpl*)
{
  return 0;
}

NDDS::DCPS::Monitor*
MonitorFactory::create_data_writer_periodic_monitor(DataWriterImpl*)
{
  return 0;
}

NDDS::DCPS::Monitor*
MonitorFactory::create_data_reader_monitor(DataReaderImpl*)
{
  return 0;
}

NDDS::DCPS::Monitor*
MonitorFactory::create_data_reader_periodic_monitor(DataReaderImpl*)
{
  return 0;
}

NDDS::DCPS::Monitor*
MonitorFactory::create_transport_monitor(TransportImpl*)
{
  return 0;
}

void
MonitorFactory::initialize()
{
}

void MonitorFactory::deinitialize()
{
}

int
MonitorFactory::service_initialize()
{
  return ACE_Service_Config::process_directive(ace_svc_desc_MonitorFactory);
}

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

using namespace NDDS::DCPS;

ACE_FACTORY_DEFINE (NDDS_Dcps, MonitorFactory)
ACE_STATIC_SVC_DEFINE (MonitorFactory,
                       ACE_TEXT ("NDDS_Monitor_Default"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (MonitorFactory),
                       ACE_Service_Type::DELETE_THIS |
                         ACE_Service_Type::DELETE_OBJ,
                       0)
