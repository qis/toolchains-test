project(vcpkg-test-liblzma)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

find_path(LZMA_INCLUDE_DIR lzma.h)
get_filename_component(LZMA_ROOT_DIR ${LZMA_INCLUDE_DIR} DIRECTORY)

find_library(LZMA_LIBRARY_DEBUG NAMES lzma lzmad
  NAMES_PER_DIR NO_CMAKE_PATH PATHS ${LZMA_ROOT_DIR}/debug/lib)

find_library(LZMA_LIBRARY_RELEASE NAMES lzma
  NAMES_PER_DIR NO_CMAKE_PATH PATHS ${LZMA_ROOT_DIR}/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(LZMA DEFAULT_MSG
  LZMA_INCLUDE_DIR LZMA_LIBRARY_DEBUG LZMA_LIBRARY_RELEASE)

add_library(lzma::lzma UNKNOWN IMPORTED)
set_target_properties(lzma::lzma PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${LZMA_INCLUDE_DIR}"
  IMPORTED_LINK_INTERFACE_LANGUAGES "C"
  IMPORTED_CONFIGURATIONS "DEBUG;RELEASE"
  MAP_IMPORTED_CONFIG_MINSIZEREL Release
  MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
  IMPORTED_LOCATION_DEBUG "${LZMA_LIBRARY_DEBUG}"
  IMPORTED_LOCATION_RELEASE "${LZMA_LIBRARY_RELEASE}")

target_link_libraries(${PROJECT_NAME} PRIVATE lzma::lzma)

# =============================================================================

check_targets(lzma::lzma)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_MAIN)
catch_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
