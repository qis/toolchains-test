cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(tests LANGUAGES C CXX)

list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_LIST_DIR})
include(check)

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
