project(vcpkg-test-libzip)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

find_path(ZIP_INCLUDE_DIR zip.h)
get_filename_component(ZIP_ROOT_DIR ${ZIP_INCLUDE_DIR} DIRECTORY)

find_library(ZIP_LIBRARY_DEBUG NAMES zip
  NAMES_PER_DIR NO_CMAKE_PATH PATHS ${ZIP_ROOT_DIR}/debug/lib)

find_library(ZIP_LIBRARY_RELEASE NAMES zip
  NAMES_PER_DIR NO_CMAKE_PATH PATHS ${ZIP_ROOT_DIR}/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(ZIP DEFAULT_MSG
  ZIP_INCLUDE_DIR ZIP_LIBRARY_DEBUG ZIP_LIBRARY_RELEASE)

add_library(zip::zip UNKNOWN IMPORTED)
set_target_properties(zip::zip PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${ZIP_INCLUDE_DIR}"
  IMPORTED_LINK_INTERFACE_LANGUAGES "C"
  IMPORTED_CONFIGURATIONS "DEBUG;RELEASE"
  MAP_IMPORTED_CONFIG_MINSIZEREL Release
  MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
  IMPORTED_LOCATION_DEBUG "${ZIP_LIBRARY_DEBUG}"
  IMPORTED_LOCATION_RELEASE "${ZIP_LIBRARY_RELEASE}")

target_link_libraries(${PROJECT_NAME} PRIVATE zip::zip)

# =============================================================================

check_targets(zip::zip)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_MAIN)
catch_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
