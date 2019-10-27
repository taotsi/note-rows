#pragma once
#include "utility.hh"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace taotsi;

int interval(int a, int b);

class NoteRows
{
public:
  void gen()
  {
    auto remaining_notes = chromatic_notes();
    std::vector<int> rows;
    rows.push_back(*remaining_notes.begin());
    remaining_notes.erase(remaining_notes.begin());
    search(remaining_notes, rows);
  }
  void print_all()
  {
    for(const auto &rows : all_rows_)
    {
      for(auto note : rows)
      {
        std::cout << note << ", ";
      }
      std::cout << "\n";
    }
    std::cout << "there're " << all_rows_.size() << " rows:\n";
  }
private:
  std::vector<std::vector<int>> all_rows_;

  void search(std::vector<int> remaining_notes, std::vector<int> rows)
  {
    if(remaining_notes.size() == 0)
    {
      return;
    }
    if(remaining_notes.size() == 1)
    {
      if(is_dissonant(interval(rows.back(), remaining_notes.back())))
      {
        rows.push_back(remaining_notes.back());
        all_rows_.push_back(rows);
      }
      return;
    }
    for (size_t i = 0; i < remaining_notes.size(); i++)
    {
      if(is_dissonant(interval(rows.back(), *(remaining_notes.begin()+i))))
      {
        auto temp_remaining_notes = remaining_notes;
        auto temp_rows = rows;
        temp_rows.push_back(*(remaining_notes.begin() + i));
        temp_remaining_notes.erase(temp_remaining_notes.begin() + i);
        search(temp_remaining_notes, temp_rows);
      }
    }
  }
  bool is_dissonant(int interval)
  {
    static std::vector<int> dissonant_intervals{1, 3, 6, 8, 11};
    return std::find(dissonant_intervals.begin(), dissonant_intervals.end(), interval) != dissonant_intervals.end();
  }

  std::vector<int> chromatic_notes()
  {
    std::vector<int> result;
    for (int i = 0; i < 12; i++)
    {
      result.push_back(i);
    }
    return result;
  }
};