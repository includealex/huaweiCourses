cmake_minimum_required(VERSION 3.16.3)
project(QueueTest)

set(CMAKE_CXX_STANDARD 11)

set(EXEC tests.cpp)
set(CIRCUL_QUEUE circular_queue_tests)
set(STACK_QUEUE stack_queue_tests)
set(PTH_INCL "../includes/")

include(FetchContent)
FetchContent_Declare(googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${CIRCUL_QUEUE} ${EXEC})
target_compile_definitions(${CIRCUL_QUEUE} PUBLIC -DCIRCULAR_IMPL)
target_link_libraries(${CIRCUL_QUEUE} gtest_main)

include(GoogleTest)
gtest_discover_tests(${CIRCUL_QUEUE})

add_custom_target (
    run_${CIRCUL_QUEUE}
    COMMAND ./${CIRCUL_QUEUE}
)

add_dependencies(run_${CIRCUL_QUEUE} ${CIRCUL_QUEUE})

add_executable(${STACK_QUEUE} ${EXEC})
target_compile_definitions(${STACK_QUEUE} PUBLIC -DSTACK_IMPL)
target_link_libraries(${STACK_QUEUE} gtest_main)

include(GoogleTest)
gtest_discover_tests(${STACK_QUEUE})

add_custom_target (
    run_${STACK_QUEUE}
    COMMAND ./${STACK_QUEUE}
)

add_dependencies(run_${STACK_QUEUE} ${STACK_QUEUE})

if(ADD_SANITIZERS)
    target_compile_options(${CIRCUL_QUEUE} PUBLIC -fsanitize=address -g)
    set_target_properties(${CIRCUL_QUEUE}  PROPERTIES LINK_FLAGS "-fsanitize=address")
    target_compile_options(${STACK_QUEUE} PUBLIC -fsanitize=address -g)
    set_target_properties(${STACK_QUEUE}  PROPERTIES LINK_FLAGS "-fsanitize=address")
endif()    