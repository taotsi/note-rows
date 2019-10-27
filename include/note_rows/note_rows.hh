#pragma once
#include "utility.hh"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace taotsi;

enum class IntervalType
{
  Dissonant,
  Consonant
};

int interval(int a, int b);

bool is_dissonant(int interval);
bool is_consonant(int interval);
bool is_interval_type(int interval, IntervalType interval_type);

class NoteRows
{
public:
  NoteRows(IntervalType interval_type)
  {
    gen(interval_type);
  }
  void gen(IntervalType interval_type)
  {
    auto remaining_notes = chromatic_notes();
    std::vector<int> rows;
    rows.push_back(*remaining_notes.begin());
    remaining_notes.erase(remaining_notes.begin());
    search(remaining_notes, rows, interval_type);
  }
  auto& all_rows()
  {
    return all_rows_;
  }
  void print_all()
  {
    // for(const auto &rows : all_rows_)
    // {
    //   for(auto note : rows)
    //   {
    //     std::cout << note << ", ";
    //   }
    //   std::cout << "\n";
    // }
    std::cout << "there're " << all_rows_.size() << " rows\n";
  }
private:
  std::vector<std::vector<int>> all_rows_;

  void search(std::vector<int> remaining_notes, std::vector<int> rows, IntervalType interval_type)
  {
    if(remaining_notes.size() == 1)
    {
      if(is_interval_type(interval(rows.back(), remaining_notes.back()), interval_type))
      {
        rows.push_back(remaining_notes.back());
        all_rows_.push_back(rows);
      }
      return;
    }
    for (size_t i = 0; i < remaining_notes.size(); i++)
    {
      if(is_interval_type(interval(rows.back(), *(remaining_notes.begin()+i)), interval_type))
      {
        auto temp_remaining_notes = remaining_notes;
        auto temp_rows = rows;
        temp_rows.push_back(*(remaining_notes.begin() + i));
        temp_remaining_notes.erase(temp_remaining_notes.begin() + i);
        search(temp_remaining_notes, temp_rows, interval_type);
      }
    }
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