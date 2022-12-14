/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "DCPS/DdsDcps_pch.h" //Only the _pch include should start with DCPS/
#include "Marked_Default_Qos.h"
#include "Service_Participant.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

int const INVALID_ENUM_VALUE = 999;

DDS::DomainParticipantQos
Marked_Default_Qos::marked_default_DomainParticipantQos()
{
  DDS::DomainParticipantQos qos =
    TheServiceParticipant->initial_DomainParticipantQos();
  void* const mem = &qos.entity_factory.autoenable_created_entities;
  *static_cast<char*>(mem) = 3;
  return qos;
}

DDS::TopicQos
Marked_Default_Qos::marked_default_TopicQos()
{
  DDS::TopicQos qos = TheServiceParticipant->initial_TopicQos();
  qos.liveliness.kind
  = static_cast<DDS::LivelinessQosPolicyKind>(
      INVALID_ENUM_VALUE);
  return qos;
}

DDS::DataWriterQos
Marked_Default_Qos::marked_default_DataWriterQos()
{
  DDS::DataWriterQos qos = TheServiceParticipant->initial_DataWriterQos();
  qos.liveliness.kind
  = static_cast<DDS::LivelinessQosPolicyKind>(
      INVALID_ENUM_VALUE);
  return qos;
}

DDS::PublisherQos
Marked_Default_Qos::marked_default_PublisherQos()
{
  DDS::PublisherQos qos = TheServiceParticipant->initial_PublisherQos();
  qos.presentation.access_scope
  = static_cast<DDS::PresentationQosPolicyAccessScopeKind>(
      INVALID_ENUM_VALUE);
  return qos;
}

DDS::DataReaderQos
Marked_Default_Qos::marked_default_DataReaderQos()
{
  DDS::DataReaderQos qos = TheServiceParticipant->initial_DataReaderQos();
  qos.liveliness.kind
  = static_cast<DDS::LivelinessQosPolicyKind>(
      INVALID_ENUM_VALUE);
  return qos;
}

DDS::SubscriberQos
Marked_Default_Qos::marked_default_SubscriberQos()
{
  DDS::SubscriberQos qos = TheServiceParticipant->initial_SubscriberQos();
  qos.presentation.access_scope
  = static_cast<DDS::PresentationQosPolicyAccessScopeKind>(
      INVALID_ENUM_VALUE);
  return qos;
}

DDS::DataWriterQos
Marked_Default_Qos::marked_default_DataWriter_Use_TopicQos()
{
  DDS::DataWriterQos qos = TheServiceParticipant->initial_DataWriterQos();
  qos.durability.kind
  = static_cast<DDS::DurabilityQosPolicyKind>(
      INVALID_ENUM_VALUE);
  return qos;
}

DDS::DataReaderQos
Marked_Default_Qos::marked_default_DataReader_Use_TopicQos()
{
  DDS::DataReaderQos qos = TheServiceParticipant->initial_DataReaderQos();
  qos.durability.kind
  = static_cast<DDS::DurabilityQosPolicyKind>(
      INVALID_ENUM_VALUE);
  return qos;
}

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL
