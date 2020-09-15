project(vcpkg-test-dtz)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(dtz CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE dtz::dtz)
