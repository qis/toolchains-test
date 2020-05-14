system = linux
triplet = $(VCPKG_DEFAULT_TRIPLET)

all: all/$(system)

all/linux: clean
	@cmake -GNinja -DCMAKE_BUILD_TYPE=Debug \
	  -DCMAKE_TOOLCHAIN_FILE="$(CURDIR)/toolchain.cmake" \
	  -B build/$(triplet)/debug
	@cmake -GNinja -DCMAKE_BUILD_TYPE=Release \
	  -DCMAKE_TOOLCHAIN_FILE="$(CURDIR)/toolchain.cmake" \
	  -B build/$(triplet)/release
	@cmake --build build/$(triplet)/debug
	@cmake --build build/$(triplet)/release

all/windows: clean
	@cmake -GNinja -DCMAKE_BUILD_TYPE=Debug \
	  -DCMAKE_TOOLCHAIN_FILE="$(MAKEDIR)\toolchain.cmake" \
	  -B build/$(triplet)/debug
	@cmake -GNinja -DCMAKE_BUILD_TYPE=Release \
	  -DCMAKE_TOOLCHAIN_FILE="$(MAKEDIR)\toolchain.cmake" \
	  -B build/$(triplet)/release
	@cmake --build build/$(triplet)/debug
	@cmake --build build/$(triplet)/release

run:
	@cmake -E chdir build/$(triplet)/release benchmark/vcpkg-test-benchmark
	@cmake -E chdir build/$(triplet)/debug ctest
	@cmake -E chdir build/$(triplet)/release ctest

install:
	@vcpkg install --overlay-ports=$(overlay) \
	  benchmark:$(triplet) \
	  catch2:$(triplet) \
	  openssl:$(triplet) \
	  bzip2:$(triplet) \
	  liblzma:$(triplet) \
	  libzip:$(triplet) \
	  lz4:$(triplet) \
	  zlib:$(triplet) \
	  zstd:$(triplet) \
	  date:$(triplet) \
	  fmt:$(triplet) \
	  libssh2:$(triplet) \
	  pugixml:$(triplet) \
	  spdlog:$(triplet) \
	  utf8proc:$(triplet) \
	  giflib:$(triplet) \
	  libjpeg-turbo:$(triplet) \
	  libpng:$(triplet) \
	  tiff:$(triplet) \
	  freetype:$(triplet) \
	  harfbuzz:$(triplet) \
	  boost:$(triplet) \
	  tbb:$(triplet)

format:
	@cmake -P format.cmake

clean:
	@cmake -E remove_directory build/$(triplet)
