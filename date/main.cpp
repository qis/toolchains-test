#include <catch.hpp>
#include <date/date.h>
#include <date/tz.h>

TEST_CASE("date::date") {
  constexpr auto ymd = date::year{ 2019 } / date::month{ 1 } / 1;
  constexpr auto tp = std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds>{ date::sys_days{ ymd } };
  REQUIRE(tp.time_since_epoch() == std::chrono::seconds{ 1546300800 });
}

TEST_CASE("date::tz") {
  const auto tp = std::chrono::system_clock::now();
  const auto ztp = date::make_zoned(date::current_zone(), tp);
}
