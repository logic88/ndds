
//  (C) Copyright Runar Undheim, Robert Ramey & John Maddock 2008.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef RTIBOOST_TT_HAS_NEW_OPERATOR_HPP_INCLUDED
#define RTIBOOST_TT_HAS_NEW_OPERATOR_HPP_INCLUDED

#include <new> // std::nothrow_t
#include <cstddef> // std::size_t
#include <rtiboost/type_traits/config.hpp>
#include <rtiboost/type_traits/detail/yes_no_type.hpp>
#include <rtiboost/type_traits/detail/ice_or.hpp>

// should be the last #include
#include <rtiboost/type_traits/detail/bool_trait_def.hpp>

namespace rtiboost {
namespace detail {
    template <class U, U x> 
    struct test;

    template <typename T>
    struct has_new_operator_impl {
        template<class U>
        static type_traits::yes_type check_sig1(
            U*, 
            test<
            void *(*)(std::size_t),
                &U::operator new
            >* = NULL
        );
        template<class U>
        static type_traits::no_type check_sig1(...);

        template<class U>
        static type_traits::yes_type check_sig2(
            U*, 
            test<
            void *(*)(std::size_t, const std::nothrow_t&),
                &U::operator new
            >* = NULL
        );
        template<class U>
        static type_traits::no_type check_sig2(...);

        template<class U>
        static type_traits::yes_type check_sig3(
            U*, 
            test<
            void *(*)(std::size_t, void*),
                &U::operator new
            >* = NULL
        );
        template<class U>
        static type_traits::no_type check_sig3(...);


        template<class U>
        static type_traits::yes_type check_sig4(
            U*, 
            test<
            void *(*)(std::size_t),
                &U::operator new[]
            >* = NULL
        );
        template<class U>
        static type_traits::no_type check_sig4(...);

        template<class U>
        static type_traits::yes_type check_sig5(
            U*, 
            test<
            void *(*)(std::size_t, const std::nothrow_t&),
                &U::operator new[]
            >* = NULL
        );
        template<class U>
        static type_traits::no_type check_sig5(...);

        template<class U>
        static type_traits::yes_type check_sig6(
            U*, 
            test<
            void *(*)(std::size_t, void*),
                &U::operator new[]
            >* = NULL
        );
        template<class U>
        static type_traits::no_type check_sig6(...);

        // GCC2 won't even parse this template if we embed the computation
        // of s1 in the computation of value.
        #ifdef __GNUC__
            RTIBOOST_STATIC_CONSTANT(unsigned, s1 = sizeof(has_new_operator_impl<T>::template check_sig1<T>(0)));
            RTIBOOST_STATIC_CONSTANT(unsigned, s2 = sizeof(has_new_operator_impl<T>::template check_sig2<T>(0)));
            RTIBOOST_STATIC_CONSTANT(unsigned, s3 = sizeof(has_new_operator_impl<T>::template check_sig3<T>(0)));
            RTIBOOST_STATIC_CONSTANT(unsigned, s4 = sizeof(has_new_operator_impl<T>::template check_sig4<T>(0)));
            RTIBOOST_STATIC_CONSTANT(unsigned, s5 = sizeof(has_new_operator_impl<T>::template check_sig5<T>(0)));
            RTIBOOST_STATIC_CONSTANT(unsigned, s6 = sizeof(has_new_operator_impl<T>::template check_sig6<T>(0)));
        #else
            #if RTIBOOST_WORKAROUND(RTIBOOST_MSVC_FULL_VER, >= 140050000)
                #pragma warning(push)
                #pragma warning(disable:6334)
            #endif

            RTIBOOST_STATIC_CONSTANT(unsigned, s1 = sizeof(check_sig1<T>(0)));
            RTIBOOST_STATIC_CONSTANT(unsigned, s2 = sizeof(check_sig2<T>(0)));
            RTIBOOST_STATIC_CONSTANT(unsigned, s3 = sizeof(check_sig3<T>(0)));
            RTIBOOST_STATIC_CONSTANT(unsigned, s4 = sizeof(check_sig4<T>(0)));
            RTIBOOST_STATIC_CONSTANT(unsigned, s5 = sizeof(check_sig5<T>(0)));
            RTIBOOST_STATIC_CONSTANT(unsigned, s6 = sizeof(check_sig6<T>(0)));

            #if RTIBOOST_WORKAROUND(RTIBOOST_MSVC_FULL_VER, >= 140050000)
                #pragma warning(pop)
            #endif
        #endif
        RTIBOOST_STATIC_CONSTANT(bool, value = 
           (::rtiboost::type_traits::ice_or<
            (s1 == sizeof(type_traits::yes_type)),
            (s2 == sizeof(type_traits::yes_type)),
            (s3 == sizeof(type_traits::yes_type)),
            (s4 == sizeof(type_traits::yes_type)),
            (s5 == sizeof(type_traits::yes_type)),
            (s6 == sizeof(type_traits::yes_type))
           >::value)
        );
    };
} // namespace detail

RTIBOOST_TT_AUX_BOOL_TRAIT_DEF1(has_new_operator,T,::rtiboost::detail::has_new_operator_impl<T>::value)

} // namespace rtiboost

#include <rtiboost/type_traits/detail/bool_trait_undef.hpp>

#endif // RTIBOOST_TT_HAS_NEW_OPERATOR_HPP_INCLUDED
