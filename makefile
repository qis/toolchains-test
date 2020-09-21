system = linux
checks = ON

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
	@cmake -E echo ""
	@cmake -E echo "All configurations use correct libraries."
	@cmake -E echo ""

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

build/$(system)/multi/rules.ninja: CMakeLists.txt
	@cmake -E echo "Ninja Multi-Config:"
	@cmake -E make_directory build/$(system)/multi/check
	@cmake -E time cmake -G "Ninja Multi-Config" -DCMAKE_CONFIGURATION_TYPES="Debug;Release" \
	  -DCMAKE_TOOLCHAIN_FILE="$(VCPKG_ROOT)/triplets/toolchains/$(system).cmake" \
	  -DCMAKE_VERBOSE_MAKEFILE=$(checks) \
	  -B build/$(system)/multi
	@cmake -E echo ""

build/$(system)/debug/rules.ninja: CMakeLists.txt
	@cmake -E echo "Ninja Debug:"
	@cmake -E make_directory build/$(system)/debug/check
	@cmake -E time cmake -GNinja -DCMAKE_BUILD_TYPE=Debug \
	  -DCMAKE_TOOLCHAIN_FILE="$(VCPKG_ROOT)/triplets/toolchains/$(system).cmake" \
	  -DCMAKE_VERBOSE_MAKEFILE=$(checks) \
	  -B build/$(system)/debug
	@cmake -E echo ""

build/$(system)/release/rules.ninja: CMakeLists.txt
	@cmake -E echo "Ninja Release:"
	@cmake -E make_directory build/$(system)/release/check
	@cmake -E time cmake -GNinja -DCMAKE_BUILD_TYPE=Release \
	  -DCMAKE_TOOLCHAIN_FILE="$(VCPKG_ROOT)/triplets/toolchains/$(system).cmake" \
	  -DCMAKE_VERBOSE_MAKEFILE=$(checks) \
	  -B build/$(system)/release
	@cmake -E echo ""
