#include <bzlib.h>
#include <gtest/gtest.h>

TEST(bzip2, init) {
  bz_stream stream = {};
  ASSERT_EQ(BZ2_bzCompressInit(&stream, 9, 0, 30), BZ_OK);
}
