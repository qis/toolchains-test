project(vcpkg-test-libssh2)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(Libssh2 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Libssh2::libssh2)
