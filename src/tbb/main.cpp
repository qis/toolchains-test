#include <gtest/gtest.h>
#include <tbb/parallel_for.h>
#include <vector>

TEST(tbb, parallel_for)
{
  std::vector<int> v(1'000, 1);
  tbb::parallel_for(tbb::blocked_range<std::size_t>(0, v.size()), [&](const auto& range) {
    for (auto i = range.begin(); i != range.end(); ++i) {
      ASSERT_EQ(v[i], 1);
    }
  });
}
