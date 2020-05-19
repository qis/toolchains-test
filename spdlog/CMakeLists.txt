project(vcpkg-test-spdlog)

add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}-header-only main.cpp)

# =============================================================================

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)

# =============================================================================

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME}-header-only PRIVATE spdlog::spdlog_header_only)

# =============================================================================

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main)
gtest_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME}-header-only PRIVATE GTest::gtest GTest::gtest_main)
gtest_discover_tests(${PROJECT_NAME}-header-only WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
