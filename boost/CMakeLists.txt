project(vcpkg-test-boost)

add_executable(${PROJECT_NAME} main.cpp)

# =============================================================================

find_package(Boost 1.73.0 CONFIG REQUIRED COMPONENTS headers filesystem)
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::headers Boost::filesystem)
target_compile_definitions(${PROJECT_NAME} PRIVATE
  BOOST_ASIO_HAS_CO_AWAIT
  BOOST_ASIO_DISABLE_CONCEPTS
  BOOST_ASIO_SEPARATE_COMPILATION
  BOOST_BEAST_SEPARATE_COMPILATION
  BOOST_BEAST_USE_STD_STRING_VIEW
  BOOST_JSON_STANDALONE)

# =============================================================================

check_targets(Boost::filesystem)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_MAIN)
catch_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
