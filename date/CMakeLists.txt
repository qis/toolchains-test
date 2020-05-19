project(vcpkg-test-date)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(date CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE date::date date::tz)

include(tzdata)
tzdata(${PROJECT_NAME} 2020a ${CMAKE_CURRENT_BINARY_DIR}/tzdata)

find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

# =============================================================================

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main)
gtest_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} DISCOVERY_TIMEOUT 60)
