#pragma once

enum class Note
{
  Do,  //  1
  Di,  // #1
  Re,  //  2
  Ri,  // #2
  Mi,  //  3
  Fa,  //  4
  Fi,  // #4
  Sol, //  5
  Si,  // #5
  La,  //  6
  Li,  // #6
  Ti   //  7
};

enum class Interval
{
  P1, // perfect union
  m2, // minor second
  M2, // major second
  m3, // minor third
  M3, // major third
  P4, // perfect fourth
  A4, // augmented fourth
  P5, // perfect fifth
  m6, // minor sixth
  M6, // major sixth
  m7, // minor seventh
  M7, // major seventh
  P8  // perfect octave
};

enum class IntervalType
{
  Dissonant,
  Consonant,
  PerfectConsonant,
  ImperfectConsonant
};

int interval(int a, int b);

bool is_dissonant(int interval);
bool is_consonant(int interval);
bool is_interval_type(int interval, IntervalType interval_type);