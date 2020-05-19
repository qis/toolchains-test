project(vcpkg-test-libpng)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

find_package(PNG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE PNG::PNG)

# =============================================================================

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main)
gtest_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
