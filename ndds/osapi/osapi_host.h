/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_MULTITOPICIMPL_H
#define NDDS_DCPS_MULTITOPICIMPL_H

#ifndef NDDS_NO_MULTI_TOPIC

#include "TopicDescriptionImpl.h"
#include "FilterEvaluator.h"

#include "PoolAllocator.h"
#include <utility>

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class NDDS_Dcps_Export MultiTopicImpl
  : public virtual NDDS::DCPS::LocalObject<DDS::MultiTopic>
  , public virtual TopicDescriptionImpl {
public:
  MultiTopicImpl(const char* name, const char* type_name,
    const char* subscription_expression,
    const DDS::StringSeq& expression_parameters,
    DomainParticipantImpl* participant);

  virtual ~MultiTopicImpl();

  char* get_subscription_expression();

  DDS::ReturnCode_t get_expression_parameters(DDS::StringSeq& parameters);

  DDS::ReturnCode_t set_expression_parameters(const DDS::StringSeq& parameters);

  struct SubjectFieldSpec {
    NDDS_STRING incoming_name_;
    NDDS_STRING resulting_name_;

    explicit SubjectFieldSpec(const NDDS_STRING& inc,
                              const NDDS_STRING& res = "")
      : incoming_name_(inc)
      , resulting_name_(res == "" ? inc : res)
    {}
  };

  const std::vector<SubjectFieldSpec>& get_aggregation() const
  {
    return aggregation_;
  }

  const std::vector<NDDS_STRING>& get_selection() const
  {
    return selection_;
  }

  template<typename Sample>
  bool filter(const Sample& s) const
  {
    if (!filter_eval_) return true;
    ACE_GUARD_RETURN(ACE_Recursive_Thread_Mutex, guard, lock_, false);
    return filter_eval_->eval(s, expression_parameters_);
  }

private:
  NDDS_STRING subscription_expression_;
  DDS::StringSeq expression_parameters_;
  unique_ptr<FilterEvaluator> filter_eval_;

  std::vector<SubjectFieldSpec> aggregation_;
  std::vector<NDDS_STRING> selection_;

  /// Concurrent access to expression_parameters_
  mutable ACE_Recursive_Thread_Mutex lock_;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif // NDDS_NO_MULTI_TOPIC

#endif
