#include <gtest/gtest.h>
#include <zip.h>

TEST(libzip, source) {
  zip_error_t error = {};
  zip_error_init(&error);
  const auto source = zip_source_buffer_create(nullptr, 0, 1, &error);
  ASSERT_NE(source, nullptr);
}
