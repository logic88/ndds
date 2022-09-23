
// (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef RTIBOOST_TT_ADD_POINTER_HPP_INCLUDED
#define RTIBOOST_TT_ADD_POINTER_HPP_INCLUDED

#include <rtiboost/type_traits/remove_reference.hpp>

// should be the last #include
#include <rtiboost/type_traits/detail/type_trait_def.hpp>

namespace rtiboost {

namespace detail {

#if defined(__BORLANDC__) && (__BORLANDC__ < 0x5A0)
//
// For some reason this implementation stops Borlands compiler
// from dropping cv-qualifiers, it still fails with references
// to arrays for some reason though (shrug...) (JM 20021104)
//
template <typename T>
struct add_pointer_impl
{
    typedef T* type;
};
template <typename T>
struct add_pointer_impl<T&>
{
    typedef T* type;
};
template <typename T>
struct add_pointer_impl<T&const>
{
    typedef T* type;
};
template <typename T>
struct add_pointer_impl<T&volatile>
{
    typedef T* type;
};
template <typename T>
struct add_pointer_impl<T&const volatile>
{
    typedef T* type;
};

#else

template <typename T>
struct add_pointer_impl
{
    typedef typename remove_reference<T>::type no_ref_type;
    typedef no_ref_type* type;
};

#endif

} // namespace detail

RTIBOOST_TT_AUX_TYPE_TRAIT_DEF1(add_pointer,T,typename rtiboost::detail::add_pointer_impl<T>::type)

} // namespace rtiboost

#include <rtiboost/type_traits/detail/type_trait_undef.hpp>

#endif // RTIBOOST_TT_ADD_POINTER_HPP_INCLUDED
