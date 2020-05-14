project(vcpkg-test-giflib)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

find_package(GIF REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE GIF::GIF)

# =============================================================================

check_targets(GIF::GIF)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_MAIN)
catch_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
