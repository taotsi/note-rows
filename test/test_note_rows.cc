#include "catch.hpp"
#include "note_rows.hh"

bool is_note_rows_interval_type(std::vector<int> &rows, IntervalType type)
{
  for (size_t i = 0; i < rows.size()-1; i++)
  {
    if(!is_interval_type(interval(rows[i], rows[i+1]), type))
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
  tval(all_rows.size());
  for(auto &rows : all_rows)
  {
    REQUIRE(is_note_rows_interval_type(rows, IntervalType::Dissonant));
  }
}

TEST_CASE("consonant note rows", "note rows")
{
  NoteRows nr{IntervalType::Consonant};
  auto all_rows = nr.all_rows();
  tval(all_rows.size());
  for(auto &rows : all_rows)
  {
    REQUIRE(is_note_rows_interval_type(rows, IntervalType::Consonant));
  }
}



