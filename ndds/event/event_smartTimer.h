#ifndef NDDS_FACE_CONFIG_TOPICSETTINGS_H
#define NDDS_FACE_CONFIG_TOPICSETTINGS_H

#include "FACE/TS_common.hpp"
#include "dds/DCPS/PoolAllocator.h"
#include "FACE/NDDS_FACE_Export.h"
#include "dds/Versioned_Namespace.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS { namespace FaceTSS { namespace config {

class NDDS_FACE_Export TopicSettings {
public:
  static const int TYPE_NAME_LEN = 128;

  int set(const char* name, const char* value);

  char type_name_[TYPE_NAME_LEN];
  FACE::MESSAGE_TYPE_GUID platform_view_guid_;
  FACE::MESSAGE_SIZE_TYPE max_message_size_;
};

typedef NDDS_MAP(NDDS_STRING, TopicSettings) TopicMap;

} } }

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif
