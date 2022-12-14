//  Boost compiler configuration selection header file

//  (C) Copyright John Maddock 2001 - 2003. 
//  (C) Copyright Martin Wille 2003.
//  (C) Copyright Guillaume Melquiond 2003.
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/ for most recent version.

// locate which compiler we are using and define
// RTIBOOST_COMPILER_CONFIG as needed: 

#if defined __CUDACC__
//  NVIDIA CUDA C++ compiler for GPU
#   include "rtiboost/config/compiler/nvcc.hpp"

#endif

#if defined(__GCCXML__)
// GCC-XML emulates other compilers, it has to appear first here!
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/gcc_xml.hpp"

#elif defined(_CRAYC)
// EDG based Cray compiler:
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/cray.hpp"

#elif defined __COMO__
//  Comeau C++
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/comeau.hpp"

#elif defined(__PATHSCALE__) && (__PATHCC__ >= 4)
// PathScale EKOPath compiler (has to come before clang and gcc)
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/pathscale.hpp"

#elif defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)
//  Intel
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/intel.hpp"

#elif defined __clang__
//  Clang C++ emulates GCC, so it has to appear early.
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/clang.hpp"

#elif defined __DMC__
//  Digital Mars C++
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/digitalmars.hpp"

# elif defined __GNUC__
//  GNU C++:
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/gcc.hpp"

#elif defined __KCC
//  Kai C++
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/kai.hpp"

#elif defined __sgi
//  SGI MIPSpro C++
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/sgi_mipspro.hpp"

#elif defined __DECCXX
//  Compaq Tru64 Unix cxx
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/compaq_cxx.hpp"

#elif defined __ghs
//  Greenhills C++
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/greenhills.hpp"

#elif defined __CODEGEARC__
//  CodeGear - must be checked for before Borland
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/codegear.hpp"

#elif defined __BORLANDC__
//  Borland
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/borland.hpp"

#elif defined  __MWERKS__
//  Metrowerks CodeWarrior
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/metrowerks.hpp"

#elif defined  __SUNPRO_CC
//  Sun Workshop Compiler C++
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/sunpro_cc.hpp"

#elif defined __HP_aCC
//  HP aCC
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/hp_acc.hpp"

#elif defined(__MRC__) || defined(__SC__)
//  MPW MrCpp or SCpp
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/mpw.hpp"

#elif defined(__IBMCPP__)
//  IBM Visual Age
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/vacpp.hpp"

#elif defined(__PGI)
//  Portland Group Inc.
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/pgi.hpp"

#elif defined _MSC_VER
//  Microsoft Visual C++
//
//  Must remain the last #elif since some other vendors (Metrowerks, for
//  example) also #define _MSC_VER
#   define RTIBOOST_COMPILER_CONFIG "rtiboost/config/compiler/visualc.hpp"

#elif defined (RTIBOOST_ASSERT_CONFIG)
// this must come last - generate an error if we don't
// recognise the compiler:
#  error "Unknown compiler - please configure (http://www.boost.org/libs/config/config.htm#configuring) and report the results to the main boost mailing list (http://www.boost.org/more/mailing_lists.htm#main)"

#endif
