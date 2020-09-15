#include <cstdlib>  // include before <gif_lib.h> to fix `reallocarray` declaration

#include <gtest/gtest.h>
#include <gif_lib.h>

TEST(giflib, open) {
  int error = E_GIF_SUCCEEDED;
  OutputFunc write = [](GifFileType* gif, const GifByteType* data, int size) -> int {
    return size;
  };
  ASSERT_TRUE(EGifOpen(nullptr, write, &error));
}
