project(vcpkg-test-utf8proc)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

get_property(multi_config GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(multi_config)
  message(FATAL_ERROR "Multi-config generators are not supported.")
endif()

include(FindPackageHandleStandardArgs)
find_path(UTF8PROC_INCLUDE_DIR utf8proc.h)
find_library(UTF8PROC_LIBRARY NAMES utf8proc utf8proc_static)
get_filename_component(UTF8PROC_LIBRARY_NAME ${UTF8PROC_LIBRARY} NAME_WE)
if(UTF8PROC_LIBRARY_NAME STREQUAL utf8proc_static)
  set(UTF8PROC_DEFINITIONS UTF8PROC_STATIC=1)
else()
  set(UTF8PROC_DEFINITIONS)
endif()
find_package_handle_standard_args(UTF8PROC DEFAULT_MSG UTF8PROC_INCLUDE_DIR UTF8PROC_LIBRARY UTF8PROC_DEFINITIONS)

target_compile_definitions(${PROJECT_NAME} PRIVATE ${UTF8PROC_DEFINITIONS})
target_include_directories(${PROJECT_NAME} PRIVATE ${UTF8PROC_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${UTF8PROC_LIBRARY})

# =============================================================================

check_includes(${UTF8PROC_INCLUDE_DIR})
check_libraries(${UTF8PROC_LIBRARY})

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_MAIN)
catch_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
