//  Boost noncopyable.hpp header file  --------------------------------------//

//  (C) Copyright Beman Dawes 1999-2003. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/utility for documentation.

#ifndef RTIBOOST_NONCOPYABLE_HPP_INCLUDED
#define RTIBOOST_NONCOPYABLE_HPP_INCLUDED

#include <rtiboost/config.hpp>

namespace rtiboost {

//  Private copy constructor and copy assignment ensure classes derived from
//  class noncopyable cannot be copied.

//  Contributed by Dave Abrahams

namespace noncopyable_  // protection from unintended ADL
{
  class noncopyable
  {
   protected:
#ifndef RTIBOOST_NO_DEFAULTED_FUNCTIONS
    RTIBOOST_CONSTEXPR noncopyable() = default;
    ~noncopyable() = default;
#else
    noncopyable() {}
      ~noncopyable() {}
#endif
#ifndef RTIBOOST_NO_DELETED_FUNCTIONS
        noncopyable( const noncopyable& ) = delete;
        noncopyable& operator=( const noncopyable& ) = delete;
#else
    private:  // emphasize the following members are private
      noncopyable( const noncopyable& );
      noncopyable& operator=( const noncopyable& );
#endif
  };
}

typedef noncopyable_::noncopyable noncopyable;

} // namespace rtiboost

#endif  // RTIBOOST_NONCOPYABLE_HPP_INCLUDED
