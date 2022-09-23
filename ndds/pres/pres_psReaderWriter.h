/*
 * Distributed under the NDDS License.
 * See: http://www.NDDS.org/license.html
 */

#ifndef NDDS_DCPS_SECURITY_ACCESSCONTROL_GOVERNANCE_H
#define NDDS_DCPS_SECURITY_ACCESSCONTROL_GOVERNANCE_H

#include "DomainIdSet.h"

#include <dds/DCPS/security/SSL/SignedDocument.h>
#include <dds/DCPS/RcObject.h>

#include <dds/DdsSecurityCoreC.h>

#include <string>
#include <vector>

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace Security {

class Governance : public DCPS::RcObject {
public:
  typedef DCPS::RcHandle<Governance> shared_ptr;

  struct TopicAccessRule {
    TopicAccessRule();
    std::string topic_expression;
    DDS::Security::TopicSecurityAttributes topic_attrs;
    std::string metadata_protection_kind;
    std::string data_protection_kind;
  };

  typedef std::vector<TopicAccessRule> TopicAccessRules;

  struct DomainRule {
    DomainIdSet domains;
    DDS::Security::ParticipantSecurityAttributes domain_attrs;
    TopicAccessRules topic_rules;
  };

  typedef std::vector<DomainRule> GovernanceAccessRules;

  Governance();

  int load(const SSL::SignedDocument& doc);

  GovernanceAccessRules& access_rules()
  {
    return access_rules_;
  }

private:
  GovernanceAccessRules access_rules_;
};

}
}

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif
