#include <gtest/gtest.h>
#include <lzma.h>
#include <string>

TEST(liblzma, crc64) {
  const std::string src = "test";
  const auto data = reinterpret_cast<const uint8_t*>(src.data());
  const auto size = src.size();
  const auto hash = lzma_crc64(data, size, 0);
  ASSERT_EQ(hash, 0xFA15FDA7C10C75A5);
}
