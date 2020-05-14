#include <catch.hpp>
#include <harfbuzz/hb.h>
#include <filesystem>

TEST_CASE("harfbuzz::data") {
  const auto filename = "harfbuzz/font.ttf";
  REQUIRE(std::filesystem::is_regular_file(filename));

  const auto blob = hb_blob_create_from_file(filename);
  REQUIRE(blob != nullptr);

  unsigned int size = 0;
  const auto data = hb_blob_get_data(blob, &size);
  REQUIRE(data != nullptr);
  REQUIRE(size != 0U);
}
