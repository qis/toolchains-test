#include <catch.hpp>
#include <jpeglib.h>

TEST_CASE("libjpeg::init") {
  struct jpeg_error_mgr jerr = {};
  REQUIRE(jpeg_std_error(&jerr) != nullptr);
}
