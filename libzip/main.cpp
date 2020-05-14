#include <catch.hpp>
#include <zip.h>

TEST_CASE("libzip::source") {
  zip_error_t error = {};
  zip_error_init(&error);
  const auto source = zip_source_buffer_create(nullptr, 0, 1, &error);
  REQUIRE(source != nullptr);
}
