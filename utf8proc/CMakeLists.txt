project(vcpkg-test-utf8proc)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

find_path(UTF8PROC_INCLUDE_DIR utf8proc.h)
find_library(UTF8PROC_LIBRARY NAMES utf8proc utf8proc_static)
target_compile_definitions(${PROJECT_NAME} PRIVATE UTF8PROC_STATIC=1)
target_include_directories(${PROJECT_NAME} PRIVATE ${UTF8PROC_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${UTF8PROC_LIBRARY})

# =============================================================================

check_includes(${UTF8PROC_INCLUDE_DIR})
check_libraries(${UTF8PROC_LIBRARY})

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_MAIN)
catch_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
