#include <gtest/gtest.h>
#include <lz4.h>
#include <string>

TEST(lz4, version)
{
  ASSERT_GT(LZ4_versionNumber(), 0);
}
