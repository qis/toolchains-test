project(vcpkg-test-giflib)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(GIF REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE GIF::GIF)
