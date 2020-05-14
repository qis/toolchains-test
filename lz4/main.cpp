#include <catch.hpp>
#include <lz4.h>
#include <string>

TEST_CASE("lz4::version") {
  REQUIRE(LZ4_versionNumber() > 0);
}
