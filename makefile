system = linux

all: build/$(system)/debug/rules.ninja build/$(system)/release/rules.ninja
	@cmake -E time $(MAKE) system=$(system) all/debug
	@cmake -E time $(MAKE) system=$(system) all/release

all/debug: build/$(system)/debug/rules.ninja
	@cmake -E echo "Building Debug ..."
	@cmake --build build/$(system)/debug > build/$(system)-debug.log

all/release: build/$(system)/release/rules.ninja
	@cmake -E echo "Building Release ..."
	@cmake --build build/$(system)/release > build/$(system)-release.log

run:
	@cmake -E chdir build/$(system)/release benchmark/vcpkg-test-benchmark
	@cmake -E time $(MAKE) system=$(system) run/debug
	@cmake -E time $(MAKE) system=$(system) run/release

run/debug:
	@cmake -E chdir build/$(system)/debug ctest

run/release:
	@cmake -E chdir build/$(system)/release ctest

install:
	@vcpkg install --overlay-ports=$(VCPKG_PORTS) \
	  benchmark \
	  catch2 \
	  openssl \
	  bzip2 \
	  liblzma \
	  libzip \
	  lz4 \
	  zlib \
	  zstd \
	  date \
	  fmt \
	  libssh2 \
	  pugixml \
	  spdlog \
	  utf8proc \
	  giflib \
	  libjpeg-turbo \
	  libpng \
	  tiff \
	  freetype \
	  harfbuzz \
	  boost \
	  tbb

format:
	@cmake -P "$(VCPKG_ROOT)/triplets/toolchains/format.cmake"

clean:
	@cmake -E remove_directory build/$(system)

build/windows/debug/rules.ninja: CMakeLists.txt
	@cmake -GNinja -DCMAKE_BUILD_TYPE=Debug \
	  -DCMAKE_INSTALL_PREFIX="$(MAKEDIR)\build\install" \
	  -DCMAKE_TOOLCHAIN_FILE="$(VCPKG_ROOT)\triplets\toolchains\windows.cmake" \
	  -DCMAKE_VERBOSE_MAKEFILE=ON \
	  -B build/windows/debug

build/windows/release/rules.ninja: CMakeLists.txt
	@cmake -GNinja -DCMAKE_BUILD_TYPE=Release \
	  -DCMAKE_INSTALL_PREFIX="$(MAKEDIR)\build\install" \
	  -DCMAKE_TOOLCHAIN_FILE="$(VCPKG_ROOT)\triplets\toolchains\windows.cmake" \
	  -DCMAKE_VERBOSE_MAKEFILE=ON \
	  -B build/windows/release

build/linux/debug/rules.ninja: CMakeLists.txt
	@cmake -GNinja -DCMAKE_BUILD_TYPE=Debug \
	  -DCMAKE_INSTALL_PREFIX="$(CURDIR)/build/install" \
	  -DCMAKE_TOOLCHAIN_FILE="$(VCPKG_ROOT)/triplets/toolchains/linux.cmake" \
	  -DCMAKE_CXX_CLANG_TIDY="clang-tidy" \
	  -DCMAKE_VERBOSE_MAKEFILE=ON \
	  -B build/linux/debug

build/linux/release/rules.ninja: CMakeLists.txt
	@cmake -GNinja -DCMAKE_BUILD_TYPE=Release \
	  -DCMAKE_INSTALL_PREFIX="$(CURDIR)/build/install" \
	  -DCMAKE_TOOLCHAIN_FILE="$(VCPKG_ROOT)/triplets/toolchains/linux.cmake" \
	  -DCMAKE_CXX_CLANG_TIDY="clang-tidy" \
	  -DCMAKE_VERBOSE_MAKEFILE=ON \
	  -B build/linux/release
