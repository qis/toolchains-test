project(vcpkg-test-tbb)
add_vcpkg_test(${PROJECT_NAME} main.cpp)

find_package(TBB CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE TBB::tbb TBB::tbbmalloc)
