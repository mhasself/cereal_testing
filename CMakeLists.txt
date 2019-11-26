cmake_minimum_required(VERSION 3.1)

# Require C++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

add_library(certest SHARED
    src/file1.cxx
    src/file2.cxx
)

add_executable(run_test src/main.cxx)
target_link_libraries(run_test certest)
