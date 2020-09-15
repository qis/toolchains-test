project(vcpkg-test-openssl)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(OpenSSL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenSSL::Crypto OpenSSL::SSL)
