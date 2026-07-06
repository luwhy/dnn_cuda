cmake_minimum_required(VERSION 3.15)
project(dnn_cuda)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#启动MPI支持
find_package(MPI REQUIRED)

#启动CUDA支持
find_package(CUDA REQUIRED)

file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cu)

add_executable(dnn_cuda ${SRC})

target_link_libraries(dnn_cuda PRIVATE MPI::MPI_CXX)

target_link_libraries(dnn_cuda PRIVATE ${CUDA_LIBRARIES})
target_include_directories(dnn_cuda PRIVATE ${CUDA_INCLUDE_DIRS})

#    c) 如果 CMake 没有自动为 .cu 文件设置正确的包含路径，可以手动添加：
#    这通常是必要的，以便在 .cu 文件中包含 cuda_runtime.h 等头文件。
target_include_directories(dnn_cuda PRIVATE ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES})

set(CMAKE_CUDA_ARCHITECTURES "native")