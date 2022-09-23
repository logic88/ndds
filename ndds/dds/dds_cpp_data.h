/*
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_RTPS_PARAMETERLISTCONVERTER_H
#define NDDS_DCPS_RTPS_PARAMETERLISTCONVERTER_H

#include "rtps_export.h"
#include "RtpsCoreC.h"

#ifdef NDDS_SECURITY
#include "RtpsSecurityC.h"
#endif

#include "ICE/Ice.h"

#include "dds/DCPS/XTypes/TypeObject.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace RTPS {

#ifdef NDDS_SECURITY
struct DiscoveredPublication_SecurityWrapper;
struct DiscoveredSubscription_SecurityWrapper;
#endif

namespace ParameterListConverter {

// DDS::ParticipantBuiltinTopicData

NDDS_Rtps_Export
bool to_param_list(const DDS::ParticipantBuiltinTopicData& pbtd,
                   ParameterList& param_list);

NDDS_Rtps_Export
bool from_param_list(const ParameterList& param_list,
                     DDS::ParticipantBuiltinTopicData& pbtd);

#ifdef NDDS_SECURITY
// DDS::Security::ParticipantBuiltinTopicData

NDDS_Rtps_Export
bool to_param_list(const DDS::Security::ParticipantBuiltinTopicData& pbtd,
                   ParameterList& param_list);

NDDS_Rtps_Export
bool from_param_list(const ParameterList& param_list,
                     DDS::Security::ParticipantBuiltinTopicData& pbtd);

// DDS::Security::ParticipantBuiltinTopicDataSecure

NDDS_Rtps_Export
bool to_param_list(const DDS::Security::ParticipantBuiltinTopicDataSecure& pbtds,
                   ParameterList& param_list);

NDDS_Rtps_Export
bool from_param_list(const ParameterList& param_list,
                     DDS::Security::ParticipantBuiltinTopicDataSecure& pbtds);
#endif

// NDDS::RTPS::ParticipantProxy_t

NDDS_Rtps_Export
bool to_param_list(const ParticipantProxy_t& proxy,
                   ParameterList& param_list);

NDDS_Rtps_Export
bool from_param_list(const ParameterList& param_list,
                     ParticipantProxy_t& proxy);

// NDDS::RTPS::Duration_t

NDDS_Rtps_Export
bool to_param_list(const Duration_t& duration,
                   ParameterList& param_list);

NDDS_Rtps_Export
bool from_param_list(const ParameterList& param_list,
                     Duration_t& duration);

// NDDS::RTPS::SPDPdiscoveredParticipantData

NDDS_Rtps_Export
bool to_param_list(const SPDPdiscoveredParticipantData& participant_data,
                   ParameterList& param_list);

NDDS_Rtps_Export
bool from_param_list(const ParameterList& param_list,
                     SPDPdiscoveredParticipantData& participant_data);

#ifdef NDDS_SECURITY
// NDDS::Security::SPDPdiscoveredParticipantData

NDDS_Rtps_Export
bool to_param_list(const NDDS::Security::SPDPdiscoveredParticipantData& participant_data,
                   ParameterList& param_list);

NDDS_Rtps_Export
bool from_param_list(const ParameterList& param_list,
                     NDDS::Security::SPDPdiscoveredParticipantData& participant_data);
#endif

// NDDS::DCPS::DiscoveredWriterData

NDDS_Rtps_Export
void add_DataRepresentationQos(ParameterList& param_list, const DDS::DataRepresentationIdSeq& ids);

NDDS_Rtps_Export
bool to_param_list(const DCPS::DiscoveredWriterData& writer_data,
                   ParameterList& param_list,
                   bool use_xtypes,
                   const XTypes::TypeInformation& type_info,
                   bool map = false /*map IPV4 to IPV6 addr*/);

NDDS_Rtps_Export
bool from_param_list(const ParameterList& param_list,
                     DCPS::DiscoveredWriterData& writer_data,
                     bool use_xtypes,
                     XTypes::TypeInformation& type_info);

// NDDS::DCPS::DiscoveredReaderData

NDDS_Rtps_Export
bool to_param_list(const DCPS::DiscoveredReaderData& reader_data,
                   ParameterList& param_list,
                   bool use_xtypes,
                   const XTypes::TypeInformation& type_info,
                   bool map = false /*map IPV4 to IPV6 addr*/);

NDDS_Rtps_Export
bool from_param_list(const ParameterList& param_list,
                     DCPS::DiscoveredReaderData& reader_data,
                     bool use_xtypes,
                     XTypes::TypeInformation& type_info);

#ifdef NDDS_SECURITY
// DDS::Security::EndpointSecurityInfo

NDDS_Rtps_Export
bool to_param_list(const DDS::Security::EndpointSecurityInfo& info,
                   ParameterList& param_list);

NDDS_Rtps_Export
bool from_param_list(const ParameterList& param_list,
                     DDS::Security::EndpointSecurityInfo& info);

// DDS::Security::DataTags data_tags

NDDS_Rtps_Export
bool to_param_list(const DDS::Security::DataTags& tags,
                   ParameterList& param_list);

NDDS_Rtps_Export
bool from_param_list(const ParameterList& param_list,
                     DDS::Security::DataTags& tags);

// DiscoveredPublication_SecurityWrapper

NDDS_Rtps_Export
bool to_param_list(const DiscoveredPublication_SecurityWrapper& wrapper,
                   ParameterList& param_list,
                   bool use_xtypes,
                   const XTypes::TypeInformation& type_info,
                   bool map = false /*map IPV4 to IPV6 addr*/);

NDDS_Rtps_Export
bool from_param_list(const ParameterList& param_list,
                     DiscoveredPublication_SecurityWrapper& wrapper,
                     bool use_xtypes,
                     XTypes::TypeInformation& type_info);

// DiscoveredSubscription_SecurityWrapper

NDDS_Rtps_Export
bool to_param_list(const DiscoveredSubscription_SecurityWrapper& wrapper,
                   ParameterList& param_list,
                   bool use_xtypes,
                   const XTypes::TypeInformation& type_info,
                   bool map = false /*map IPV4 to IPV6 addr*/);

NDDS_Rtps_Export
bool from_param_list(const ParameterList& param_list,
                     DiscoveredSubscription_SecurityWrapper& wrapper,
                     bool use_xtypes,
                     XTypes::TypeInformation& type_info);

// Extensions for ICE

NDDS_Rtps_Export
bool to_param_list(const ICE::AgentInfoMap& ai_map,
                   ParameterList& param_list);

NDDS_Rtps_Export
bool from_param_list(const ParameterList& param_list,
                     ICE::AgentInfoMap& ai_map);
#endif

}
}
}

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif
