/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_SHMEM_SHMEM_H
#define NDDS_DCPS_TRANSPORT_SHMEM_SHMEM_H

#include "Shmem_Export.h"
#include "dds/Versioned_Namespace.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Shmem_Export ShmemInitializer {
public:
  ShmemInitializer();
};

static ShmemInitializer shmem_init;

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif  /* NDDS_SHMEM_H */
