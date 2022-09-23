/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_INFOREPODISCOVERY_DATAWRITERREMOTEIMPL_H
#define NDDS_DCPS_INFOREPODISCOVERY_DATAWRITERREMOTEIMPL_H

#include "DataWriterRemoteS.h"
#include "dds/DCPS/Definitions.h"
#include "dds/DCPS/RcHandle_T.h"
#include "dds/DCPS/DataWriterCallbacks.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {


/**
* @class DataWriterRemoteImpl
*
* @brief Implements the NDDS::DCPS::DataWriterRemote interface.
*
*/
class DataWriterRemoteImpl
  : public virtual POA_NDDS::DCPS::DataWriterRemote {
public:
  explicit DataWriterRemoteImpl(DataWriterCallbacks& parent);

  virtual ~DataWriterRemoteImpl();

  virtual void add_association(const RepoId& yourId,
                               const ReaderAssociation& readers,
                               bool active);

  virtual void remove_associations(const ReaderIdSeq& readers,
                                   CORBA::Boolean callback);

  virtual void update_incompatible_qos(const IncompatibleQosStatus& status);

  virtual void update_subscription_params(const RepoId& readerId,
                                          const DDS::StringSeq& exprParams);

  void detach_parent();

private:
  WeakRcHandle<DataWriterCallbacks> parent_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif
