project(vcpkg-test-lz4)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(lz4 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE lz4::lz4)
