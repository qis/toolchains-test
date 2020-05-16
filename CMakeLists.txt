cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(tests LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Catch2 CONFIG REQUIRED)

include(CTest)
include(Catch)

# Development
add_subdirectory(benchmark)

# Encryption
add_subdirectory(openssl)

# Compression
add_subdirectory(bzip2)
add_subdirectory(liblzma)
add_subdirectory(libzip)
add_subdirectory(lz4)
add_subdirectory(zlib)
add_subdirectory(zstd)

# Utility
add_subdirectory(date)
add_subdirectory(fmt)
add_subdirectory(libssh2)
add_subdirectory(pugixml)
add_subdirectory(spdlog)
add_subdirectory(utf8proc)

# Images
add_subdirectory(giflib)
add_subdirectory(libjpeg)
add_subdirectory(libjpeg-turbo)
add_subdirectory(libpng)
add_subdirectory(tiff)

# Fonts
add_subdirectory(freetype)
add_subdirectory(harfbuzz)

# Overlays
add_subdirectory(boost)
add_subdirectory(tbb)
