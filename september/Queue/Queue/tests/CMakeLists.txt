cmake_minimum_required(VERSION 3.9)
project(Test_Queues VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDART 11)

set(EXEC_FILE_C tests_for_circle_queue)
set(EXEC_FILE_S tests_for_stack_queue)
set(TEST_FILE_C run_${EXEC_FILE_C})
set(TEST_FILE_S run_${EXEC_FILE_S})
set(INCL_PATH "../includes/")

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/release-1.10.0.tar.gz)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${EXEC_FILE_C} tests.cpp)
target_compile_definitions(${EXEC_FILE_C} PUBLIC -DCIRCULAR_IMPL)
target_link_libraries(${EXEC_FILE_C} gtest_main)
target_include_directories(${EXEC_FILE_C} PUBLIC ${INCL_PATH})

include(GoogleTest)
gtest_discover_tests(${EXEC_FILE_C})

add_custom_target(
    ${TEST_FILE_C}
    COMMENT "Running tests for \"circular\" queue"
    COMMAND ./${EXEC_FILE_C}
)
add_dependencies(${TEST_FILE_C} ${EXEC_FILE_C})

add_executable(${EXEC_FILE_S} tests.cpp)
target_compile_definitions(${EXEC_FILE_S} PUBLIC -DSTACK_IMPL)
target_link_libraries(${EXEC_FILE_S} gtest_main)
target_include_directories(${EXEC_FILE_S} PUBLIC ${INCL_PATH})

gtest_discover_tests(${EXEC_FILE_S})

add_custom_target(
    ${TEST_FILE_S}
    COMMENT "Running tests for \"stack\" queue"
    COMMAND ./${EXEC_FILE_S}
)
add_dependencies(${TEST_FILE_S} ${EXEC_FILE_S})

if (ADD_SANITIZERS)
    target_compile_options(${EXEC_FILE_C} PUBLIC -fsanitize=address -g)
    set_target_properties(${EXEC_FILE_C}  PROPERTIES LINK_FLAGS "-fsanitize=address")
    target_compile_options(${EXEC_FILE_S} PUBLIC -fsanitize=address -g)
    set_target_properties(${EXEC_FILE_S}  PROPERTIES LINK_FLAGS "-fsanitize=address")
endif()