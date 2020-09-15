#include <gtest/gtest.h>
#include <fmt/format.h>
#include <chrono>
#include <string>

template <typename Rep, typename Period>
struct fmt::formatter<std::chrono::duration<Rep, Period>> : fmt::formatter<std::string_view> {
  template <typename FormatContext>
  auto format(const std::chrono::duration<Rep, Period>& duration, FormatContext& context) {
    const auto h = std::chrono::floor<std::chrono::hours>(duration);
    if constexpr (std::ratio_less_equal_v<Period, std::chrono::minutes::period>) {
      const auto m = std::chrono::floor<std::chrono::minutes>(duration - h);
      if constexpr (std::ratio_less_equal_v<Period, std::chrono::seconds::period>) {
        const auto s = std::chrono::floor<std::chrono::seconds>(duration - h - m);
        if constexpr (std::ratio_less_equal_v<Period, std::chrono::nanoseconds::period>) {
          const auto ns = std::chrono::floor<std::chrono::nanoseconds>(duration - h - m - s);
          return format_to(context.out(), "{:02}:{:02}:{:02}.{:09}", h.count(), m.count(), s.count(), ns.count());
        } else if constexpr (std::ratio_less_equal_v<Period, std::chrono::microseconds::period>) {
          const auto us = std::chrono::floor<std::chrono::microseconds>(duration - h - m - s);
          return format_to(context.out(), "{:02}:{:02}:{:02}.{:06}", h.count(), m.count(), s.count(), us.count());
        } else if constexpr (std::ratio_less_equal_v<Period, std::chrono::milliseconds::period>) {
          const auto ms = std::chrono::floor<std::chrono::milliseconds>(duration - h - m - s);
          return format_to(context.out(), "{:02}:{:02}:{:02}.{:03}", h.count(), m.count(), s.count(), ms.count());
        } else {
          return format_to(context.out(), "{:02}:{:02}:{:02}", h.count(), m.count(), s.count());
        }
      } else {
        return format_to(context.out(), "{:02}:{:02}", h.count(), m.count());
      }
    } else {
      return format_to(context.out(), "{:02}:00", h.count());
    }
  }
};

TEST(fmt, chrono) {
  using namespace std::literals::chrono_literals;
  ASSERT_EQ(fmt::format("{}", 42s + 100ms), "00:00:42.100");
}

TEST(fmt, lib) {
  // Use a function from the compiled library.
  // fmt::v5::internal::char_traits<char>::format_float<double>(char*, unsigned __int64, const char*, int, double)
  ASSERT_EQ(fmt::format("{:.1f}", 0.123), "0.1");
}
