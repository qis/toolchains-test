#include <catch.hpp>
#include <zstd.h>
#include <string>

TEST_CASE("zstd::compress") {
  const std::string src = "test";
  std::string dst;
  dst.resize(ZSTD_compressBound(src.size()));
  const auto size = ZSTD_compress(dst.data(), dst.size(), src.data(), src.size(), 1);
  REQUIRE(size > 0);
}
