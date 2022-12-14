
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef RTIBOOST_TT_IS_INTEGRAL_HPP_INCLUDED
#define RTIBOOST_TT_IS_INTEGRAL_HPP_INCLUDED

#include <rtiboost/config.hpp>

// should be the last #include
#include <rtiboost/type_traits/detail/bool_trait_def.hpp>

namespace rtiboost {

//* is a type T an [cv-qualified-] integral type described in the standard (3.9.1p3)
// as an extension we include long long, as this is likely to be added to the
// standard at a later date
#if defined( __CODEGEARC__ )
RTIBOOST_TT_AUX_BOOL_TRAIT_DEF1(is_integral,T,__is_integral(T))
#else
RTIBOOST_TT_AUX_BOOL_TRAIT_DEF1(is_integral,T,false)

RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned char,true)
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned short,true)
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned int,true)
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned long,true)

RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,signed char,true)
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,signed short,true)
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,signed int,true)
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,signed long,true)

RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,bool,true)
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,char,true)

#ifndef RTIBOOST_NO_INTRINSIC_WCHAR_T
// If the following line fails to compile and you're using the Intel
// compiler, see http://lists.boost.org/MailArchives/boost-users/msg06567.php,
// and define RTIBOOST_NO_INTRINSIC_WCHAR_T on the command line.
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,wchar_t,true)
#endif

// Same set of integral types as in boost/type_traits/integral_promotion.hpp.
// Please, keep in sync. -- Alexander Nasonov
#if (defined(RTIBOOST_MSVC) && (RTIBOOST_MSVC < 1300)) \
    || (defined(RTIBOOST_INTEL_CXX_VERSION) && defined(_MSC_VER) && (RTIBOOST_INTEL_CXX_VERSION <= 600)) \
    || (defined(__BORLANDC__) && (__BORLANDC__ == 0x600) && (_MSC_VER < 1300))
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned __int8,true)
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,__int8,true)
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned __int16,true)
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,__int16,true)
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned __int32,true)
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,__int32,true)
#ifdef __BORLANDC__
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned __int64,true)
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,__int64,true)
#endif
#endif

# if defined(RTIBOOST_HAS_LONG_LONG)
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral, ::rtiboost::ulong_long_type,true)
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral, ::rtiboost::long_long_type,true)
#elif defined(RTIBOOST_HAS_MS_INT64)
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned __int64,true)
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,__int64,true)
#endif
        
#ifdef RTIBOOST_HAS_INT128
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,rtiboost::int128_type,true)
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,rtiboost::uint128_type,true)
#endif
#ifndef RTIBOOST_NO_CXX11_CHAR16_T
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,char16_t,true)
#endif
#ifndef RTIBOOST_NO_CXX11_CHAR32_T
RTIBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,char32_t,true)
#endif

#endif  // non-CodeGear implementation

} // namespace rtiboost

#include <rtiboost/type_traits/detail/bool_trait_undef.hpp>

#endif // RTIBOOST_TT_IS_INTEGRAL_HPP_INCLUDED
