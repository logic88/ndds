//  (C) Copyright Eric Jourdanneau, Joel Falcou 2010
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  NVIDIA CUDA C++ compiler setup

#ifndef RTIBOOST_COMPILER
#  define RTIBOOST_COMPILER "NVIDIA CUDA C++ Compiler"
#endif

// NVIDIA Specific support
// RTIBOOST_GPU_ENABLED : Flag a function or a method as being enabled on the host and device
#define RTIBOOST_GPU_ENABLED __host__ __device__
