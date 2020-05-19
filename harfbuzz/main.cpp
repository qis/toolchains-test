#include <gtest/gtest.h>
#include <harfbuzz/hb.h>
#include <filesystem>

TEST(harfbuzz, data) {
  const auto filename = "harfbuzz/font.ttf";
  ASSERT_TRUE(std::filesystem::is_regular_file(filename));

  const auto blob = hb_blob_create_from_file(filename);
  ASSERT_NE(blob, nullptr);

  unsigned int size = 0;
  const auto data = hb_blob_get_data(blob, &size);
  ASSERT_NE(data, nullptr);
  ASSERT_NE(size, 0U);
}
