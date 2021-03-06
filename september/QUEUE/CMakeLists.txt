cmake_minimum_required(VERSION 3.16.3)
project(Queue)

file(GLOB_RECURSE ALL_CXX_SOURCE_FILES *.cpp *.hpp)

find_program(CLANG_FORMAT "clang-format" REQUIRED)
add_custom_target (
    format
    COMMAND clang-format
    -i
    -style=file
    ${ALL_CXX_SOURCE_FILES}
)

set(CMAKE_CXX_CLANG_TIDY
    clang-tidy
    --format-style=file
    --header-filter=*.hpp
)

add_subdirectory(benchmark)
add_subdirectory(tests)