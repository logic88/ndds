/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef DCPS_IR_SUBSCRIPTION_H
#define DCPS_IR_SUBSCRIPTION_H

#include  "inforepo_export.h"
#include /**/ "UpdateDataTypes.h"
#include /**/ "dds/DdsDcpsInfrastructureC.h"
#include /**/ "dds/DdsDcpsSubscriptionC.h"
#include /**/ "dds/DCPS/InfoRepoDiscovery/InfoC.h"
#include /**/ "dds/DCPS/InfoRepoDiscovery/DataReaderRemoteC.h"
#include /**/ "ace/Unbounded_Set.h"
#include "dds/DCPS/unique_ptr.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

// forward declarations
class DCPS_IR_Publication;
typedef ACE_Unbounded_Set<DCPS_IR_Publication*> DCPS_IR_Publication_Set;

class DCPS_IR_Participant;
class DCPS_IR_Topic_Description;
class DCPS_IR_Topic;

/**
 * @class DCPS_IR_Subscription
 *
 * @brief Representative of a Subscription
 *
 *
 */
class NDDS_InfoRepoLib_Export DCPS_IR_Subscription
: public NDDS::DCPS::EnableContainerSupportedUniquePtr<DCPS_IR_Subscription> {
public:
  DCPS_IR_Subscription(const NDDS::DCPS::RepoId& id,
                       DCPS_IR_Participant* participant,
                       DCPS_IR_Topic* topic,
                       NDDS::DCPS::DataReaderRemote_ptr reader,
                       const DDS::DataReaderQos& qos,
                       const NDDS::DCPS::TransportLocatorSeq& info,
                       ACE_CDR::ULong transportContext,
                       const DDS::SubscriberQos& subscriberQos,
                       const char* filterClassName,
                       const char* filterExpression,
                       const DDS::StringSeq& exprParams,
                       const DDS::OctetSeq & serializedTypeInfo);

  ~DCPS_IR_Subscription();

  /// Associate with the publication
  /// Adds the publication to the list of associated
  ///  publications and notifies datareader if successfully added
  /// This method can mark the participant dead
  /// Returns 0 if added, 1 if already exists, -1 other failure
  int add_associated_publication(DCPS_IR_Publication* pub, bool active);

  /// Remove the associated publication
  /// Removes the publication from the list of associated
  ///  publications if return successful
  /// sendNotify indicates whether to tell the datareader about
  ///  removing the publication
  /// The notify_lost flag true indicates this remove_associations is called
  /// when the InfoRepo detects this subscription is lost because of the failure
  /// of invocation on this subscription.
  /// The notify_both_side parameter indicates if it needs call pub to remove
  /// association as well.
  /// This method can mark the participant dead
  /// Returns 0 if successful
  int remove_associated_publication(DCPS_IR_Publication* pub,
                                    CORBA::Boolean sendNotify,
                                    CORBA::Boolean notify_lost,
                                    bool notify_both_side = false);

  /// Removes all the associated publications
  /// This method can mark the participant dead
  /// The notify_lost flag true indicates this remove_associations is called
  /// when the InfoRepo detects this subscription is lost because of the failure
  /// of invocation on this subscription.
  /// Returns 0 if successful
  int remove_associations(CORBA::Boolean notify_lost);

  /// Remove any publications whose participant has the id
  void disassociate_participant(NDDS::DCPS::RepoId id,
                                bool reassociate = false);

  /// Remove any publications whose topic has the id
  void disassociate_topic(NDDS::DCPS::RepoId id);

  /// Remove any publications with id
  void disassociate_publication(NDDS::DCPS::RepoId id,
                                bool reassociate = false);

  /// Notify the reader of incompatible qos status
  ///  and reset the status' count_since_last_send to 0
  void update_incompatible_qos();

  /// Check that none of the ids given are ones that
  ///  this subscription should ignore.
  /// returns 1 if one of these ids is an ignored id
  CORBA::Boolean is_publication_ignored(NDDS::DCPS::RepoId partId,
                                        NDDS::DCPS::RepoId topicId,
                                        NDDS::DCPS::RepoId pubId);

  /// Return pointer to the DataReader qos
  /// Subscription retains ownership
  const DDS::DataReaderQos* get_datareader_qos();

  /// Return pointer to the Subscriber qos
  /// Subscription retains ownership
  const DDS::SubscriberQos* get_subscriber_qos();

  /// Update the DataReader or Subscriber qos and also publish the qos
  /// changes to datereader BIT.
  bool set_qos(const DDS::DataReaderQos & qos,
               const DDS::SubscriberQos & subscriberQos,
               Update::SpecificQos& specificQos);

  /// Update DataReaderQos only.
  void set_qos(const DDS::DataReaderQos& qos);

  /// Update SubscriberQos only.
  void set_qos(const DDS::SubscriberQos& qos);

  void reevaluate_defunct_associations();

  // Verify the existing associations. This may result removal of
  // associations. The existing associations have to be removed before
  // adding new association and may need some delay. Otherwise, if
  // two DataWriters uses same Datalink and add an association happens
  // before remove an association then the new association will fail to
  // connect.
  void reevaluate_existing_associations();

  // Re-evaluate the association between this subscription and the provided
  // publication. If they are already associated and not compatible then
  // they will be dis-associated. If they are not already associated then
  // the new association will be added.
  bool reevaluate_association(DCPS_IR_Publication* publication);

  NDDS::DCPS::TransportLocatorSeq get_transportLocatorSeq() const;
  ACE_CDR::ULong get_transportContext() const { return transportContext_; }

  /// Return pointer to the incompatible qos status
  /// Subscription retains ownership
  NDDS::DCPS::IncompatibleQosStatus* get_incompatibleQosStatus();

  NDDS::DCPS::RepoId get_id();
  NDDS::DCPS::RepoId get_topic_id();
  NDDS::DCPS::RepoId get_participant_id();

  DCPS_IR_Topic_Description* get_topic_description();

  DCPS_IR_Topic* get_topic();

  DDS::InstanceHandle_t get_handle();
  void set_handle(DDS::InstanceHandle_t handle);

  CORBA::Boolean is_bit();
  void set_bit_status(CORBA::Boolean isBIT);

  // Expose the datareader.
  NDDS::DCPS::DataReaderRemote_ptr reader();

  std::string get_filter_class_name() const;
  std::string get_filter_expression() const;
  DDS::StringSeq get_expr_params() const;

  /// Calls associated Publications
  void update_expr_params(const DDS::StringSeq& params);

  std::string dump_to_string(const std::string& prefix, int depth) const;


  const DDS::OctetSeq& get_serialized_type_info() const;

private:
  NDDS::DCPS::RepoId id_;
  DCPS_IR_Participant* participant_;
  DCPS_IR_Topic* topic_;
  DDS::InstanceHandle_t handle_;
  CORBA::Boolean isBIT_;

  /// the corresponding DataReaderRemote object
  NDDS::DCPS::DataReaderRemote_var reader_;
  DDS::DataReaderQos qos_;
  NDDS::DCPS::TransportLocatorSeq info_;
  ACE_CDR::ULong transportContext_;
  DDS::SubscriberQos subscriberQos_;
  std::string filterClassName_;
  std::string filterExpression_;
  DDS::StringSeq exprParams_;
  DDS::OctetSeq serializedTypeInfo_;
  DCPS_IR_Publication_Set associations_;
  DCPS_IR_Publication_Set defunct_;

  NDDS::DCPS::IncompatibleQosStatus incompatibleQosStatus_;
};

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* DCPS_IR_SUBSCRIPTION_H */
