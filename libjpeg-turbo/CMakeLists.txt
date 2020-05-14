project(vcpkg-test-libjpeg-turbo)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

find_path(LIBJPEG_TURBO_INCLUDE_DIR turbojpeg.h)
if(WIN32 AND CMAKE_BUILD_TYPE MATCHES Debug)
  find_library(LIBJPEG_TURBO_LIBRARY NAMES turbojpegd)
else()
  find_library(LIBJPEG_TURBO_LIBRARY NAMES turbojpeg)
endif()
target_include_directories(${PROJECT_NAME} PRIVATE ${LIBJPEG_TURBO_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBJPEG_TURBO_LIBRARY})

# =============================================================================

check_includes(${LIBJPEG_TURBO_INCLUDE_DIR})
check_libraries(${LIBJPEG_TURBO_LIBRARY})

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_MAIN)
catch_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
