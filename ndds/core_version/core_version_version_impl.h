// -*- C++ -*-

//=============================================================================
/**
 * @file    Versioned_Namespace.h
 *
 * Versioned namespace support.
 *
 * Useful for preventing conflicts when using a third party library.
 *
 * @author Ossama Othman <ossama@dre.vanderbilt.edu>
 */
//=============================================================================

#ifndef NDDS_VERSIONED_NAMESPACE_H
#define NDDS_VERSIONED_NAMESPACE_H

#include "ace/config.h"

#if !defined (NDDS_HAS_VERSIONED_NAMESPACE) \
  && defined (ACE_HAS_VERSIONED_NAMESPACE) \
  && ACE_HAS_VERSIONED_NAMESPACE == 1
# define NDDS_HAS_VERSIONED_NAMESPACE 1
#endif  /* !NDDS_HAS_VERSIONED_NAMESPACE
           && ACE_HAS_VERSIONED_NAMESPACE == 1*/

#if defined (NDDS_HAS_VERSIONED_NAMESPACE) && NDDS_HAS_VERSIONED_NAMESPACE == 1

# ifndef NDDS_VERSIONED_NAMESPACE_NAME
#  include "Version.h"

// Preprocessor symbols will not be expanded if they are
// concatenated.  Force the preprocessor to expand them during the
// argument prescan by calling a macro that itself calls another that
// performs the actual concatenation.
#  define NDDS_MAKE_VERSIONED_NAMESPACE_NAME_IMPL(MAJOR,MINOR,MICRO) NDDS_ ## MAJOR ## _ ## MINOR ## _ ## MICRO
#  define NDDS_MAKE_VERSIONED_NAMESPACE_NAME(MAJOR,MINOR,MICRO) NDDS_MAKE_VERSIONED_NAMESPACE_NAME_IMPL(MAJOR,MINOR,MICRO)
#  define NDDS_VERSIONED_NAMESPACE_NAME \
  NDDS_MAKE_VERSIONED_NAMESPACE_NAME(NDDS_MAJOR_VERSION,NDDS_MINOR_VERSION,NDDS_MICRO_VERSION)
# endif  /* !NDDS_VERSIONED_NAMESPACE_NAME */

# define NDDS_BEGIN_VERSIONED_NAMESPACE_DECL namespace NDDS_VERSIONED_NAMESPACE_NAME {
# define NDDS_END_VERSIONED_NAMESPACE_DECL } \
  using namespace NDDS_VERSIONED_NAMESPACE_NAME;
#else
# define NDDS_VERSIONED_NAMESPACE_NAME
# define NDDS_BEGIN_VERSIONED_NAMESPACE_DECL
# define NDDS_END_VERSIONED_NAMESPACE_DECL

#endif  /* NDDS_HAS_VERSIONED_NAMESPACE */

#endif  /* !NDDS_VERSIONED_NAMESPACE_H */
