/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_SENDRESPONSELISTENER_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_SENDRESPONSELISTENER_H

#include "dds/DCPS/dcps_export.h"
#include "TransportSendListener.h"
#include "dds/DCPS/MessageTracker.h"
#include "dds/DCPS/PoolAllocator.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

/**
 * @class SendResponseListener
 *
 * @brief Simple listener to discard response samples.
 *
 * This is a simple listener implementation used to release response
 * samples once they have been either delivered or dropped.  No
 * special actions are taken to distinguish between the two results.
 */
class NDDS_Dcps_Export SendResponseListener
  : public TransportSendListener {
public:
  explicit SendResponseListener(const NDDS_STRING& msg_src);
  virtual ~SendResponseListener();

  virtual void data_delivered(const DataSampleElement* sample);
  virtual void data_dropped(const DataSampleElement* sample,
                            bool dropped_by_transport);

  virtual void control_delivered(const Message_Block_Ptr& sample);
  virtual void control_dropped(const Message_Block_Ptr& sample,
                               bool dropped_by_transport);

  void notify_publication_disconnected(const ReaderIdSeq&) {}
  void notify_publication_reconnected(const ReaderIdSeq&) {}
  void notify_publication_lost(const ReaderIdSeq&) {}
  void remove_associations(const ReaderIdSeq&, bool) {}
  void replay_durable_data_for(const RepoId&) {}

  void track_message();

private:
  void _add_ref() {}
  void _remove_ref() {}

  MessageTracker tracker_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* NDDS_DCPS_SENDRESPONSELISTENER_H */
