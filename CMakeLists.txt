cmake_minimum_required(VERSION 3.1)

# Require C++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(Boost_NO_BOOST_CMAKE ON)

find_package(Boost COMPONENTS system iostreams filesystem REQUIRED)

include_directories(include)
include_directories(.)

add_library(certest SHARED
    src/file0.cxx
#    src/file1.cxx
#    src/file2.cxx
)

add_executable(run_test src/main.cxx)
target_link_libraries(run_test certest)

# This version is linked directly together without going through a
# shared lib!
add_executable(run_test1
    src/main.cxx
    src/file0.cxx
#    src/file1.cxx
#    src/file2.cxx
)
