#include <date/date.h>
#include <date/tz.h>
#include <gtest/gtest.h>

TEST(date, date) {
  constexpr auto ymd = date::year{ 2019 } / date::month{ 1 } / 1;
  constexpr auto tp = std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds>{ date::sys_days{ ymd } };
  ASSERT_EQ(tp.time_since_epoch(), std::chrono::seconds{ 1546300800 });
}

TEST(date, tz) {
  const auto tp = std::chrono::system_clock::now();
  const auto ztp = date::make_zoned(date::current_zone(), tp);
}
