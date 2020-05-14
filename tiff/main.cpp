#include <catch.hpp>
#include <tiffio.h>
#include <filesystem>

#include <iostream>

TEST_CASE("tiff::open") {
  std::cout << std::filesystem::current_path() << std::endl;

  const auto filename = "tiff/test.tiff";
  REQUIRE(std::filesystem::is_regular_file(filename));

  const auto tiff = TIFFOpen(filename, "r");
  REQUIRE(tiff != nullptr);
  TIFFClose(tiff);
}
