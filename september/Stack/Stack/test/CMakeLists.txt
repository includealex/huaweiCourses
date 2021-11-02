cmake_minimum_required(VERSION 3.16.3)
project(StackTest)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

file(GLOB_RECURSE STACK_TEST_SOURCES *.cpp)
set(EXEC_NAME stack_test)

add_executable(${EXEC_NAME} ${STACK_TEST_SOURCES})

add_custom_target(run_${EXEC_NAME}
                  COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${EXEC_NAME})
add_dependencies(run_${EXEC_NAME} ${EXEC_NAME})

if(ADD_SANITIZERS)
    target_compile_options(${EXEC_NAME} PUBLIC -fsanitize=address -g)
    set_target_properties(${EXEC_NAME} PROPERTIES LINK_FLAGS "-fsanitize=address")
endif()

target_link_libraries(${EXEC_NAME} gtest_main stack)

include(GoogleTest)
gtest_discover_tests(${EXEC_NAME} PROPERTIES LABELS "unit")