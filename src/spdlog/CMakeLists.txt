project(vcpkg-test-spdlog)
add_vcpkg_test(${PROJECT_NAME} main.cpp)
add_vcpkg_test(${PROJECT_NAME}-header-only main.cpp)

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME}-header-only PRIVATE spdlog::spdlog_header_only)
