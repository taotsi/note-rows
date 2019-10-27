#include "catch.hpp"
#include "note_rows.hh"

TEST_CASE("interval")
{
  REQUIRE(interval(0, 11) == 1);
  REQUIRE(interval(11, 0) == 11);
}

bool is_note_rows_dissonant(std::vector<int> &rows)
{
  for (size_t i = 0; i < rows.size()-1; i++)
  {
    if(!is_dissonant(interval(rows[i], rows[i+1])))
    {
      return false;
    }
  }
  return true;
}

bool is_note_rows_consonant(std::vector<int> &rows)
{
  for (size_t i = 0; i < rows.size()-1; i++)
  {
    if(!is_consonant(interval(rows[i], rows[i+1])))
    {
      return false;
    }
  }
  return true;
}

TEST_CASE("dissonant note rows", "note rows")
{
  NoteRows nr{IntervalType::Dissonant};
  auto all_rows = nr.all_rows();
  for(auto &rows : all_rows)
  {
    REQUIRE(is_note_rows_dissonant(rows));
  }
}

TEST_CASE("consonant note rows", "note rows")
{
  NoteRows nr{IntervalType::Consonant};
  auto all_rows = nr.all_rows();
  for(auto &rows : all_rows)
  {
    REQUIRE(is_note_rows_consonant(rows));
  }
}