#pragma once

#include<cstdlib>
#include <cuda_runtime.h>
template<typename T>
class Layer{
public:
    Layer()=default;
    ~Layer()=default;
    float *forward_cpu(float *input, int H, int W)
    {
        static<T *>(this)->forward_cpu(input, H, W);
    }
    float *forward_gpu(float *doutput)
    {
        static<T *>(this)->forward_gpu(doutput);
    }

    float *forward_gpu(float *input, int H, int W)
    {
        static_cast<T *>(this)->forward_gpu(input, H, W);
    }

    float *backward_gpu(float *output){
        static_cast<T*>(this)->backward(output);
    }
};

class Conv2d:public Layer<Conv2d>{
    Conv2d(int batch_size,int in_channels,int out_channels,int kernel_size,int stride=1,int padding=0);
    ~Conv2d();
    //cpu 版本的forward和backward
    float* forward_cpu(float* input, int H ,int W);
    float* backward_cpu(float* doutput);

    //gpu 版本的forward/backward
    float* forward_gpu(float* input,int H ,int W);
    float* backward_gpu(float* doutput_d);

    //通用接口，根据
};