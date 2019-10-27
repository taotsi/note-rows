#include "utility.hh"
#include "note_rows.hh"

using namespace taotsi;

int main(int argc, const char** argv)
{
  NoteRows nr{IntervalType::Dissonant};
  nr.print_all();
  return 0;
}

