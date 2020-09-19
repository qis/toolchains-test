#include <gtest/gtest.h>
#include <brotli/decode.h>
#include <brotli/encode.h>

TEST(brotli, decoder)
{
  const auto dec = BrotliDecoderCreateInstance(nullptr, nullptr, nullptr);
  ASSERT_TRUE(dec);
  BrotliDecoderDestroyInstance(dec);
}

TEST(brotli, encoder)
{
  const auto enc = BrotliEncoderCreateInstance(nullptr, nullptr, nullptr);
  ASSERT_TRUE(enc);
  BrotliEncoderDestroyInstance(enc);
}
