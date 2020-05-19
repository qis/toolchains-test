project(vcpkg-test-libssh2)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

find_package(Libssh2 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Libssh2::libssh2)

# =============================================================================

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main)
gtest_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
