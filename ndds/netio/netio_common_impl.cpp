/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "DCPS/DdsDcps_pch.h" //Only the _pch include should start with DCPS/

#include "dds/DdsDcpsGuidC.h"

#include "InstanceHandle.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

InstanceHandleGenerator::InstanceHandleGenerator(long begin)
  : sequence_(begin)
{
}

InstanceHandleGenerator::~InstanceHandleGenerator()
{
}

DDS::InstanceHandle_t
InstanceHandleGenerator::next()
{
  return ++sequence_;
}

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL
