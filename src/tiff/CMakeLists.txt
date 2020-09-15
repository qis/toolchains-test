project(vcpkg-test-tiff)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(TIFF REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE TIFF::TIFF)
