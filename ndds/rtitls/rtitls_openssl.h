/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_DATALINKCLEANUPTASK_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_DATALINKCLEANUPTASK_H

#include /**/ "ace/pre.h"

#include "QueueTaskBase_T.h"
#include "DataLink.h"
#include "DataLink_rch.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class TransportImpl;

/**
 * @class DataLinkCleanupTask
 *
 * @brief Active Object responsible for cleaning up DataLink resources.
 *
 */
class NDDS_Dcps_Export DataLinkCleanupTask : public QueueTaskBase <DataLink_rch> {
public:
  DataLinkCleanupTask();

  virtual ~DataLinkCleanupTask();

  /// Handle reconnect requests.
  virtual void execute(DataLink_rch& dl);
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* NDDS_DCPS_DATALINKCLEANUP_H */
