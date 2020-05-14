project(vcpkg-test-openssl)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

find_package(OpenSSL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenSSL::Crypto OpenSSL::SSL)

if(WIN32)
  target_link_libraries(${PROJECT_NAME} PRIVATE crypt32 ws2_32)
endif()

# =============================================================================

check_targets(OpenSSL::Crypto OpenSSL::SSL)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_MAIN)
catch_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
