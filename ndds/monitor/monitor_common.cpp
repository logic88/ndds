/*
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "MonitorFactoryImpl.h"

#include "SPMonitorImpl.h"
#include "DPMonitorImpl.h"
#include "TopicMonitorImpl.h"
#include "PublisherMonitorImpl.h"
#include "SubscriberMonitorImpl.h"
#include "DWMonitorImpl.h"
#include "DWPeriodicMonitorImpl.h"
#include "DRMonitorImpl.h"
#include "DRPeriodicMonitorImpl.h"
#include "TransportMonitorImpl.h"

#include "monitorC.h"
#include "monitorTypeSupportImpl.h"

#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/DomainParticipantImpl.h>
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/DCPS_Utils.h>
#include <dds/DCPS/transport/framework/TransportRegistry.h>

#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsPublicationC.h>

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

MonitorFactoryImpl::MonitorFactoryImpl()
{
}

MonitorFactoryImpl::~MonitorFactoryImpl()
{
  deinitialize();
}

NDDS::DCPS::Monitor*
MonitorFactoryImpl::create_sp_monitor(Service_Participant* sp)
{
  return new SPMonitorImpl(this, sp);
}

Monitor*
MonitorFactoryImpl::create_dp_monitor(DomainParticipantImpl* dp)
{
  if (dp->get_domain_id() == MONITOR_DOMAIN_ID) {
    return 0;
  }
  return new DPMonitorImpl(dp, this->dp_writer_);
}

ServiceParticipantReportDataWriter_ptr
MonitorFactoryImpl::get_sp_writer()
{
  return ServiceParticipantReportDataWriter::_duplicate(this->sp_writer_);
}

NDDS::DCPS::Monitor*
MonitorFactoryImpl::create_topic_monitor(TopicImpl* topic)
{
  return new TopicMonitorImpl(topic, this->topic_writer_);
}

NDDS::DCPS::Monitor*
MonitorFactoryImpl::create_publisher_monitor(PublisherImpl* pub)
{
  return new PublisherMonitorImpl(pub, this->pub_writer_);
}

NDDS::DCPS::Monitor*
MonitorFactoryImpl::create_subscriber_monitor(SubscriberImpl* sub)
{
  return new SubscriberMonitorImpl(sub, this->sub_writer_);
}

NDDS::DCPS::Monitor*
MonitorFactoryImpl::create_data_writer_monitor(DataWriterImpl* dw)
{
  return new DWMonitorImpl(dw, this->dw_writer_);
}

NDDS::DCPS::Monitor*
MonitorFactoryImpl::create_data_writer_periodic_monitor(DataWriterImpl* dw)
{
  return new DWPeriodicMonitorImpl(dw, this->dw_per_writer_);
}

NDDS::DCPS::Monitor*
MonitorFactoryImpl::create_data_reader_monitor(DataReaderImpl* dr)
{
  return new DRMonitorImpl(dr, this->dr_writer_);
}

NDDS::DCPS::Monitor*
MonitorFactoryImpl::create_data_reader_periodic_monitor(DataReaderImpl* dr)
{
  return new DRPeriodicMonitorImpl(dr, this->dr_per_writer_);
}

NDDS::DCPS::Monitor*
MonitorFactoryImpl::create_transport_monitor(TransportImpl* transport)
{
  return new TransportMonitorImpl(transport, this->transport_writer_);
}

DDS::DataWriter_ptr
MonitorFactoryImpl::create_data_writer(DDS::DomainParticipant_ptr participant,
                                       DDS::Publisher_ptr publisher,
                                       const char* type_name,
                                       const char* topic_name,
                                       const DDS::DataWriterQos& dw_qos)
{
  DDS::Topic_var topic =
    participant->create_topic(topic_name,
                              type_name,
                              TOPIC_QOS_DEFAULT,
                              DDS::TopicListener::_nil(),
                              NDDS::DCPS::DEFAULT_STATUS_MASK);
  if (CORBA::is_nil(topic)) {
    ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::create_data_writer(): Failed to create topic, name = %C\n", topic_name));
  }
  DDS::DataWriter_var writer =
    publisher->create_datawriter(topic.in(),
                                 dw_qos,
                                 DDS::DataWriterListener::_nil(),
                                 NDDS::DCPS::DEFAULT_STATUS_MASK);
  if (CORBA::is_nil(writer)) {
    ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::create_data_writer(): Failed to create data writer\n"));
  }

  return writer._retn();
}

void
MonitorFactoryImpl::initialize()
{
  DDS::DomainParticipantFactory_var dpf =
    TheServiceParticipant->get_domain_participant_factory();
  DDS::DomainParticipant_var participant =
    dpf->create_participant(MONITOR_DOMAIN_ID,
                            PARTICIPANT_QOS_DEFAULT,
                            DDS::DomainParticipantListener::_nil(),
                            NDDS::DCPS::DEFAULT_STATUS_MASK);
  participant_ = participant;
  if (CORBA::is_nil(participant.in())) {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("ERROR: %N:%l: MonitorFactoryImpl::initialize() -")
               ACE_TEXT(" create_participant failed!\n")));
  }

  DDS::Publisher_var publisher =
    participant->create_publisher(PUBLISHER_QOS_DEFAULT,
                                  DDS::PublisherListener::_nil(),
                                  NDDS::DCPS::DEFAULT_STATUS_MASK);

  static const std::string config_name = TransportRegistry::DEFAULT_INST_PREFIX
    + std::string("MonitorBITTransportConfig");
  NDDS::DCPS::TransportConfig_rch config =
    TheTransportRegistry->get_config (config_name);
  if (config.is_nil ())
  {
    config = TransportRegistry::instance()->create_config(config_name);

    std::string inst_name = TransportRegistry::DEFAULT_INST_PREFIX
      + std::string("FederationBITTCPTransportInst");
    TransportInst_rch inst =
      TransportRegistry::instance()->create_inst(inst_name, "tcp");
    config->instances_.push_back(inst);
  }

  TransportRegistry::instance()->bind_config(config, publisher.in());

  DDS::DataWriter_var writer;
  DDS::DataWriterQos dw_qos;
  publisher->get_default_datawriter_qos(dw_qos);
  dw_qos.durability.kind = DDS::TRANSIENT_LOCAL_DURABILITY_QOS;

  NDDS::DCPS::ServiceParticipantReportTypeSupport_var sp_ts =
    new NDDS::DCPS::ServiceParticipantReportTypeSupportImpl();
  ::DDS::ReturnCode_t ret = sp_ts->register_type(participant.in(), "");
  if (DDS::RETCODE_OK == ret) {
    CORBA::String_var sp_type_name = sp_ts->get_type_name();
    writer = create_data_writer(participant.in(),
                                publisher.in(),
                                sp_type_name.in(),
                                SERVICE_PARTICIPANT_MONITOR_TOPIC,
                                dw_qos);
    this->sp_writer_ =
      NDDS::DCPS::ServiceParticipantReportDataWriter::_narrow(writer.in());
    if (CORBA::is_nil(this->sp_writer_)) {
      ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::initialize(): Failed to narrow sp_writer\n"));
    }
  } else {
    ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::initialize(): Failed to register sp_ts\n"));
  }

  NDDS::DCPS::DomainParticipantReportTypeSupport_var dp_ts =
    new NDDS::DCPS::DomainParticipantReportTypeSupportImpl();
  ret = dp_ts->register_type(participant.in(), "");
  if (DDS::RETCODE_OK == ret) {
    CORBA::String_var dp_type_name = dp_ts->get_type_name();
    writer = create_data_writer(participant.in(),
                                publisher.in(),
                                dp_type_name.in(),
                                DOMAIN_PARTICIPANT_MONITOR_TOPIC,
                                dw_qos);
    this->dp_writer_ =
      NDDS::DCPS::DomainParticipantReportDataWriter::_narrow(writer.in());
    if (CORBA::is_nil(this->dp_writer_)) {
      ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::initialize(): Failed to narrow dp_writer\n"));
    }
  } else {
    ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::initialize(): Failed to register dp_ts\n"));
  }

  NDDS::DCPS::TopicReportTypeSupport_var topic_ts =
    new NDDS::DCPS::TopicReportTypeSupportImpl();
  ret = topic_ts->register_type(participant.in(), "");
  if (DDS::RETCODE_OK == ret) {
    CORBA::String_var topic_type_name = topic_ts->get_type_name();
    writer = create_data_writer(participant.in(),
                                publisher.in(),
                                topic_type_name.in(),
                                TOPIC_MONITOR_TOPIC,
                                dw_qos);
    this->topic_writer_ =
      NDDS::DCPS::TopicReportDataWriter::_narrow(writer.in());
    if (CORBA::is_nil(this->topic_writer_)) {
      ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::initialize(): Failed to narrow topic_writer\n"));
    }
  } else {
    ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::initialize(): Failed to register topic_ts\n"));
  }

  NDDS::DCPS::PublisherReportTypeSupport_var pub_ts =
    new NDDS::DCPS::PublisherReportTypeSupportImpl();
  ret = pub_ts->register_type(participant.in(), "");
  if (DDS::RETCODE_OK == ret) {
    CORBA::String_var pub_type_name = pub_ts->get_type_name();
    writer = create_data_writer(participant.in(),
                                publisher.in(),
                                pub_type_name.in(),
                                PUBLISHER_MONITOR_TOPIC,
                                dw_qos);
    this->pub_writer_ =
      NDDS::DCPS::PublisherReportDataWriter::_narrow(writer.in());
    if (CORBA::is_nil(this->pub_writer_)) {
      ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::initialize(): Failed to narrow pub_writer\n"));
    }
  } else {
    ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::initialize(): Failed to register pub_ts\n"));
  }

  NDDS::DCPS::SubscriberReportTypeSupport_var sub_ts =
    new NDDS::DCPS::SubscriberReportTypeSupportImpl();
  ret = sub_ts->register_type(participant.in(), "");
  if (DDS::RETCODE_OK == ret) {
    CORBA::String_var sub_type_name = sub_ts->get_type_name();
    writer = create_data_writer(participant.in(),
                                publisher.in(),
                                sub_type_name.in(),
                                SUBSCRIBER_MONITOR_TOPIC,
                                dw_qos);
    this->sub_writer_ =
      NDDS::DCPS::SubscriberReportDataWriter::_narrow(writer.in());
    if (CORBA::is_nil(this->sub_writer_)) {
      ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::initialize(): Failed to narrow sub_writer\n"));
    }
  } else {
    ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::initialize(): Failed to register sub_ts\n"));
  }

  NDDS::DCPS::DataWriterReportTypeSupport_var dw_ts =
    new NDDS::DCPS::DataWriterReportTypeSupportImpl();
  ret = dw_ts->register_type(participant.in(), "");
  if (DDS::RETCODE_OK == ret) {
    CORBA::String_var dw_type_name = dw_ts->get_type_name();
    writer = create_data_writer(participant.in(),
                                publisher.in(),
                                dw_type_name.in(),
                                DATA_WRITER_MONITOR_TOPIC,
                                dw_qos);
    this->dw_writer_ =
      NDDS::DCPS::DataWriterReportDataWriter::_narrow(writer.in());
    if (CORBA::is_nil(this->dw_writer_)) {
      ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::initialize(): Failed to narrow dw_writer\n"));
    }
  } else {
    ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::initialize(): Failed to register sp_ts\n"));
  }

  NDDS::DCPS::DataWriterPeriodicReportTypeSupport_var dw_per_ts =
    new NDDS::DCPS::DataWriterPeriodicReportTypeSupportImpl();
  ret = dw_per_ts->register_type(participant.in(), "");
  if (DDS::RETCODE_OK == ret) {
    CORBA::String_var dw_per_type_name = dw_per_ts->get_type_name();
    writer = create_data_writer(participant.in(),
                                publisher.in(),
                                dw_per_type_name.in(),
                                DATA_WRITER_PERIODIC_MONITOR_TOPIC,
                                dw_qos);
    this->dw_per_writer_ =
      NDDS::DCPS::DataWriterPeriodicReportDataWriter::_narrow(writer.in());
    if (CORBA::is_nil(this->dw_per_writer_)) {
      ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::initialize(): Failed to narrow dw_per_writer\n"));
    }
  } else {
    ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::initialize(): Failed to register dw_per_ts\n"));
  }

  NDDS::DCPS::DataReaderReportTypeSupport_var dr_ts =
    new NDDS::DCPS::DataReaderReportTypeSupportImpl();
  ret = dr_ts->register_type(participant.in(), "");
  if (DDS::RETCODE_OK == ret) {
    CORBA::String_var dr_type_name = dr_ts->get_type_name();
    writer = create_data_writer(participant.in(),
                                publisher.in(),
                                dr_type_name.in(),
                                DATA_READER_MONITOR_TOPIC,
                                dw_qos);
    this->dr_writer_ =
      NDDS::DCPS::DataReaderReportDataWriter::_narrow(writer.in());
    if (CORBA::is_nil(this->dr_writer_)) {
      ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::initialize(): Failed to narrow dr_writer\n"));
    }
  } else {
    ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::initialize(): Failed to register dr_ts\n"));
  }

  NDDS::DCPS::DataReaderPeriodicReportTypeSupport_var dr_per_ts =
    new NDDS::DCPS::DataReaderPeriodicReportTypeSupportImpl();
  ret = dr_per_ts->register_type(participant.in(), "");
  if (DDS::RETCODE_OK == ret) {
    CORBA::String_var dr_per_type_name = dr_per_ts->get_type_name();
    writer = create_data_writer(participant.in(),
                                publisher.in(),
                                dr_per_type_name.in(),
                                DATA_READER_PERIODIC_MONITOR_TOPIC,
                                dw_qos);
    this->dr_per_writer_ =
      NDDS::DCPS::DataReaderPeriodicReportDataWriter::_narrow(writer.in());
    if (CORBA::is_nil(this->dr_per_writer_)) {
      ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::initialize(): Failed to narrow dr_per_writer\n"));
    }
  } else {
    ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::initialize(): Failed to register dr_per_ts\n"));
  }

  NDDS::DCPS::TransportReportTypeSupport_var transport_ts =
    new NDDS::DCPS::TransportReportTypeSupportImpl();
  ret = transport_ts->register_type(participant.in(), "");
  if (DDS::RETCODE_OK == ret) {
    CORBA::String_var transport_type_name = transport_ts->get_type_name();
    writer = create_data_writer(participant.in(),
                                publisher.in(),
                                transport_type_name.in(),
                                TRANSPORT_MONITOR_TOPIC,
                                dw_qos);
    this->transport_writer_ =
      NDDS::DCPS::TransportReportDataWriter::_narrow(writer.in());
    if (CORBA::is_nil(this->transport_writer_)) {
      ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::initialize(): Failed to narrow transport_writer\n"));
    }
  } else {
    ACE_DEBUG((LM_DEBUG, "MonitorFactoryImpl::initialize(): Failed to register transport_ts\n"));
  }
}

void MonitorFactoryImpl::deinitialize()
{
  if (participant_) {
    DDS::ReturnCode_t tmp = participant_->delete_contained_entities();
    if (tmp && log_level >= LogLevel::Error) {
      ACE_ERROR((LM_ERROR, "(%P|%t) ERROR: MonitorFactoryImpl::deinitialize: "
        "delete_contained_entities returned %C\n",
        retcode_to_string(tmp)));
    }

    DDS::DomainParticipantFactory_var dpf =
      TheServiceParticipant->get_domain_participant_factory();
    tmp = dpf->delete_participant(participant_);
    if (tmp && log_level >= LogLevel::Error) {
      ACE_ERROR((LM_ERROR, "(%P|%t) ERROR: MonitorFactoryImpl::deinitialize: "
        "delete_participant returned %C\n",
        retcode_to_string(tmp)));
    }

    participant_ = 0;
  }
}

int
MonitorFactoryImpl::service_initialize()
{
  return ACE_Service_Config::process_directive(ace_svc_desc_MonitorFactoryImpl);
}

} // namespace DCPS
} // namespace NDDS

using namespace NDDS::DCPS;

ACE_FACTORY_DEFINE (NDDS_monitor, MonitorFactoryImpl)
ACE_STATIC_SVC_DEFINE (MonitorFactoryImpl,
                       ACE_TEXT ("NDDS_Monitor"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (MonitorFactoryImpl),
                       ACE_Service_Type::DELETE_THIS |
                         ACE_Service_Type::DELETE_OBJ,
                       0)

NDDS_END_VERSIONED_NAMESPACE_DECL
