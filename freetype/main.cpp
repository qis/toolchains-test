#include <catch.hpp>
#include <filesystem>

#include <ft2build.h>
#include FT_FREETYPE_H

TEST_CASE("freetype::load") {
  const auto filename = "freetype/font.ttf";
  REQUIRE(std::filesystem::is_regular_file(filename));

  FT_Library ft_library = nullptr;
  REQUIRE(FT_Init_FreeType(&ft_library) == FT_Err_Ok);

  FT_Face ft_face = nullptr;
  REQUIRE(FT_New_Face(ft_library, filename, 0, &ft_face) == FT_Err_Ok);
  REQUIRE(FT_Set_Char_Size(ft_face, 16 * 64, 16 * 64, 0, 0) == FT_Err_Ok);

  REQUIRE(FT_Done_Face(ft_face) == FT_Err_Ok);
}
