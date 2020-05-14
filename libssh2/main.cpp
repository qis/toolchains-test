#include <catch.hpp>
#include <libssh2.h>

TEST_CASE("libssh2::init") {
  REQUIRE(libssh2_init(0) == 0);
  libssh2_exit();
}
