#include "catch.hpp"
#include "basic_concepts.hh"

TEST_CASE("basic notation", "note")
{
  REQUIRE(static_cast<int>(Note::Do) == 0);
  REQUIRE(static_cast<int>(Note::Sol) == 7);
  REQUIRE(static_cast<int>(Note::Ti) == 11);
}

TEST_CASE("interval")
{
  REQUIRE(interval(0, 11) == 1);
  REQUIRE(interval(11, 0) == 11);
}