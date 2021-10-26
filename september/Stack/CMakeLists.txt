cmake_minimum_required(VERSION 3.16.3)
project(Google_tests)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run test.cpp Bool_Stack.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)