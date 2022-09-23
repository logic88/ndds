/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "FailoverListener.h"
#include "dds/DCPS/Service_Participant.h"
#include "dds/DCPS/debug.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

FailoverListener::FailoverListener(Discovery::RepoKey key)
  : key_(key)
{
  if (NDDS::DCPS::DCPS_debug_level > 0) {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("(%P|%t) FailoverListener::FailoverListener( key==%C)\n"),
               key.c_str()));
  }
}

FailoverListener::~FailoverListener()
{
  if (NDDS::DCPS::DCPS_debug_level > 0) {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("(%P|%t) FailoverListener::~FailoverListener\n")));
  }
}

void
FailoverListener::on_data_available(
  DDS::DataReader_ptr /* reader */)
{
  if (NDDS::DCPS::DCPS_debug_level > 0) {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("(%P|%t) FailoverListener::on_data_available\n")));
  }
}

void
FailoverListener::on_requested_deadline_missed(
  DDS::DataReader_ptr /* reader */,
  const DDS::RequestedDeadlineMissedStatus & /* status */)
{
  if (NDDS::DCPS::DCPS_debug_level > 0) {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("(%P|%t) ")
               ACE_TEXT("Federatorer::on_requested_deadline_missed\n")));
  }
}

void
FailoverListener::on_requested_incompatible_qos(
  DDS::DataReader_ptr /* reader */,
  const DDS::RequestedIncompatibleQosStatus & /* status */)
{
  if (NDDS::DCPS::DCPS_debug_level > 0) {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("(%P|%t) FailoverListener::")
               ACE_TEXT("on_requested_incompatible_qos\n")));
  }
}

void
FailoverListener::on_liveliness_changed(
  DDS::DataReader_ptr /* reader */,
  const DDS::LivelinessChangedStatus & /* status */)
{
  if (NDDS::DCPS::DCPS_debug_level > 0) {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("(%P|%t) FailoverListener::on_liveliness_changed\n")));
  }
}

void
FailoverListener::on_subscription_matched(
  DDS::DataReader_ptr /* reader */,
  const DDS::SubscriptionMatchedStatus & /* status */)
{
  if (NDDS::DCPS::DCPS_debug_level > 0) {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("(%P|%t) FailoverListener::on_subscription_matched\n")));
  }
}

void
FailoverListener::on_sample_rejected(
  DDS::DataReader_ptr /* reader */,
  const DDS::SampleRejectedStatus& /* status */)
{
  if (NDDS::DCPS::DCPS_debug_level > 0) {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("(%P|%t) FailoverListener::on_sample_rejected\n")));
  }
}

void
FailoverListener::on_sample_lost(
  DDS::DataReader_ptr /* reader */,
  const DDS::SampleLostStatus& /* status */)
{
  if (NDDS::DCPS::DCPS_debug_level > 0) {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("(%P|%t) FailoverListener::on_sample_lost\n")));
  }
}

void
FailoverListener::on_subscription_disconnected(
  DDS::DataReader_ptr /* reader */,
  const NDDS::DCPS::SubscriptionDisconnectedStatus& /* status */)
{
  if (NDDS::DCPS::DCPS_debug_level > 0) {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("(%P|%t) FailoverListener::on_subscription_disconnected\n")));
  }
  TheServiceParticipant->repository_lost(this->key_);
}

void
FailoverListener::on_subscription_reconnected(
  DDS::DataReader_ptr /* reader */,
  const NDDS::DCPS::SubscriptionReconnectedStatus& /* status */)
{
  if (NDDS::DCPS::DCPS_debug_level > 0) {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("(%P|%t) FailoverListener::on_subscription_reconnected\n")));
  }
}

void
FailoverListener::on_subscription_lost(
  DDS::DataReader_ptr /* reader */,
  const NDDS::DCPS::SubscriptionLostStatus& /* status */)
{
  if (NDDS::DCPS::DCPS_debug_level > 0) {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("(%P|%t) FailoverListener::on_subscription_lost: ")
               ACE_TEXT("initiating failover sequencing.\n")));
  }

  TheServiceParticipant->repository_lost(this->key_);
}


void
FailoverListener::on_budget_exceeded(
  DDS::DataReader_ptr /* reader */,
  const NDDS::DCPS::BudgetExceededStatus& /* status */)
{
  if (NDDS::DCPS::DCPS_debug_level > 0) {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("(%P|%t) FailoverListener::on_budget_exceeded\n")));
  }
}

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL
