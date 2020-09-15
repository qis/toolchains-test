project(vcpkg-test-harfbuzz)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(harfbuzz CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE harfbuzz::harfbuzz)
