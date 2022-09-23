/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TYPESUPPORTIMPL_H
#define NDDS_DCPS_TYPESUPPORTIMPL_H

#include "dcps_export.h"
#include "Definitions.h"
#include "LocalObject.h"
#include "Serializer.h"
#include "SafetyProfileStreams.h"
#include "XTypes/TypeObject.h"

#include <dds/DdsDcpsTypeSupportExtC.h>

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace XTypes {
class TypeLookupService;
}

namespace DCPS {

class MetaStruct;

template <typename Message> struct DDSTraits;

template <typename Message> struct MarshalTraits;

class NDDS_Dcps_Export SerializedSizeBound {
public:
  SerializedSizeBound()
  : bounded_(false)
  , bound_(0)
  {
  }

  SerializedSizeBound(size_t bound)
  : bounded_(true)
  , bound_(bound)
  {
  }

  operator bool() const
  {
    return bounded_;
  }

  size_t get() const
  {
    NDDS_ASSERT(bounded_);
    return bound_;
  }

  NDDS_STRING to_string() const
  {
    return bounded_ ? to_dds_string(bound_) : "<unbounded>";
  }

private:
  bool bounded_;
  size_t bound_;
};

class NDDS_Dcps_Export TypeSupportImpl
  : public virtual LocalObject<TypeSupport> {
public:
  TypeSupportImpl() {}

  virtual ~TypeSupportImpl();

#ifndef NDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
  virtual const MetaStruct& getMetaStructForType() = 0;
#endif

  virtual DDS::ReturnCode_t register_type(DDS::DomainParticipant_ptr participant,
                                          const char* type_name);

  virtual DDS::ReturnCode_t unregister_type(DDS::DomainParticipant_ptr participant,
                                            const char* type_name);

  virtual char* get_type_name();

  /// Get allowed representations defined by IDL annotations
  virtual void representations_allowed_by_type(
    DDS::DataRepresentationIdSeq& seq) = 0;

  virtual const XTypes::TypeIdentifier& getMinimalTypeIdentifier() const = 0;
  virtual const XTypes::TypeMap& getMinimalTypeMap() const = 0;
  virtual const XTypes::TypeIdentifier& getCompleteTypeIdentifier() const = 0;
  virtual const XTypes::TypeMap& getCompleteTypeMap() const = 0;

  virtual Extensibility getExtensibility() const = 0;

  void to_type_info(XTypes::TypeInformation& type_info) const;

  void add_types(const RcHandle<XTypes::TypeLookupService>& tls) const;
  void populate_dependencies(const RcHandle<XTypes::TypeLookupService>& tls) const;

private:
  static const ACE_CDR::Long TYPE_INFO_DEPENDENT_COUNT_NOT_PROVIDED;

  virtual const char* default_type_name() const = 0;

  void to_type_info_i(XTypes::TypeIdentifierWithDependencies& ti_with_deps,
                      const XTypes::TypeIdentifier& ti,
                      const XTypes::TypeMap& type_map) const;

  void populate_dependencies_i(const RcHandle<XTypes::TypeLookupService>& tls,
                               XTypes::EquivalenceKind ek) const;

  NDDS_DELETED_COPY_MOVE_CTOR_ASSIGN(TypeSupportImpl)

};

const char* kind_to_string(const XTypes::EquivalenceKind ek);

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif
