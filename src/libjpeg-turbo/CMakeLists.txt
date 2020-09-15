project(vcpkg-test-libjpeg-turbo)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(JPEGTURBO REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE JPEGTURBO::JPEGTURBO)
