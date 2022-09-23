/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSPORT_FRAMEWORK_TRANSPORTREGISTRY_H
#define NDDS_DCPS_TRANSPORT_FRAMEWORK_TRANSPORTREGISTRY_H

#include "dds/DCPS/dcps_export.h"
#include "TransportDefs.h"
#include "TransportImpl_rch.h"
#include "dds/DCPS/ReactorTask_rch.h"
#include "TransportType.h"
#include "TransportType_rch.h"
#include "TransportInst_rch.h"
#include "TransportConfig_rch.h"
#include "TransportConfig.h"
#include "dds/DCPS/PoolAllocator.h"
#include "dds/DCPS/ConfigUtils.h"
#include "dds/DdsDcpsInfrastructureC.h"
#include "ace/Synch_Traits.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Configuration_Heap;
ACE_END_VERSIONED_NAMESPACE_DECL

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace DDS {
  class Entity;
  typedef Entity* Entity_ptr;
}

#define TheTransportRegistry NDDS::DCPS::TransportRegistry::instance()

namespace NDDS {
namespace DCPS {

/**
 * The TransportRegistry is a singleton object which provides a mechanism to
 * the application code to configure NDDS's use of the transport layer.
 */
class NDDS_Dcps_Export TransportRegistry {
public:

  /// Return a singleton instance of this class.
  static TransportRegistry* instance();

  /// Close the singleton instance of this class.
  static void close();

  /// This will shutdown all TransportImpl objects.
  ///
  /// Client Application calls this method to tear down the transport
  /// framework.
  void release();

  TransportInst_rch create_inst(const NDDS_STRING& name,
                                const NDDS_STRING& transport_type,
                                bool wait = true);
  TransportInst_rch get_inst(const NDDS_STRING& name) const;

  /// Removing a TransportInst from the registry shuts down the underlying
  /// transport implementation (if one was started) and therefore should only
  /// be attempted after DDS Entities using this transport have been deleted.
  void remove_inst(const TransportInst_rch& inst);
  void remove_inst(const NDDS_STRING& inst_name);

  static const char DEFAULT_CONFIG_NAME[];
  static const char DEFAULT_INST_PREFIX[];

  TransportConfig_rch create_config(const NDDS_STRING& name);
  TransportConfig_rch get_config(const NDDS_STRING& name) const;
  void remove_config(const TransportConfig_rch& cfg);
  void remove_config(const NDDS_STRING& config_name);

  void remove_transport_template_instance(const NDDS_STRING& config_name);

  TransportConfig_rch global_config() const;
  void global_config(const TransportConfig_rch& cfg);

  void domain_default_config(DDS::DomainId_t domain,
                             const TransportConfig_rch& cfg);
  TransportConfig_rch domain_default_config(DDS::DomainId_t domain) const;

  void bind_config(const NDDS_STRING& name, DDS::Entity_ptr entity);
  void bind_config(const TransportConfig_rch& cfg, DDS::Entity_ptr entity);

  /// SPI (Service Provider Interface) for specific transport types:
  /// This function is called as the concrete transport library is
  /// loaded.  The concrete transport library creates a concrete
  /// transport type object and registers it with TransportRegistry
  /// singleton.  Returns true for success.
  bool register_type(const TransportType_rch& type);

  /// For internal use by NDDS DCPS layer:
  /// Transfer the configuration in ACE_Configuration_Heap object to
  /// the TransportRegistry. This is called by the Service_Participant
  /// at initialization time. This function iterates each section in
  /// the configuration file, and creates TransportInst and
  /// TransportConfig objects and adds them to the registry.
  int load_transport_configuration(const NDDS_STRING& file_name,
                                   ACE_Configuration_Heap& cf);

  /// For internal use by NDDS DCPS layer:
  /// Process the transport_template configuration in the
  /// ACE_Configuration_Heap object.
  /// Called by the Service_Participant at initialization time.
  int load_transport_templates(ACE_Configuration_Heap& cf);

  /// For internal use by NDDS DCPS layer:
  /// If the default config is empty when it's about to be used, allow the
  /// TransportRegistry to attempt to load a fallback option.
  TransportConfig_rch fix_empty_default();

  /// For internal use by NDDS DCPS layer:
  /// Dynamically load the library for the supplied transport type.
  void load_transport_lib(const NDDS_STRING& transport_type,
                          bool wait = true);

  bool released() const;

  bool config_has_transport_template(const ACE_TString& config_name) const;

  int create_transport_template_instance(DDS::DomainId_t domain, const ACE_TString& config_name);

  NDDS_STRING get_transport_template_instance_name(DDS::DomainId_t id);

  NDDS_STRING get_config_instance_name(DDS::DomainId_t id);

  // the new config and instance names are returned by reference.
  bool create_new_transport_instance_for_participant(DDS::DomainId_t id, NDDS_STRING& transport_config_name, NDDS_STRING& transport_instance_name);

  void update_config_template_instance_info(const NDDS_STRING& config_name, const NDDS_STRING& inst_name);

private:
  friend class ACE_Singleton<TransportRegistry, ACE_Recursive_Thread_Mutex>;

  TransportRegistry();
  ~TransportRegistry();

  typedef NDDS_MAP(NDDS_STRING, TransportType_rch) TypeMap;
  typedef NDDS_MAP(NDDS_STRING, TransportConfig_rch) ConfigMap;
  typedef NDDS_MAP(NDDS_STRING, TransportInst_rch) InstMap;
  typedef NDDS_MAP(NDDS_STRING, NDDS_STRING) LibDirectiveMap;
  typedef NDDS_MAP(DDS::DomainId_t, TransportConfig_rch) DomainConfigMap;
  typedef NDDS_MAP(NDDS_STRING, NDDS_STRING) ConfigTemplateToInstanceMap;

  typedef ACE_SYNCH_MUTEX LockType;
  typedef ACE_Guard<LockType> GuardType;

  TypeMap type_map_;
  ConfigMap config_map_;
  InstMap inst_map_;
  LibDirectiveMap lib_directive_map_;
  DomainConfigMap domain_default_config_map_;
  ConfigTemplateToInstanceMap config_template_to_instance_map_;

  TransportConfig_rch global_config_;
  bool released_;

  mutable LockType lock_;
  // This condition is signaled when a load is completed.
  mutable ConditionVariable<LockType> load_complete_;

  // transport template support
  static const NDDS_STRING CUSTOM_ADD_DOMAIN_TO_IP;
  static const NDDS_STRING CUSTOM_ADD_DOMAIN_TO_PORT;

  struct TransportTemplate
  {
    NDDS_STRING transport_template_name;
    NDDS_STRING config_name;
    bool instantiate_per_participant;
    ValueMap customizations;
    ValueMap transport_info;
  };

  TransportType_rch load_transport_lib_i(const NDDS_STRING& transport_type,
                                         bool wait);

  NDDS_VECTOR(TransportTemplate) transport_templates_;

  bool get_transport_template_info(const ACE_TString& config_name, TransportTemplate& inst);

  bool process_customizations(const DDS::DomainId_t id, const TransportTemplate& tr_inst, ValueMap& customs);

  bool has_transport_templates() const;

  struct TransportEntry
  {
    ACE_TString transport_name;
    ACE_TString config_name;
    ValueMap transport_info;
  };

  NDDS_VECTOR(TransportEntry) transports_;

  bool get_transport_info(const ACE_TString& config_name, TransportEntry& inst);

  bool has_transports() const;
};

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "TransportRegistry.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_DCPS_TRANSPORTREGISTRY_H */
