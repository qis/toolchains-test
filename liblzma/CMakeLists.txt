project(vcpkg-test-liblzma)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

find_package(LibLZMA CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE LibLZMA::LibLZMA)

# =============================================================================

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main)
gtest_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
