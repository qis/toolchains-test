#include <cstdlib>  // include before <gif_lib.h> to fix `reallocarray` declaration

#include <catch.hpp>
#include <gif_lib.h>

TEST_CASE("giflib::open") {
  int error = E_GIF_SUCCEEDED;
  OutputFunc write = [](GifFileType* gif, const GifByteType* data, int size) -> int {
    return size;
  };
  REQUIRE(EGifOpen(nullptr, write, &error) != nullptr);
}
