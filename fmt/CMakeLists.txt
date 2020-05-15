project(vcpkg-test-fmt)

add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}-header-only main.cpp)

# =============================================================================

find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

# =============================================================================

find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME}-header-only PRIVATE fmt::fmt-header-only)

# =============================================================================

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_MAIN)
catch_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME}-header-only PRIVATE Catch2::Catch2)
target_compile_definitions(${PROJECT_NAME}-header-only PRIVATE CATCH_CONFIG_MAIN)
catch_discover_tests(${PROJECT_NAME}-header-only WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
