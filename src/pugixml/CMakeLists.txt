project(vcpkg-test-pugixml)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(pugixml CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE pugixml)
