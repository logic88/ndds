/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_TRANSPORTSENDLISTENER_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_TRANSPORTSENDLISTENER_H

#include "dds/DCPS/dcps_export.h"
#include "dds/DCPS/RcHandle_T.h"
#include "dds/DdsDcpsInfoUtilsC.h"
#include "dds/DCPS/Message_Block_Ptr.h"
#include "TransportDefs.h"
#include "dds/DCPS/RcObject.h"
#include "dds/DCPS/PoolAllocator.h"
#include "dds/DCPS/SequenceNumber.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Message_Block;
ACE_END_VERSIONED_NAMESPACE_DECL

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class DataSampleElement;
struct DataSampleHeader;
typedef ACE_Message_Block DataSample;

class DataLinkSet;
typedef RcHandle<DataLinkSet> DataLinkSet_rch;

class ReaderIdSeq;

class NDDS_Dcps_Export TransportSendListener
  : public virtual RcObject {
public:

  virtual ~TransportSendListener();

  virtual void data_delivered(const DataSampleElement* sample);
  virtual void data_dropped(const DataSampleElement* sample,
                            bool dropped_by_transport);

  virtual void data_acked(const GUID_t&) {}

  virtual void control_delivered(const Message_Block_Ptr& sample);
  virtual void control_dropped(const Message_Block_Ptr& sample,
                               bool dropped_by_transport);

  virtual void notify_publication_disconnected(const ReaderIdSeq& subids) = 0;
  virtual void notify_publication_reconnected(const ReaderIdSeq& subids) = 0;
  virtual void notify_publication_lost(const ReaderIdSeq& subids) = 0;

  virtual void remove_associations(const ReaderIdSeq& subids, bool notify) = 0;

  virtual void replay_durable_data_for(const RepoId&) {}

  /// Hook for the listener to override a normal control message with
  /// customized messages to different DataLinks.
  virtual SendControlStatus send_control_customized(
    const DataLinkSet_rch& links,
    const DataSampleHeader& header,
    ACE_Message_Block* msg,
    void* extra);

  struct InlineQosData {
    DDS::PublisherQos  pub_qos;
    DDS::DataWriterQos dw_qos;
    NDDS_STRING     topic_name;
  };

  virtual void retrieve_inline_qos_data(InlineQosData& qos_data) const;

  virtual void transport_discovery_change() {}

protected:

  TransportSendListener();
};

typedef RcHandle<TransportSendListener> TransportSendListener_rch;

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* NDDS_DCPS_TRANSPORTSENDLISTENER_H */
