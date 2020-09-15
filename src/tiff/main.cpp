#include <gtest/gtest.h>
#include <tiffio.h>
#include <filesystem>

#include <iostream>

TEST(tiff, open) {
  std::cout << std::filesystem::current_path() << std::endl;

  const auto filename = "test.tiff";
  ASSERT_TRUE(std::filesystem::is_regular_file(filename));

  const auto tiff = TIFFOpen(filename, "r");
  ASSERT_TRUE(tiff);
  TIFFClose(tiff);
}
