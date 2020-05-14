#include <catch.hpp>
#include <turbojpeg.h>

TEST_CASE("libjpeg-turbo::init") {
  tjhandle jpeg = tjInitCompress();
  REQUIRE(jpeg != nullptr);
  REQUIRE(tjDestroy(jpeg) == 0);
}
