#include <catch.hpp>
#include <zlib.h>
#include <string>

TEST_CASE("zlib::crc32") {
  const std::string src = "test";
  const auto data = reinterpret_cast<const Bytef*>(src.data());
  const auto size = static_cast<uInt>(src.size());
  const auto hash = crc32(0, data, size);
  REQUIRE(hash == 0xD87F7E0C);
}
