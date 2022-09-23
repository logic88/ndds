/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_TRANSPORTRECEIVELISTENER_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_TRANSPORTRECEIVELISTENER_H

#include "dds/DCPS/dcps_export.h"
#include "dds/DdsDcpsInfoUtilsC.h"
#include "dds/DCPS/RcHandle_T.h"
#include "dds/DCPS/RcObject.h"
NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class ReceivedDataSample;
class WriterIdSeq;

class NDDS_Dcps_Export TransportReceiveListener
  : public virtual RcObject {
public:

  virtual ~TransportReceiveListener();

  virtual void data_received(const ReceivedDataSample& sample) = 0;

  virtual void notify_subscription_disconnected(const WriterIdSeq& pubids) = 0;
  virtual void notify_subscription_reconnected(const WriterIdSeq& pubids) = 0;
  virtual void notify_subscription_lost(const WriterIdSeq& pubids) = 0;

  virtual void remove_associations(const WriterIdSeq& pubids, bool notify) = 0;

  virtual void transport_discovery_change() {}

protected:

  TransportReceiveListener();
};

typedef RcHandle<TransportReceiveListener> TransportReceiveListener_rch;

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* NDDS_DCPS_TRANSPORTRECEIVELISTENER_H */
