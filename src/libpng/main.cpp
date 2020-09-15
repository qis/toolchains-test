#include <gtest/gtest.h>
#include <png.h>

TEST(libpng, init)
{
  const auto png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
  ASSERT_TRUE(png_ptr);
}
