/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_TRANSIENT_KLUDGE_H
#define NDDS_DCPS_TRANSIENT_KLUDGE_H

#include "dcps_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

/**
* @class TransientKludge
*
* @brief Simply turn on and off the transient kludge enable flag.
*
* This class provides the methods to set/get transient kludge
* enable flag.
* Only the repository should set/enable the kludge!!!
*/
class NDDS_Dcps_Export Transient_Kludge {
public:
  Transient_Kludge();
  ~Transient_Kludge();

  /// Return a singleton instance of this class.
  static Transient_Kludge* instance();

  /// Turn on enabled_ flag.
  void enable();

  /// Turn off enabled_ flag.
  void disable();

  /// Accessor of enable flag.
  bool is_enabled() const;

private:
  /// The flag.
  bool  enabled_;
};

#define TheTransientKludge NDDS::DCPS::Transient_Kludge::instance()

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined(__ACE_INLINE__)
#include "Transient_Kludge.inl"
#endif /* __ACE_INLINE__ */

#endif /* NDDS_DCPS_TRANSIENT_KLUDGE_H */
