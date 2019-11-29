cmake_minimum_required(VERSION 3.1)

# Require C++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(cereal-1.3.0/include/)

add_executable(run_test2
    src/main2.cxx
)
