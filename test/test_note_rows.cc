#include "catch.hpp"
#include "note_rows.hh"

TEST_CASE("interval")
{
  REQUIRE(interval(0, 11) == 1);
  REQUIRE(interval(11, 0) == 11);
}