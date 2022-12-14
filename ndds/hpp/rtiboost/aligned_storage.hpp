//-----------------------------------------------------------------------------
// boost aligned_storage.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2002-2003
// Eric Friedman, Itay Maman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef RTIBOOST_ALIGNED_STORAGE_HPP
#define RTIBOOST_ALIGNED_STORAGE_HPP

#include <cstddef> // for std::size_t

#include "rtiboost/config.hpp"
#include "rtiboost/detail/workaround.hpp"
#include "rtiboost/type_traits/alignment_of.hpp"
#include "rtiboost/type_traits/type_with_alignment.hpp"
#include "rtiboost/type_traits/is_pod.hpp"

#include "rtiboost/mpl/eval_if.hpp"
#include "rtiboost/mpl/identity.hpp"

#include "rtiboost/type_traits/detail/bool_trait_def.hpp"

namespace rtiboost {

namespace detail { namespace aligned_storage {

RTIBOOST_STATIC_CONSTANT(
      std::size_t
    , alignment_of_max_align = ::rtiboost::alignment_of<max_align>::value
    );

//
// To be TR1 conforming this must be a POD type:
//
template <
      std::size_t size_
    , std::size_t alignment_
>
struct aligned_storage_imp
{
    union data_t
    {
        char buf[size_];

        typename mpl::eval_if_c<
              alignment_ == std::size_t(-1)
            , mpl::identity<detail::max_align>
            , type_with_alignment<alignment_>
            >::type align_;
    } data_;
    void* address() const { return const_cast<aligned_storage_imp*>(this); }
};

template< std::size_t alignment_ >
struct aligned_storage_imp<0u,alignment_>
{
    /* intentionally empty */
    void* address() const { return 0; }
};

}} // namespace detail::aligned_storage

template <
      std::size_t size_
    , std::size_t alignment_ = std::size_t(-1)
>
class aligned_storage : 
#ifndef __BORLANDC__
   private 
#else
   public
#endif
   detail::aligned_storage::aligned_storage_imp<size_, alignment_> 
{
 
public: // constants

    typedef detail::aligned_storage::aligned_storage_imp<size_, alignment_> type;

    RTIBOOST_STATIC_CONSTANT(
          std::size_t
        , size = size_
        );
    RTIBOOST_STATIC_CONSTANT(
          std::size_t
        , alignment = (
              alignment_ == std::size_t(-1)
            ? ::rtiboost::detail::aligned_storage::alignment_of_max_align
            : alignment_
            )
        );

#if defined(__GNUC__) &&\
    (__GNUC__ >  3) ||\
    (__GNUC__ == 3 && (__GNUC_MINOR__ >  2 ||\
                      (__GNUC_MINOR__ == 2 && __GNUC_PATCHLEVEL__ >=3)))

private: // noncopyable

    aligned_storage(const aligned_storage&);
    aligned_storage& operator=(const aligned_storage&);

#else // gcc less than 3.2.3

public: // _should_ be noncopyable, but GCC compiler emits error

    aligned_storage(const aligned_storage&);
    aligned_storage& operator=(const aligned_storage&);

#endif // gcc < 3.2.3 workaround

public: // structors

    aligned_storage()
    {
    }

    ~aligned_storage()
    {
    }

public: // accessors

    void* address()
    {
        return static_cast<type*>(this)->address();
    }

#if !RTIBOOST_WORKAROUND(RTIBOOST_MSVC, < 1300)

    const void* address() const
    {
        return static_cast<const type*>(this)->address();
    }

#else // MSVC6

    const void* address() const;

#endif // MSVC6 workaround

};

#if RTIBOOST_WORKAROUND(RTIBOOST_MSVC, < 1300)

// MSVC6 seems not to like inline functions with const void* returns, so we
// declare the following here:

template <std::size_t S, std::size_t A>
const void* aligned_storage<S,A>::address() const
{
    return const_cast< aligned_storage<S,A>* >(this)->address();
}

#endif // MSVC6 workaround

#ifndef RTIBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
//
// Make sure that is_pod recognises aligned_storage<>::type
// as a POD (Note that aligned_storage<> itself is not a POD):
//
template <std::size_t size_, std::size_t alignment_>
struct is_pod<rtiboost::detail::aligned_storage::aligned_storage_imp<size_,alignment_> >
   RTIBOOST_TT_AUX_BOOL_C_BASE(true)
{ 
    RTIBOOST_TT_AUX_BOOL_TRAIT_VALUE_DECL(true)
}; 
#endif


} // namespace rtiboost

#include "rtiboost/type_traits/detail/bool_trait_undef.hpp"

#endif // RTIBOOST_ALIGNED_STORAGE_HPP
