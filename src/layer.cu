#include<iostream>
#include<cassert>
#include<cuda_runtime.h>
#include"layer.h"
#include"utils.h"

#define CUDA_CHECK(err)                                                                    \
    if (err != cudaSuccess)                                                                \
    {                                                                                      \
        std::cerr << "CUDA error: " << " at " << __FILE__ << ":" << __LINE__ << std::endl; \
        std::exit(EXIT_FAILURE);                                                           \
    }