#include <cstdlib>  // include before <gif_lib.h> to fix `reallocarray` declaration

#include <gif_lib.h>
#include <gtest/gtest.h>

TEST(giflib, open) {
  int error = E_GIF_SUCCEEDED;
  OutputFunc write = [](GifFileType* gif, const GifByteType* data, int size) -> int {
    return size;
  };
  ASSERT_NE(EGifOpen(nullptr, write, &error), nullptr);
}
