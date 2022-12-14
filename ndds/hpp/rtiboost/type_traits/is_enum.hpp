
//  (C) Copyright Dave Abrahams, Steve Cleary, Beman Dawes, Howard
//  Hinnant & John Maddock 2000.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.


#ifndef RTIBOOST_TT_IS_ENUM_HPP_INCLUDED
#define RTIBOOST_TT_IS_ENUM_HPP_INCLUDED

#include <rtiboost/type_traits/intrinsics.hpp>
#ifndef RTIBOOST_IS_ENUM
#include <rtiboost/type_traits/add_reference.hpp>
#include <rtiboost/type_traits/is_arithmetic.hpp>
#include <rtiboost/type_traits/is_reference.hpp>
#include <rtiboost/type_traits/is_convertible.hpp>
#include <rtiboost/type_traits/is_array.hpp>
#ifdef __GNUC__
#include <rtiboost/type_traits/is_function.hpp>
#endif
#include <rtiboost/type_traits/config.hpp>
#if defined(RTIBOOST_TT_HAS_CONFORMING_IS_CLASS_IMPLEMENTATION) 
#  include <rtiboost/type_traits/is_class.hpp>
#  include <rtiboost/type_traits/is_union.hpp>
#endif
#endif

// should be the last #include
#include <rtiboost/type_traits/detail/bool_trait_def.hpp>

namespace rtiboost {

#ifndef RTIBOOST_IS_ENUM
#if !(defined(__BORLANDC__) && (__BORLANDC__ <= 0x551))

namespace detail {

#if defined(RTIBOOST_TT_HAS_CONFORMING_IS_CLASS_IMPLEMENTATION) 

template <typename T>
struct is_class_or_union
{
   RTIBOOST_STATIC_CONSTANT(bool, value =
      (::rtiboost::type_traits::ice_or<
           ::rtiboost::is_class<T>::value
         , ::rtiboost::is_union<T>::value
      >::value));
};

#else

template <typename T>
struct is_class_or_union
{
# if RTIBOOST_WORKAROUND(RTIBOOST_MSVC, < 1300) || RTIBOOST_WORKAROUND(__BORLANDC__, RTIBOOST_TESTED_AT(0x581))// we simply can't detect it this way.
    RTIBOOST_STATIC_CONSTANT(bool, value = false);
# else
    template <class U> static ::rtiboost::type_traits::yes_type is_class_or_union_tester(void(U::*)(void));

#  if RTIBOOST_WORKAROUND(RTIBOOST_MSVC, == 1300)                 \
    || RTIBOOST_WORKAROUND(__MWERKS__, <= 0x3000) // no SFINAE
    static ::rtiboost::type_traits::no_type is_class_or_union_tester(...);
    RTIBOOST_STATIC_CONSTANT(
        bool, value = sizeof(is_class_or_union_tester(0)) == sizeof(::rtiboost::type_traits::yes_type));
#  else
    template <class U>
    static ::rtiboost::type_traits::no_type is_class_or_union_tester(...);
    RTIBOOST_STATIC_CONSTANT(
        bool, value = sizeof(is_class_or_union_tester<T>(0)) == sizeof(::rtiboost::type_traits::yes_type));
#  endif
# endif
};
#endif

struct int_convertible
{
    int_convertible(int);
};

// Don't evaluate convertibility to int_convertible unless the type
// is non-arithmetic. This suppresses warnings with GCC.
template <bool is_typename_arithmetic_or_reference = true>
struct is_enum_helper
{
    template <typename T> struct type
    {
        RTIBOOST_STATIC_CONSTANT(bool, value = false);
    };
};

template <>
struct is_enum_helper<false>
{
    template <typename T> struct type
       : public ::rtiboost::is_convertible<typename rtiboost::add_reference<T>::type,::rtiboost::detail::int_convertible>
    {
    };
};

template <typename T> struct is_enum_impl
{
   //typedef ::rtiboost::add_reference<T> ar_t;
   //typedef typename ar_t::type r_type;

#if defined(__GNUC__)

#ifdef RTIBOOST_TT_HAS_CONFORMING_IS_CLASS_IMPLEMENTATION
    
   // We MUST check for is_class_or_union on conforming compilers in
   // order to correctly deduce that noncopyable types are not enums
   // (dwa 2002/04/15)...
   RTIBOOST_STATIC_CONSTANT(bool, selector =
      (::rtiboost::type_traits::ice_or<
           ::rtiboost::is_arithmetic<T>::value
         , ::rtiboost::is_reference<T>::value
         , ::rtiboost::is_function<T>::value
         , is_class_or_union<T>::value
         , is_array<T>::value
      >::value));
#else
   // ...however, not checking is_class_or_union on non-conforming
   // compilers prevents a dependency recursion.
   RTIBOOST_STATIC_CONSTANT(bool, selector =
      (::rtiboost::type_traits::ice_or<
           ::rtiboost::is_arithmetic<T>::value
         , ::rtiboost::is_reference<T>::value
         , ::rtiboost::is_function<T>::value
         , is_array<T>::value
      >::value));
#endif // RTIBOOST_TT_HAS_CONFORMING_IS_CLASS_IMPLEMENTATION

#else // !defined(__GNUC__):
    
   RTIBOOST_STATIC_CONSTANT(bool, selector =
      (::rtiboost::type_traits::ice_or<
           ::rtiboost::is_arithmetic<T>::value
         , ::rtiboost::is_reference<T>::value
         , is_class_or_union<T>::value
         , is_array<T>::value
      >::value));
    
#endif

#if RTIBOOST_WORKAROUND(__BORLANDC__, < 0x600)
    typedef ::rtiboost::detail::is_enum_helper<
          ::rtiboost::detail::is_enum_impl<T>::selector
        > se_t;
#else
    typedef ::rtiboost::detail::is_enum_helper<selector> se_t;
#endif

    typedef typename se_t::template type<T> helper;
    RTIBOOST_STATIC_CONSTANT(bool, value = helper::value);
};

// these help on compilers with no partial specialization support:
RTIBOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_enum,void,false)
#ifndef RTIBOOST_NO_CV_VOID_SPECIALIZATIONS
RTIBOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_enum,void const,false)
RTIBOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_enum,void volatile,false)
RTIBOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_enum,void const volatile,false)
#endif

} // namespace detail

RTIBOOST_TT_AUX_BOOL_TRAIT_DEF1(is_enum,T,::rtiboost::detail::is_enum_impl<T>::value)

#else // __BORLANDC__
//
// buggy is_convertible prevents working
// implementation of is_enum:
RTIBOOST_TT_AUX_BOOL_TRAIT_DEF1(is_enum,T,false)

#endif

#else // RTIBOOST_IS_ENUM

RTIBOOST_TT_AUX_BOOL_TRAIT_DEF1(is_enum,T,RTIBOOST_IS_ENUM(T))

#endif

} // namespace rtiboost

#include <rtiboost/type_traits/detail/bool_trait_undef.hpp>

#endif // RTIBOOST_TT_IS_ENUM_HPP_INCLUDED
