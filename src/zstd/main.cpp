#include <gtest/gtest.h>
#include <zstd.h>
#include <string>

TEST(zstd, compress)
{
  const std::string src = "test";
  std::string dst;
  dst.resize(ZSTD_compressBound(src.size()));
  const auto size = ZSTD_compress(dst.data(), dst.size(), src.data(), src.size(), 1);
  ASSERT_GT(size, 0);
}
