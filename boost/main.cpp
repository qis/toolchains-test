#include <boost/filesystem.hpp>
#include <catch.hpp>
#include <string>

TEST_CASE("boost::filesystem") {
  const auto path = boost::filesystem::current_path();
  REQUIRE(!path.empty());
}
