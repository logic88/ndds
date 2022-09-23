/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_INFOREPODISCOVERY_DATAREADERREMOTEIMPL_H
#define NDDS_DCPS_INFOREPODISCOVERY_DATAREADERREMOTEIMPL_H

#include "InfoRepoDiscovery_Export.h"
#include "DataReaderRemoteS.h"
#include "dds/DCPS/RcHandle_T.h"
#include "dds/DCPS/Definitions.h"
#include "dds/DCPS/RcObject.h"
#include "dds/DCPS/DataReaderCallbacks.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

/**
* @class DataReaderRemoteImpl
*
* @brief Implements the NDDS::DCPS::ReaderRemote interface that
*        is used to add and remove associations.
*
*/
class DataReaderRemoteImpl
  : public virtual POA_NDDS::DCPS::DataReaderRemote {
public:

  explicit DataReaderRemoteImpl(DataReaderCallbacks& parent);

  virtual ~DataReaderRemoteImpl();

  virtual void add_association(const RepoId& yourId,
                               const WriterAssociation& writer,
                               bool active);

  virtual void remove_associations(const WriterIdSeq& writers,
                                   CORBA::Boolean callback);

  virtual void update_incompatible_qos(const IncompatibleQosStatus& status);

  void detach_parent();

private:
  WeakRcHandle<DataReaderCallbacks> parent_;
};

NDDS_END_VERSIONED_NAMESPACE_DECL

} // namespace DCPS
} // namespace NDDS

#endif /* NDDS_DCPS_DATAREADERREMOTEIMPL_H  */
