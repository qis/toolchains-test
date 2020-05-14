project(vcpkg-test-tiff)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

find_package(TIFF REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE TIFF::TIFF)

# =============================================================================

check_targets(TIFF::TIFF)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_MAIN)
catch_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
