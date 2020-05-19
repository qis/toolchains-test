#include <boost/filesystem.hpp>
#include <gtest/gtest.h>
#include <string>

TEST(boost, filesystem) {
  const auto path = boost::filesystem::current_path();
  ASSERT_FALSE(path.empty());
}
