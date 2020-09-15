project(vcpkg-test-fmt)
add_vcpkg_test(${PROJECT_NAME} main.cpp)
add_vcpkg_test(${PROJECT_NAME}-header-only main.cpp)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME}-header-only PRIVATE fmt::fmt-header-only)
