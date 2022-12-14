/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#include "DcpsInfo_pch.h"

#include "FederationId.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_DDS_DCPSFederationId::TAO_DDS_DCPSFederationId(RepoKey initId)
: id_(initId)
, overridden_(false)
{
}

void
TAO_DDS_DCPSFederationId::id(RepoKey fedId)
{
  this->id_ = fedId;
  this->overridden_ = true;
}

TAO_DDS_DCPSFederationId::RepoKey
TAO_DDS_DCPSFederationId::id() const
{
  return this->id_;
}

bool
TAO_DDS_DCPSFederationId::overridden() const
{
  return this->overridden_;
}

NDDS_END_VERSIONED_NAMESPACE_DECL
