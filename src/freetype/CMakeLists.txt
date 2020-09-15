project(vcpkg-test-freetype)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(freetype CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE freetype)
