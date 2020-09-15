project(vcpkg-test-zlib)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(ZLIB REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ZLIB::ZLIB)
