project(vcpkg-test-liblzma)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(LibLZMA CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE LibLZMA::LibLZMA)
