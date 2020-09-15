#include <gtest/gtest.h>
#include <bzlib.h>

TEST(bzip2, init)
{
  bz_stream stream = {};
  ASSERT_EQ(BZ2_bzCompressInit(&stream, 9, 0, 30), BZ_OK);
}
