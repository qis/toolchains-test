#include <bzlib.h>
#include <catch.hpp>

TEST_CASE("bzip2::init") {
  bz_stream stream = {};
  REQUIRE(BZ2_bzCompressInit(&stream, 9, 0, 30) == BZ_OK);
}
