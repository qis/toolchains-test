project(vcpkg-test-utf8proc)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(Utf8Proc REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE utf8proc::utf8proc)
