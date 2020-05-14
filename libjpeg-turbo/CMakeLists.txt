project(vcpkg-test-libjpeg-turbo)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

find_path(TURBOJPEG_INCLUDE_DIR turbojpeg.h)
get_filename_component(TURBOJPEG_ROOT_DIR ${TURBOJPEG_INCLUDE_DIR} DIRECTORY)

find_library(TURBOJPEG_LIBRARY_DEBUG NAMES turbojpeg turbojpegd
  NAMES_PER_DIR NO_CMAKE_PATH PATHS ${TURBOJPEG_ROOT_DIR}/debug/lib)

find_library(TURBOJPEG_LIBRARY_RELEASE NAMES turbojpeg
  NAMES_PER_DIR NO_CMAKE_PATH PATHS ${TURBOJPEG_ROOT_DIR}/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(TURBOJPEG DEFAULT_MSG
  TURBOJPEG_INCLUDE_DIR TURBOJPEG_LIBRARY_DEBUG TURBOJPEG_LIBRARY_RELEASE)

add_library(turbojpeg::turbojpeg UNKNOWN IMPORTED)
set_target_properties(turbojpeg::turbojpeg PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${TURBOJPEG_INCLUDE_DIR}"
  IMPORTED_LINK_INTERFACE_LANGUAGES "C"
  IMPORTED_CONFIGURATIONS "DEBUG;RELEASE"
  MAP_IMPORTED_CONFIG_MINSIZEREL Release
  MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
  IMPORTED_LOCATION_DEBUG "${TURBOJPEG_LIBRARY_DEBUG}"
  IMPORTED_LOCATION_RELEASE "${TURBOJPEG_LIBRARY_RELEASE}")

target_link_libraries(${PROJECT_NAME} PRIVATE turbojpeg::turbojpeg)

# =============================================================================

check_targets(turbojpeg::turbojpeg)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_MAIN)
catch_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
