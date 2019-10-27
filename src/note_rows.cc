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