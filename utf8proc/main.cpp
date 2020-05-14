#include <catch.hpp>
#include <utf8proc.h>
#include <random>
#include <string>

const std::u8string src = []() {
  std::random_device rd;
  std::uniform_int_distribution<int> dist('0', '9');
  std::u8string src = u8"unicode_test _ ぁあぃいぅうぇえぉおかがきぎ";
  src[13] = static_cast<std::u8string::value_type>(dist(rd));
  return src;
}();

const std::u32string dst = []() {
  std::u32string dst = U"unicode_test _ ぁあぃいぅうぇえぉおかがきぎ";
  dst[13] = static_cast<std::u32string::value_type>(src[13]);
  return dst;
}();

TEST_CASE("utf8proc::convert") {
  const auto data = reinterpret_cast<const utf8proc_uint8_t*>(src.data());
  const auto size = static_cast<utf8proc_ssize_t>(src.size());
  utf8proc_int32_t cp = 0;
  std::u32string str;
  for (auto it = data; it < data + size;) {
    const auto result = utf8proc_iterate(it, data + size - it, &cp);
    REQUIRE(result > 0);
    str.push_back(static_cast<char32_t>(cp));
    it += result;
  }
  REQUIRE(str.size() == 29);
  REQUIRE(str == dst);
}
