#include <gtest/gtest.h>
#include <jpeglib.h>

TEST(libjpeg, init)
{
  struct jpeg_error_mgr jerr = {};
  ASSERT_TRUE(jpeg_std_error(&jerr));
}
