project(vcpkg-test-libjpeg)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(JPEG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE JPEG::JPEG)
