project(vcpkg-test-bzip2)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(BZip2 REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE BZip2::BZip2)
