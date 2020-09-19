cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(vcpkg-test VERSION 0.1.0 LANGUAGES CXX)

# Testing
enable_testing()
include(GoogleTest)
find_package(GTest CONFIG REQUIRED)

# Functions
function(add_vcpkg_test name)
  add_executable(${ARGV})
  target_link_libraries(${name} PRIVATE GTest::gtest GTest::gtest_main)
  gtest_discover_tests(${name} WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
endfunction()

# Encryption
add_subdirectory(src/openssl)

# Compression
add_subdirectory(src/brotli)
add_subdirectory(src/bzip2)
add_subdirectory(src/liblzma)
add_subdirectory(src/libzip)
add_subdirectory(src/lz4)
add_subdirectory(src/zlib)
add_subdirectory(src/zstd)

# Utility
add_subdirectory(src/dtz)
add_subdirectory(src/fmt)
add_subdirectory(src/libssh2)
add_subdirectory(src/pugixml)
add_subdirectory(src/spdlog)
add_subdirectory(src/tbb)
add_subdirectory(src/utf8proc)

# Images
add_subdirectory(src/giflib)
add_subdirectory(src/libjpeg-turbo)
add_subdirectory(src/libpng)
add_subdirectory(src/tiff)

# Fonts
add_subdirectory(src/freetype)
add_subdirectory(src/harfbuzz)

# Boost
add_subdirectory(src/boost)

# Benchmark
add_subdirectory(src/benchmark)
