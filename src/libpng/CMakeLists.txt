project(vcpkg-test-libpng)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(PNG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE PNG::PNG)
