project(vcpkg-test-libjpeg-turbo)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

get_property(multi_config GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(multi_config)
  message(FATAL_ERROR "Multi-config generators are not supported.")
endif()

include(FindPackageHandleStandardArgs)
find_path(TURBOJPEG_INCLUDE_DIR utf8proc.h)
if(WIN32 AND CMAKE_BUILD_TYPE MATCHES Debug)
  find_library(TURBOJPEG_LIBRARY NAMES turbojpegd)
else()
  find_library(TURBOJPEG_LIBRARY NAMES turbojpeg)
endif()
find_package_handle_standard_args(TURBOJPEG DEFAULT_MSG TURBOJPEG_INCLUDE_DIR TURBOJPEG_LIBRARY)

target_include_directories(${PROJECT_NAME} PRIVATE ${TURBOJPEG_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${TURBOJPEG_LIBRARY})

# =============================================================================

check_includes(${TURBOJPEG_INCLUDE_DIR})
check_libraries(${TURBOJPEG_LIBRARY})

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_MAIN)
catch_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
