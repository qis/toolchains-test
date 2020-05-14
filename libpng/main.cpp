#include <catch.hpp>
#include <png.h>

TEST_CASE("libpng::init") {
  const auto png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
  REQUIRE(png_ptr != nullptr);
}
