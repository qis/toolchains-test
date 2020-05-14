project(vcpkg-test-utf8proc)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

find_path(UTF8PROC_INCLUDE_DIR utf8proc.h)
get_filename_component(UTF8PROC_ROOT_DIR ${UTF8PROC_INCLUDE_DIR} DIRECTORY)

find_library(UTF8PROC_LIBRARY_DEBUG NAMES utf8proc utf8proc_static
  NAMES_PER_DIR NO_CMAKE_PATH PATHS ${UTF8PROC_ROOT_DIR}/debug/lib)

find_library(UTF8PROC_LIBRARY_RELEASE NAMES utf8proc utf8proc_static
  NAMES_PER_DIR NO_CMAKE_PATH PATHS ${UTF8PROC_ROOT_DIR}/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(UTF8PROC DEFAULT_MSG
  UTF8PROC_INCLUDE_DIR UTF8PROC_LIBRARY_DEBUG UTF8PROC_LIBRARY_RELEASE)

add_library(utf8proc::utf8proc UNKNOWN IMPORTED)
set_target_properties(utf8proc::utf8proc PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${UTF8PROC_INCLUDE_DIR}"
  IMPORTED_LINK_INTERFACE_LANGUAGES "C"
  IMPORTED_CONFIGURATIONS "DEBUG;RELEASE"
  MAP_IMPORTED_CONFIG_MINSIZEREL Release
  MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
  IMPORTED_LOCATION_DEBUG "${UTF8PROC_LIBRARY_DEBUG}"
  IMPORTED_LOCATION_RELEASE "${UTF8PROC_LIBRARY_RELEASE}")

get_filename_component(UTF8PROC_LIBRARY_NAME_DEBUG ${UTF8PROC_LIBRARY_DEBUG} NAME_WE)
if(UTF8PROC_LIBRARY_NAME_DEBUG STREQUAL "utf8proc_static")
  set_property(TARGET utf8proc::utf8proc APPEND PROPERTY
    INTERFACE_COMPILE_DEFINITIONS "$<$<CONFIG:Debug>:UTF8PROC_STATIC=1>")
endif()

get_filename_component(UTF8PROC_LIBRARY_NAME_RELEASE ${UTF8PROC_LIBRARY_RELEASE} NAME_WE)
if(UTF8PROC_LIBRARY_NAME_RELEASE STREQUAL "utf8proc_static")
  set_property(TARGET utf8proc::utf8proc APPEND PROPERTY
    INTERFACE_COMPILE_DEFINITIONS "$<$<CONFIG:Release>:UTF8PROC_STATIC=1>")
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE utf8proc::utf8proc)

# =============================================================================

check_targets(utf8proc::utf8proc)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_MAIN)
catch_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
