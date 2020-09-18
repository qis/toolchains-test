# System
system = linux

# Settings
VERBOSE = ON

all: clean build/$(system)/multi/rules.ninja build/$(system)/debug/rules.ninja build/$(system)/release/rules.ninja
	@cmake -E echo "Building Ninja Multi-Config Debug..."
	@cmake --build build/$(system)/multi --config Debug > build/$(system)/md.log
	@cmake -E echo "Building Ninja Multi-Config Release..."
	@cmake --build build/$(system)/multi --config Release > build/$(system)/mr.log
	@cmake -E echo "Building Ninja Debug..."
	@cmake --build build/$(system)/debug > build/$(system)/nd.log
	@cmake -E echo "Building Ninja Release..."
	@cmake --build build/$(system)/release > build/$(system)/nr.log

check:
	@cmake -DGENERATOR="Ninja Multi-Config" -DCONFIG="Debug" -DLOG=build/$(system)/md.log -P src/check.cmake
	@cmake -DGENERATOR="Ninja Multi-Config" -DCONFIG="Release" -DLOG=build/$(system)/mr.log -P src/check.cmake
	@cmake -DGENERATOR="Ninja" -DCONFIG="Debug" -DLOG=build/$(system)/nd.log -P src/check.cmake
	@cmake -DGENERATOR="Ninja" -DCONFIG="Release" -DLOG=build/$(system)/nr.log -P src/check.cmake
	@cmake -E echo "All configurations use correct libraries."

test:
	@cmake -E chdir build/$(system)/multi ctest --config Debug
	@cmake -E chdir build/$(system)/multi ctest --config Release
	@cmake -E chdir build/$(system)/debug ctest
	@cmake -E chdir build/$(system)/release ctest

benchmark:
	@cmake -E chdir build/$(system)/multi/src/benchmark/Release ./vcpkg-test-benchmark
	@cmake -E chdir build/$(system)/release/src/benchmark ./vcpkg-test-benchmark

format:
	@cmake -P "$(VCPKG_ROOT)/triplets/toolchains/format.cmake"

clean:
	@cmake -E remove_directory build/$(system)

build/windows/multi/rules.ninja: CMakeLists.txt
	@cmake -E echo "Ninja Multi-Config:"
	@cmake -E make_directory build/windows/multi/check
	@cmake -E time cmake -G "Ninja Multi-Config" -DCMAKE_BUILD_TYPE=Debug \
	  -DCMAKE_TOOLCHAIN_FILE="$(VCPKG_ROOT)\triplets\toolchains\windows.cmake" \
	  -DCMAKE_VERBOSE_MAKEFILE=$(VERBOSE) \
	  -B build/windows/multi
	@cmake -E echo ""

build/linux/multi/rules.ninja: CMakeLists.txt
	@cmake -E echo "Ninja Multi-Config:"
	@cmake -E make_directory build/linux/multi/check
	@cmake -E time cmake -G "Ninja Multi-Config" -DCMAKE_BUILD_TYPE=Debug \
	  -DCMAKE_TOOLCHAIN_FILE="$(VCPKG_ROOT)/triplets/toolchains/linux.cmake" \
	  -DCMAKE_VERBOSE_MAKEFILE=$(VERBOSE) \
	  -B build/linux/multi
	@cmake -E echo ""

build/windows/debug/rules.ninja: CMakeLists.txt
	@cmake -E echo "Ninja Debug:"
	@cmake -E make_directory build/windows/debug/check
	@cmake -E time cmake -GNinja -DCMAKE_BUILD_TYPE=Debug \
	  -DCMAKE_TOOLCHAIN_FILE="$(VCPKG_ROOT)\triplets\toolchains\windows.cmake" \
	  -DCMAKE_VERBOSE_MAKEFILE=$(VERBOSE) \
	  -B build/windows/debug
	@cmake -E echo ""

build/windows/release/rules.ninja: CMakeLists.txt
	@cmake -E echo "Ninja Release:"
	@cmake -E make_directory build/windows/release/check
	@cmake -E time cmake -GNinja -DCMAKE_BUILD_TYPE=Release \
	  -DCMAKE_TOOLCHAIN_FILE="$(VCPKG_ROOT)\triplets\toolchains\windows.cmake" \
	  -DCMAKE_VERBOSE_MAKEFILE=$(VERBOSE) \
	  -B build/windows/release
	@cmake -E echo ""

build/linux/debug/rules.ninja: CMakeLists.txt
	@cmake -E echo "Ninja Debug:"
	@cmake -E make_directory build/linux/debug/check
	@cmake -E time cmake -GNinja -DCMAKE_BUILD_TYPE=Debug \
	  -DCMAKE_TOOLCHAIN_FILE="$(VCPKG_ROOT)/triplets/toolchains/linux.cmake" \
	  -DCMAKE_VERBOSE_MAKEFILE=$(VERBOSE) \
	  -B build/linux/debug
	@cmake -E echo ""

build/linux/release/rules.ninja: CMakeLists.txt
	@cmake -E echo "Ninja Release:"
	@cmake -E make_directory build/linux/release/check
	@cmake -E time cmake -GNinja -DCMAKE_BUILD_TYPE=Release \
	  -DCMAKE_TOOLCHAIN_FILE="$(VCPKG_ROOT)/triplets/toolchains/linux.cmake" \
	  -DCMAKE_VERBOSE_MAKEFILE=$(VERBOSE) \
	  -B build/linux/release
	@cmake -E echo ""
