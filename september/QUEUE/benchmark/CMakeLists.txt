find_package(benchmark REQUIRED)

set(EXEC timeResearch)
set(RUN_EXEC run_${EXEC})
set(INCL_PATH "../Queue/includes/")

add_executable(${EXEC} ${EXEC}.cpp)
target_link_libraries(${EXEC} benchmark::benchmark)
target_include_directories(${EXEC} PUBLIC ${INCL_PATH})

add_custom_target(
    ${RUN_EXEC}
	COMMAND ./${EXEC}
)