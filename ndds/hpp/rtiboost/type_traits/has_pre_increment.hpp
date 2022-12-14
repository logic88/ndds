//  (C) Copyright 2009-2011 Frederic Bron.
//
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef RTIBOOST_TT_HAS_PRE_INCREMENT_HPP_INCLUDED
#define RTIBOOST_TT_HAS_PRE_INCREMENT_HPP_INCLUDED

#define RTIBOOST_TT_TRAIT_NAME has_pre_increment
#define RTIBOOST_TT_TRAIT_OP ++
#define RTIBOOST_TT_FORBIDDEN_IF\
   ::rtiboost::type_traits::ice_or<\
      /* bool */\
      ::rtiboost::is_same< bool, Rhs_nocv >::value,\
      /* void* */\
      ::rtiboost::type_traits::ice_and<\
         ::rtiboost::is_pointer< Rhs_noref >::value,\
         ::rtiboost::is_void< Rhs_noptr >::value\
      >::value,\
      /* (fundamental or pointer) and const */\
      ::rtiboost::type_traits::ice_and<\
         ::rtiboost::type_traits::ice_or<\
            ::rtiboost::is_fundamental< Rhs_nocv >::value,\
            ::rtiboost::is_pointer< Rhs_noref >::value\
         >::value,\
         ::rtiboost::is_const< Rhs_noref >::value\
      >::value\
   >::value


#include <rtiboost/type_traits/detail/has_prefix_operator.hpp>

#undef RTIBOOST_TT_TRAIT_NAME
#undef RTIBOOST_TT_TRAIT_OP
#undef RTIBOOST_TT_FORBIDDEN_IF

#endif
