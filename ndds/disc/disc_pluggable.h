/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_INFOREPODISCOVERY_FAILOVERLISTENER_H
#define NDDS_DCPS_INFOREPODISCOVERY_FAILOVERLISTENER_H

#include "dds/DdsDcpsSubscriptionExtC.h"
#include "dds/DCPS/Definitions.h"
#include "dds/DCPS/LocalObject.h"
#include "dds/DCPS/Discovery.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

/// @class FailoverListener
class FailoverListener
  : public virtual NDDS::DCPS::LocalObject<NDDS::DCPS::DataReaderListener> {
public:
  /// Only construct with a repository key value.
  FailoverListener(Discovery::RepoKey key);

  /// Virtual destructor
  virtual ~FailoverListener();

  virtual void on_requested_deadline_missed(
    DDS::DataReader_ptr reader,
    const DDS::RequestedDeadlineMissedStatus & status);

  virtual void on_requested_incompatible_qos(
    DDS::DataReader_ptr reader,
    const DDS::RequestedIncompatibleQosStatus & status);

  virtual void on_liveliness_changed(
    DDS::DataReader_ptr reader,
    const DDS::LivelinessChangedStatus & status);

  virtual void on_subscription_matched(
    DDS::DataReader_ptr reader,
    const DDS::SubscriptionMatchedStatus & status);

  virtual void on_sample_rejected(
    DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& status);

  virtual void on_data_available(
    DDS::DataReader_ptr reader);

  virtual void on_sample_lost(
    DDS::DataReader_ptr reader,
    const DDS::SampleLostStatus& status);

  virtual void on_subscription_disconnected(
    DDS::DataReader_ptr reader,
    const NDDS::DCPS::SubscriptionDisconnectedStatus& status);

  virtual void on_subscription_reconnected(
    DDS::DataReader_ptr reader,
    const NDDS::DCPS::SubscriptionReconnectedStatus& status);

  virtual void on_subscription_lost(
    DDS::DataReader_ptr reader,
    const NDDS::DCPS::SubscriptionLostStatus& status);

  virtual void on_budget_exceeded(
    DDS::DataReader_ptr reader,
    const NDDS::DCPS::BudgetExceededStatus& status);

private:
  /// Our repository key.  If we trigger, this is the key to the
  /// repository that has been lost.
  Discovery::RepoKey key_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* FAILOVERLISTENER_T_H  */
