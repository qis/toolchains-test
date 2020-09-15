#include <gtest/gtest.h>
#include <libssh2.h>

TEST(libssh2, init)
{
  ASSERT_EQ(libssh2_init(0), 0);
  libssh2_exit();
}
