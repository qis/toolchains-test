project(vcpkg-test-harfbuzz)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

find_package(harfbuzz CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE harfbuzz::harfbuzz)

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /wd4172)
endif()

# =============================================================================

check_targets(harfbuzz::harfbuzz)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_MAIN)
catch_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
