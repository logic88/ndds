/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_RECEIVEDDATASAMPLE_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_RECEIVEDDATASAMPLE_H

#include "dds/DCPS/DataSampleHeader.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Message_Block;
ACE_END_VERSIONED_NAMESPACE_DECL

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

/**
 * @class ReceivedDataSample
 *
 * @brief Holds a data sample received by the transport.
 *
 * This is the type of object that is delivered to the
 * TransportReceiveListener objects by the transport.
 * Note that the data sample header has already been
 * demarshalled by the transport, and the ACE_Message_Block (chain)
 * represents the "data" portion of the sample.
 */
class NDDS_Dcps_Export ReceivedDataSample {
public:
  explicit ReceivedDataSample(ACE_Message_Block* payload);

  ReceivedDataSample(const ReceivedDataSample&);

  ReceivedDataSample& operator=(const ReceivedDataSample&);

  ~ReceivedDataSample();

  /// The demarshalled sample header.
  DataSampleHeader header_;

  /// The "data" part (ie, no "header" part) of the sample.
  Message_Block_Ptr sample_;
};

void swap(ReceivedDataSample&, ReceivedDataSample&);

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined(__ACE_INLINE__)
#include "ReceivedDataSample.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_DCPS_RECEIVEDDATASAMPLE_H */
