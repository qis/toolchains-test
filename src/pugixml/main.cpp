#include <gtest/gtest.h>
#include <pugixml.hpp>

TEST(pugixml, parse)
{
  pugi::xml_document doc;
  ASSERT_TRUE(doc.load_string("<data><node>test</node></data>"));
  ASSERT_EQ(strcmp(doc.child("data").child("node").text().as_string(), "test"), 0);
}
