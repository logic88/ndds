/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_DCPS_UTILS_H
#define NDDS_DCPS_DCPS_UTILS_H

#include "dcps_export.h"

#include "Serializer.h"

#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsPublicationC.h>
#include <dds/DdsDcpsInfoUtilsC.h>

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

NDDS_Dcps_Export const char* retcode_to_string(DDS::ReturnCode_t value);

NDDS_Dcps_Export const char* topicstatus_to_string(TopicStatus value);

NDDS_Dcps_Export
bool
is_wildcard(const char *str);

/// Increments the count of occurrences of the incompatible policy
///  for the status
NDDS_Dcps_Export
void
increment_incompatibility_count(NDDS::DCPS::IncompatibleQosStatus* status,
                                DDS::QosPolicyId_t incompatible_policy);

/// Compares whether a publication and subscription are compatible
/// by comparing their constituent parts.
NDDS_Dcps_Export
bool compatibleQOS(NDDS::DCPS::IncompatibleQosStatus* writerStatus,
                   NDDS::DCPS::IncompatibleQosStatus* readerStatus,
                   const NDDS::DCPS::TransportLocatorSeq& pubTLS,
                   const NDDS::DCPS::TransportLocatorSeq& subTLS,
                   DDS::DataWriterQos const * const writerQos,
                   DDS::DataReaderQos const * const readerQos,
                   DDS::PublisherQos const * const pubQos,
                   DDS::SubscriberQos const * const subQos);

NDDS_Dcps_Export
bool
compatibleQOS(const DDS::DataWriterQos * writerQos,
              const DDS::DataReaderQos * readerQos,
              NDDS::DCPS::IncompatibleQosStatus* writerStatus = 0,
              NDDS::DCPS::IncompatibleQosStatus* readerStatus = 0);

NDDS_Dcps_Export
bool
compatibleQOS(const DDS::PublisherQos * pubQos,
              const DDS::SubscriberQos * subQos,
              NDDS::DCPS::IncompatibleQosStatus* writerStatus = 0,
              NDDS::DCPS::IncompatibleQosStatus* readerStatus = 0);

NDDS_Dcps_Export
bool
matching_partitions(const DDS::PartitionQosPolicy& pub,
                    const DDS::PartitionQosPolicy& sub);

// Should check the association of the entity QoS ?
// The changeable QoS that is supported currently and affect the association
// establishment is deadline QoS and partition QoS.
NDDS_Dcps_Export
bool should_check_association_upon_change(const DDS::DataReaderQos & qos1,
                                          const DDS::DataReaderQos & qos2);

NDDS_Dcps_Export
bool should_check_association_upon_change(const DDS::DataWriterQos & qos1,
                                          const DDS::DataWriterQos & qos2);

NDDS_Dcps_Export
bool should_check_association_upon_change(const DDS::SubscriberQos & qos1,
                                          const DDS::SubscriberQos & qos2);

NDDS_Dcps_Export
bool should_check_association_upon_change(const DDS::PublisherQos & qos1,
                                          const DDS::PublisherQos & qos2);

NDDS_Dcps_Export
bool should_check_association_upon_change(const DDS::TopicQos & qos1,
                                          const DDS::TopicQos & qos2);

NDDS_Dcps_Export
bool should_check_association_upon_change(const DDS::DomainParticipantQos & qos1,
                                          const DDS::DomainParticipantQos & qos2);

NDDS_Dcps_Export
bool repr_to_encoding_kind(DDS::DataRepresentationId_t repr, Encoding::Kind& kind);

NDDS_Dcps_Export
DCPS::String repr_to_string(const DDS::DataRepresentationId_t& repr);

NDDS_Dcps_Export
DCPS::String repr_seq_to_string(const DDS::DataRepresentationIdSeq& id_seq, bool is_data_writer = false);

NDDS_Dcps_Export
void set_writer_effective_data_rep_qos(DDS::DataRepresentationIdSeq& qos, bool encapsulated_only);

NDDS_Dcps_Export
void set_reader_effective_data_rep_qos(DDS::DataRepresentationIdSeq& qos);

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* NDDS_DDS_DCPS_DCPS_UTILS_H */
