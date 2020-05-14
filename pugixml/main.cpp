#include <catch.hpp>
#include <pugixml.hpp>

TEST_CASE("pugixml::parse") {
  pugi::xml_document doc;
  REQUIRE(doc.load_string("<data><node>test</node></data>"));
  REQUIRE(strcmp(doc.child("data").child("node").text().as_string(), "test") == 0);
}
