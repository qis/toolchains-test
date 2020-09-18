project(vcpkg-test-boost)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(Boost REQUIRED COMPONENTS headers filesystem)
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::headers Boost::filesystem)
target_compile_definitions(${PROJECT_NAME} PRIVATE
  BOOST_ASIO_HAS_CO_AWAIT
  BOOST_ASIO_DISABLE_CONCEPTS
  BOOST_ASIO_SEPARATE_COMPILATION
  BOOST_BEAST_SEPARATE_COMPILATION
  BOOST_BEAST_USE_STD_STRING_VIEW
  BOOST_JSON_STANDALONE)
