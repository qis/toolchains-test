project(vcpkg-test-liblzma)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

get_property(multi_config GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(multi_config)
  message(FATAL_ERROR "Multi-config generators are not supported.")
endif()

include(FindPackageHandleStandardArgs)
find_path(LZMA_INCLUDE_DIR lzma.h)
if(CMAKE_BUILD_TYPE MATCHES Debug)
  find_library(LZMA_LIBRARY NAMES lzmad)
else()
  find_library(LZMA_LIBRARY NAMES lzma)
endif()
find_package_handle_standard_args(LZMA DEFAULT_MSG LZMA_INCLUDE_DIR LZMA_LIBRARY)

target_include_directories(${PROJECT_NAME} PRIVATE ${LZMA_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LZMA_LIBRARY})

# =============================================================================

check_includes(${LZMA_INCLUDE_DIR})
check_libraries(${LZMA_LIBRARY})

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_MAIN)
catch_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
