#include "note_rows.hh"

int interval(int a, int b)
{
  if((a-b)%12 < 0)
  {
    return (a-b)%12 + 12;
  }
  else
  {
    return (a-b)%12;
  }
}

bool is_dissonant(int interval)
{
  static std::vector<int> dissonant_intervals{1, 3, 6, 8, 11};
  return std::find(dissonant_intervals.begin(), dissonant_intervals.end(), interval) != dissonant_intervals.end();
}

bool is_consonant(int interval)
{
  static std::vector<int> dissonant_intervals{0, 3, 4, 5, 7, 9, 10, 12};
  return std::find(dissonant_intervals.begin(), dissonant_intervals.end(), interval) != dissonant_intervals.end();
}

bool is_interval_type(int interval, IntervalType interval_type)
{
  if(interval_type == IntervalType::Dissonant)
  {
    return is_dissonant(interval);
  }
  else
  {
    return is_consonant(interval);
  }
}
