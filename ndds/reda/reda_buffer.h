/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_DIRECTPRIORITYMAPPER_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_DIRECTPRIORITYMAPPER_H

#include "dds/DCPS/dcps_export.h"

#include "PriorityMapper.h"
#include "ace/OS_NS_Thread.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

/**
 * @class DirectPriorityMapper
 *
 * @brief map TRANSPORT_PRIORITY values directly.
 *
 * This implementation maps TRANSPORT_PRIORITY values directly to
 * both DiffServ codepoint and thread priority values.  The behavior
 * is saturating - that is when the TRANSPORT_PRIORITY value is out
 * of the target range, it is mapped to the nearest extremum.
 *
 * DiffServ codepoint values are mapped within the closed interval
 * [0,63], with the corresponding TRANSPORT_PRIORITY values mapped
 * directly within this range.
 *
 * Thread priorities are mapped to the system thread scheduler
 * minimum value (obtained from the sched_get_priority_min(sched)
 * system call, where available) up to the maximum value (obtained
 * from the sched_get_priority_max(sched) system call, where
 * available).  The TRANSPORT_PRIORITY value of 0 is mapped to the
 * minimum and a value of |max-min| is mapped to the maximum.
 */
class NDDS_Dcps_Export DirectPriorityMapper : public PriorityMapper {
public:
  /// Construct with a priority value.
  DirectPriorityMapper(Priority priority = 0);

  virtual ~DirectPriorityMapper();

  /// Access the mapped DiffServ codepoint value.
  virtual short codepoint() const;

  /// Access the mapped thread priority value.
  virtual short thread_priority() const;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "DirectPriorityMapper.inl"
#endif /* __ACE_INLINE__ */

#endif  /* DIRECTPRIORITY_MAPPER_H */
