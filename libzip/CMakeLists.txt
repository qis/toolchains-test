project(vcpkg-test-libzip)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

get_property(multi_config GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(multi_config)
  message(FATAL_ERROR "Multi-config generators are not supported.")
endif()

include(FindPackageHandleStandardArgs)
find_path(ZIP_INCLUDE_DIR zip.h)
find_library(ZIP_LIBRARY NAMES zip)
find_package_handle_standard_args(ZIP DEFAULT_MSG ZIP_INCLUDE_DIR ZIP_LIBRARY)

target_include_directories(${PROJECT_NAME} PRIVATE ${ZIP_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${ZIP_LIBRARY})

# =============================================================================

check_includes(${ZIP_INCLUDE_DIR})
check_libraries(${ZIP_LIBRARY})

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_MAIN)
catch_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
