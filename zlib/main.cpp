#include <gtest/gtest.h>
#include <zlib.h>
#include <string>

TEST(zlib, crc32) {
  const std::string src = "test";
  const auto data = reinterpret_cast<const Bytef*>(src.data());
  const auto size = static_cast<uInt>(src.size());
  const auto hash = crc32(0, data, size);
  ASSERT_EQ(hash, 0xD87F7E0C);
}
