//  (C) Copyright John Maddock 2001 - 2003. 
//  (C) Copyright Darin Adler 2001. 
//  (C) Copyright Douglas Gregor 2002. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  generic BSD config options:

#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__DragonFly__)
#error "This platform is not BSD"
#endif

#ifdef __FreeBSD__
#define RTIBOOST_PLATFORM "FreeBSD " RTIBOOST_STRINGIZE(__FreeBSD__)
#elif defined(__NetBSD__)
#define RTIBOOST_PLATFORM "NetBSD " RTIBOOST_STRINGIZE(__NetBSD__)
#elif defined(__OpenBSD__)
#define RTIBOOST_PLATFORM "OpenBSD " RTIBOOST_STRINGIZE(__OpenBSD__)
#elif defined(__DragonFly__)
#define RTIBOOST_PLATFORM "DragonFly " RTIBOOST_STRINGIZE(__DragonFly__)
#endif

//
// is this the correct version check?
// FreeBSD has <nl_types.h> but does not
// advertise the fact in <unistd.h>:
//
#if (defined(__FreeBSD__) && (__FreeBSD__ >= 3)) || defined(__DragonFly__)
#  define RTIBOOST_HAS_NL_TYPES_H
#endif

//
// FreeBSD 3.x has pthreads support, but defines _POSIX_THREADS in <pthread.h>
// and not in <unistd.h>
//
#if (defined(__FreeBSD__) && (__FreeBSD__ <= 3))\
   || defined(__OpenBSD__) || defined(__DragonFly__) 
#  define RTIBOOST_HAS_PTHREADS
#endif

//
// No wide character support in the BSD header files:
//
#if defined(__NetBSD__)
#define __NetBSD_GCC__ (__GNUC__         * 1000000 \
                       + __GNUC_MINOR__ *    1000 \
                       + __GNUC_PATCHLEVEL__)
// XXX - the following is required until c++config.h
//       defines _GLIBCXX_HAVE_SWPRINTF and friends
//       or the preprocessor conditionals are removed
//       from the cwchar header.
#define _GLIBCXX_HAVE_SWPRINTF 1
#endif

#if !((defined(__FreeBSD__) && (__FreeBSD__ >= 5)) \
      || (defined(__NetBSD_GCC__) && (__NetBSD_GCC__ >= 2095003)) || defined(__DragonFly__))
#  define RTIBOOST_NO_CWCHAR
#endif
//
// The BSD <ctype.h> has macros only, no functions:
//
#if !defined(__OpenBSD__) || defined(__DragonFly__)
#  define RTIBOOST_NO_CTYPE_FUNCTIONS
#endif

//
// thread API's not auto detected:
//
#define RTIBOOST_HAS_SCHED_YIELD
#define RTIBOOST_HAS_NANOSLEEP
#define RTIBOOST_HAS_GETTIMEOFDAY
#define RTIBOOST_HAS_PTHREAD_MUTEXATTR_SETTYPE
#define RTIBOOST_HAS_SIGACTION

// boilerplate code:
#define RTIBOOST_HAS_UNISTD_H
#include <rtiboost/config/posix_features.hpp>






