#pragma once
#include"layer.h"
#include<vector>
#include<mpi/mpi.h>

class Model
{
public:
    Model(int batch_size = 32);

private:
    Conv2d conv_;
};