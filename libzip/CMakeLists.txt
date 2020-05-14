project(vcpkg-test-libzip)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

find_path(ZIP_INCLUDE_DIR zip.h)
find_library(ZIP_LIBRARY NAMES zip)
target_include_directories(${PROJECT_NAME} PRIVATE ${ZIP_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${ZIP_LIBRARY})

# =============================================================================

check_includes(${ZIP_INCLUDE_DIR})
check_libraries(${ZIP_LIBRARY})

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_MAIN)
catch_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
