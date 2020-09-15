#include <gtest/gtest.h>
#include <filesystem>

#include <ft2build.h>
#include FT_FREETYPE_H

TEST(freetype, load) {
  const auto filename = "font.ttf";
  ASSERT_TRUE(std::filesystem::is_regular_file(filename));

  FT_Library ft_library = nullptr;
  ASSERT_EQ(FT_Init_FreeType(&ft_library), FT_Err_Ok);

  FT_Face ft_face = nullptr;
  ASSERT_EQ(FT_New_Face(ft_library, filename, 0, &ft_face), FT_Err_Ok);
  ASSERT_EQ(FT_Set_Char_Size(ft_face, 16 * 64, 16 * 64, 0, 0), FT_Err_Ok);

  ASSERT_EQ(FT_Done_Face(ft_face), FT_Err_Ok);
}
