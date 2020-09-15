project(vcpkg-test-zstd)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(zstd CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE libzstd)
