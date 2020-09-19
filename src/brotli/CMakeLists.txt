project(vcpkg-test-brotli)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(unofficial-brotli CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE
  unofficial::brotli::brotlicommon
  unofficial::brotli::brotlidec
  unofficial::brotli::brotlienc)
