/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_MULTICAST_MULTICAST_H
#define NDDS_DCPS_TRANSPORT_MULTICAST_MULTICAST_H

#include "Multicast_Export.h"
#include "dds/Versioned_Namespace.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Multicast_Export MulticastInitializer {
public:
  MulticastInitializer();
};

static MulticastInitializer multicast_init;

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif  /* DCPS_MULTICAST_H */
