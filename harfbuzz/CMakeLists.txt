project(vcpkg-test-harfbuzz)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

find_package(harfbuzz CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE harfbuzz::harfbuzz)

# =============================================================================

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main)
gtest_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
