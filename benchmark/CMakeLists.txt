project(vcpkg-test-benchmark)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

find_package(benchmark CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE benchmark::benchmark benchmark::benchmark_main)

# =============================================================================

check_targets(benchmark::benchmark benchmark::benchmark_main)

add_custom_target(benchmark COMMAND $<TARGET_FILE:${PROJECT_NAME}> DEPENDS ${PROJECT_NAME}
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} USES_TERMINAL)
