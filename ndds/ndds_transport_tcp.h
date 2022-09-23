/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_WAITSET_H
#define NDDS_DCPS_WAITSET_H

#include "LocalObject.h"
#include "Definitions.h"
#include "PoolAllocator.h"
#include "ConditionVariable.h"

#include <dds/DdsDcpsInfrastructureC.h>

#include <ace/Thread_Mutex.h>
#include <ace/Atomic_Op.h>
#include <ace/Recursive_Thread_Mutex.h>

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#ifdef ACE_HAS_CPP11
#  include <atomic>
#else
#  include <ace/Atomic_Op.h>
#endif
NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class ConditionImpl;

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace DDS {

class WaitSet;
typedef WaitSet* WaitSet_ptr;

typedef TAO_Objref_Var_T<WaitSet> WaitSet_var;

class NDDS_Dcps_Export WaitSet
  : public NDDS::DCPS::LocalObject<WaitSetInterf> {
public:
  typedef WaitSet_ptr _ptr_type;
  typedef WaitSet_var _var_type;

  WaitSet()
    : cond_(lock_)
    , waiting_(false)
  {}

  virtual ~WaitSet() {}

  ReturnCode_t wait(ConditionSeq& active_conditions,
                    const Duration_t& timeout);

  ReturnCode_t attach_condition(Condition_ptr cond);

  ReturnCode_t detach_condition(Condition_ptr cond);

  ReturnCode_t get_conditions(ConditionSeq& attached_conditions);

  /// Convenience method for detaching multiple conditions,
  /// for example when shutting down.
  ReturnCode_t detach_conditions(const ConditionSeq& conditions);

  static WaitSet_ptr _duplicate(WaitSet_ptr obj);

  typedef NDDS_SET_CMP(Condition_var, NDDS::DCPS::VarLess<Condition>) ConditionSet;

private:
  ReturnCode_t detach_i(const Condition_ptr cond);
  void signal(Condition_ptr cond);
  friend class NDDS::DCPS::ConditionImpl;

  ACE_Recursive_Thread_Mutex lock_;

  typedef NDDS::DCPS::ConditionVariable<ACE_Recursive_Thread_Mutex> ConditionVariableType;
  ConditionVariableType cond_;

  bool waiting_;
  ConditionSet attached_conditions_;
  ConditionSet signaled_conditions_;
};

} // namespace DDS

NDDS_END_VERSIONED_NAMESPACE_DECL

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO {

#if !defined(DDS_WAITSET__TRAITS_)
#define DDS_WAITSET__TRAITS_

template<>
struct NDDS_Dcps_Export Objref_Traits< ::DDS::WaitSet> {
  static ::DDS::WaitSet_ptr duplicate(::DDS::WaitSet_ptr p);
  static void release(::DDS::WaitSet_ptr p);
  static ::DDS::WaitSet_ptr nil();
  static CORBA::Boolean marshal(const ::DDS::WaitSet_ptr p,
                                TAO_OutputCDR & cdr);
};

#endif /* DDS_WAITSET__TRAITS_ */

} // namespace TAO

TAO_END_VERSIONED_NAMESPACE_DECL

#endif
