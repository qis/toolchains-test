project(vcpkg-test-lz4)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

find_package(lz4 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE lz4::lz4)

# =============================================================================

check_targets(lz4::lz4)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_MAIN)
catch_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
