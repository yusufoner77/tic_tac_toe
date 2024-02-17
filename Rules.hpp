#include <string>
#include "Board.hpp"
using namespace std;
#pragma once

class Rules
{
  Board *board;
public:
  Rules(Board *inputted_board);
  bool validate_input(int input);
  bool in_progress();
  bool is_board_full();
  string three_in_a_row_in_the_top_row();
  string three_in_a_row_in_the_middle_row();
  string three_in_a_row_in_the_bottom_row();
  string three_in_a_row_in_the_left_column();
  string three_in_a_row_in_the_middle_column();
  string three_in_a_row_in_the_right_column();
  string three_in_a_row_in_the_left_diagonal();
  string three_in_a_row_in_the_right_diagonal();
};