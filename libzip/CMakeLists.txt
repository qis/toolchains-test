project(vcpkg-test-libzip)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

find_package(ZIP REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ZIP::ZIP)

# =============================================================================

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main)
gtest_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
