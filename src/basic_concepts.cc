#include "basic_concepts.hh"
#include <vector>
#include <map>

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

bool is_interval_type(int interval, IntervalType interval_type)
{
  static std::map<IntervalType, std::vector<Interval>> interval_groups{
    {IntervalType::Dissonant,
     {Interval::m2, Interval::m3, Interval::A4, Interval::m6, Interval::M7}},
    {IntervalType::Consonant,
     {Interval::P1, Interval::P4, Interval::P5, Interval::P8}}
  };

  auto &intervals = interval_groups[interval_type];
  return std::find(intervals.begin(), intervals.end(), static_cast<Interval>(interval)) != intervals.end();
}
