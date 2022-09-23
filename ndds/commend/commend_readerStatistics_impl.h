#ifndef NDDS_DCPS_XTYPES_TYPE_DESCRIPTOR_H
#define NDDS_DCPS_XTYPES_TYPE_DESCRIPTOR_H

#include "TypeObject.h"

#include <dds/DCPS/RcObject.h>
#include <dds/DCPS/RcHandle_T.h>

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace NDDS {
namespace XTypes {

class DynamicType;
class DynamicTypeMember;
typedef DCPS::RcHandle<DynamicTypeMember> DynamicTypeMember_rch;
typedef NDDS_MAP(DCPS::String, DynamicTypeMember_rch) DynamicTypeMembersByName;
typedef NDDS_MAP(MemberId, DynamicTypeMember_rch) DynamicTypeMembersById;
typedef NDDS_VECTOR(DynamicTypeMember_rch) DynamicTypeMembersByIndex;
typedef std::pair<const DynamicType*, const DynamicType*> DynamicTypePtrPair;
typedef NDDS_SET(DynamicTypePtrPair) DynamicTypePtrPairSeen;
typedef DCPS::RcHandle<DynamicType> DynamicType_rch;

enum ExtensibilityKind {
  FINAL,
  APPENDABLE,
  MUTABLE
};

class NDDS_Dcps_Export TypeDescriptor {
public:
  TypeDescriptor();

  ~TypeDescriptor();

  bool equals(const TypeDescriptor& other) const;

  TypeKind kind;
  DCPS::String name;
  DynamicType_rch base_type;
  DynamicType_rch discriminator_type;
  LBoundSeq bound;
  DynamicType_rch element_type;
  DynamicType_rch key_element_type;
  ExtensibilityKind extensibility_kind;
  bool is_nested;
};

inline bool operator==(const LBoundSeq& lhs, const LBoundSeq& rhs)
{
  if (lhs.length() == rhs.length()) {
    for (ACE_CDR::ULong i = 0 ; i < lhs.length() ; ++i) {
      if (lhs[i] != rhs[i]) {
        return false;
      }
    }
    return true;
  }
  return false;
}

bool test_equality_i(const TypeDescriptor& lhs, const TypeDescriptor& rhs, DynamicTypePtrPairSeen& dt_ptr_pair);

} // namespace XTypes
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif  /* NDDS_DCPS_XTYPES_TYPE_DESCRIPTOR_H */
