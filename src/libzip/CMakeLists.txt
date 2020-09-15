project(vcpkg-test-libzip)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(ZIP REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ZIP::ZIP)
