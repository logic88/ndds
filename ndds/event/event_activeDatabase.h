/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef DCPS_IR_FEDERATOR_ID_H
#define DCPS_IR_FEDERATOR_ID_H

#include "inforepo_export.h"
#include "tao/Basic_Types.h"
#include "dds/Versioned_Namespace.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

class NDDS_InfoRepoLib_Export TAO_DDS_DCPSFederationId
{
public:
  typedef ::CORBA::Long RepoKey;
  TAO_DDS_DCPSFederationId(RepoKey initId);
  void id(RepoKey fedId);
  RepoKey id() const;
  bool overridden() const;
private:
  RepoKey id_;
  bool    overridden_;
};

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* DCPS_IR_FEDERATOR_ID_H */
