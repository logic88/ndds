/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_GUARDCONDITION_H
#define NDDS_DCPS_GUARDCONDITION_H

#include "dds/DdsDcpsInfrastructureC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ConditionImpl.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace DDS {

class GuardCondition;
typedef GuardCondition* GuardCondition_ptr;
typedef TAO_Objref_Var_T<GuardCondition> GuardCondition_var;

class NDDS_Dcps_Export GuardCondition
  : public virtual DDS::GuardConditionInterf
  , public virtual NDDS::DCPS::ConditionImpl {
public:
  typedef GuardCondition* _ptr_type;
  typedef GuardCondition_var _var_type;

  GuardCondition()
    : trigger_value_(false)
  {}

  virtual ~GuardCondition() {}

  CORBA::Boolean get_trigger_value();

  ReturnCode_t set_trigger_value(CORBA::Boolean value);

  static GuardCondition_ptr _duplicate(GuardCondition_ptr obj);
  static GuardCondition_ptr _narrow(CORBA::Object_ptr obj);

private:
  ACE_Atomic_Op<ACE_Thread_Mutex, CORBA::Boolean> trigger_value_;
};

} // namespace DDS

NDDS_END_VERSIONED_NAMESPACE_DECL

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO {

template<>
struct NDDS_Dcps_Export Objref_Traits<DDS::GuardCondition> {
  static DDS::GuardCondition_ptr duplicate(DDS::GuardCondition_ptr p);
  static void release(DDS::GuardCondition_ptr p);
  static DDS::GuardCondition_ptr nil();
  static CORBA::Boolean marshal(const DDS::GuardCondition_ptr p,
                                TAO_OutputCDR & cdr);
};

} // namespace TAO

TAO_END_VERSIONED_NAMESPACE_DECL

#endif
