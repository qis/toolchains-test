project(vcpkg-test-benchmark)
add_executable(${PROJECT_NAME} main.cpp)

find_package(benchmark CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE benchmark::benchmark_main)
