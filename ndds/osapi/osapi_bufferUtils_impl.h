/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_MONITORFACTORY_H
#define NDDS_DCPS_MONITORFACTORY_H

#include "ace/Service_Object.h"
#include "ace/Service_Config.h"
#include "tao/corba.h"
#include "dcps_export.h"
#include "PublicationInstance.h"


#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class Service_Participant;
class DomainParticipantImpl;
class TopicImpl;
class PublisherImpl;
class SubscriberImpl;
class DataWriterImpl;
class DataReaderImpl;
class TransportImpl;


class Monitor {
public:
  Monitor() { }
  virtual ~Monitor() { }
  virtual void report() = 0;
};

/**
* @class MonitorFactory
*
* @brief Null implementation of the MonitorFactory
*
* Full version of this library is implemented by the monitor lib.
*/
class NDDS_Dcps_Export MonitorFactory
  : public ACE_Service_Object {
public:
  MonitorFactory();

  virtual ~MonitorFactory();

  /// Factory function to create a service participant monitor object
  virtual Monitor* create_sp_monitor(Service_Participant* sp);

  /// Factory function to create a domain participant monitor object
  virtual Monitor* create_dp_monitor(DomainParticipantImpl* dp);

  /// Factory function to create a topic monitor object
  virtual Monitor* create_topic_monitor(TopicImpl* topic);

  /// Factory function to create a publisher monitor object
  virtual Monitor* create_publisher_monitor(PublisherImpl* publisher);

  /// Factory function to create a subscriber monitor object
  virtual Monitor* create_subscriber_monitor(SubscriberImpl* subscriber);

  /// Factory function to create a data writer monitor object
  virtual Monitor* create_data_writer_monitor(DataWriterImpl* dw);

  /// Factory function to create a data writer periodic monitor object
  virtual Monitor* create_data_writer_periodic_monitor(DataWriterImpl* dw);

  /// Factory function to create a data reader monitor object
  virtual Monitor* create_data_reader_monitor(DataReaderImpl* dr);

  /// Factory function to create a data reader periodic monitor object
  virtual Monitor* create_data_reader_periodic_monitor(DataReaderImpl* dr);

  /// Factory function to create a transport monitor object
  virtual Monitor* create_transport_monitor(TransportImpl* transport);

  /// Initialize the monitor (required to report data)
  virtual void initialize();

  virtual void deinitialize();

  static int service_initialize();
};

static const int NDDS_Requires_MonitorFactory_Initializer =
  MonitorFactory::service_initialize();

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

ACE_STATIC_SVC_DECLARE (MonitorFactory)
ACE_FACTORY_DECLARE (NDDS_Dcps, MonitorFactory)

#endif /* NDDS_DCPS_MONITOR_FACTORY_BASE_H */
