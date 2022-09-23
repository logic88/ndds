
// -*- C++ -*-
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl -s NDDS_monitor
// ------------------------------
#ifndef NDDS_MONITOR_EXPORT_H
#define NDDS_MONITOR_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (NDDS_MONITOR_HAS_DLL)
#  define NDDS_MONITOR_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && NDDS_MONITOR_HAS_DLL */

#if !defined (NDDS_MONITOR_HAS_DLL)
#  define NDDS_MONITOR_HAS_DLL 1
#endif /* ! NDDS_MONITOR_HAS_DLL */

#if defined (NDDS_MONITOR_HAS_DLL) && (NDDS_MONITOR_HAS_DLL == 1)
#  if defined (NDDS_MONITOR_BUILD_DLL)
#    define NDDS_monitor_Export ACE_Proper_Export_Flag
#    define NDDS_MONITOR_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define NDDS_MONITOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* NDDS_MONITOR_BUILD_DLL */
#    define NDDS_monitor_Export ACE_Proper_Import_Flag
#    define NDDS_MONITOR_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define NDDS_MONITOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* NDDS_MONITOR_BUILD_DLL */
#else /* NDDS_MONITOR_HAS_DLL == 1 */
#  define NDDS_monitor_Export
#  define NDDS_MONITOR_SINGLETON_DECLARATION(T)
#  define NDDS_MONITOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* NDDS_MONITOR_HAS_DLL == 1 */

// Set NDDS_MONITOR_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (NDDS_MONITOR_NTRACE)
#  if (ACE_NTRACE == 1)
#    define NDDS_MONITOR_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define NDDS_MONITOR_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !NDDS_MONITOR_NTRACE */

#if (NDDS_MONITOR_NTRACE == 1)
#  define NDDS_MONITOR_TRACE(X)
#else /* (NDDS_MONITOR_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define NDDS_MONITOR_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (NDDS_MONITOR_NTRACE == 1) */

#endif /* NDDS_MONITOR_EXPORT_H */

// End of auto generated file.
