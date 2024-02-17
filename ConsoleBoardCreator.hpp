#include <string>
#include "Board.hpp"
using namespace std;
#pragma once


class ConsoleBoardCreator
{

private:
  string make_line();
  string first_row();
  string second_row();
  string third_row();

public:
    Board *board;

  ConsoleBoardCreator(Board *inputted_board);
  string formatted_board();
  string print_map();

};