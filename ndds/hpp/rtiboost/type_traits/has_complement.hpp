//  (C) Copyright 2009-2011 Frederic Bron.
//
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef RTIBOOST_TT_HAS_COMPLEMENT_HPP_INCLUDED
#define RTIBOOST_TT_HAS_COMPLEMENT_HPP_INCLUDED

#define RTIBOOST_TT_TRAIT_NAME has_complement
#define RTIBOOST_TT_TRAIT_OP ~
#define RTIBOOST_TT_FORBIDDEN_IF\
   ::rtiboost::type_traits::ice_or<\
      /* pointer */\
      ::rtiboost::is_pointer< Rhs_noref >::value,\
      /* fundamental non integral */\
      ::rtiboost::type_traits::ice_and<\
         ::rtiboost::is_fundamental< Rhs_noref >::value,\
         ::rtiboost::type_traits::ice_not< ::rtiboost::is_integral< Rhs_noref >::value >::value\
      >::value\
   >::value


#include <rtiboost/type_traits/detail/has_prefix_operator.hpp>

#undef RTIBOOST_TT_TRAIT_NAME
#undef RTIBOOST_TT_TRAIT_OP
#undef RTIBOOST_TT_FORBIDDEN_IF

#endif
