project(vcpkg-test-utf8proc)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

find_package(Utf8Proc REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE utf8proc::utf8proc)

# =============================================================================

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main)
gtest_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
