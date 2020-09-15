#include <gtest/gtest.h>
#include <turbojpeg.h>

TEST(libjpeg_turbo, init) {
  tjhandle jpeg = tjInitCompress();
  ASSERT_TRUE(jpeg);
  ASSERT_EQ(tjDestroy(jpeg), 0);
}
